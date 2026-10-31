/*
 * Titlu: Drumuri minime de la un nod (algoritmul lui Dijkstra)
 * Clasa: 11
 * Capitol: Grafuri orientate și drumuri minime
 * Descriere: Se cere costul minim al drumului de la nodul s la fiecare alt nod, când toate
 *            costurile arcelor sunt nenegative. d[s] = 0, restul „infinit”. La fiecare pas
 *            alegem nodul neselectat x cu d[x] minim (la egalitate, pe cel cu numărul mai
 *            mic): costul lui nu se mai poate îmbunătăți, deci îl selectăm definitiv. Apoi
 *            relaxăm arcele care pleacă din x: dacă d[x] + c(x, y) < d[y], actualizăm d[y]
 *            și reținem tata[y] = x. Drumul spre un nod se reface prin tați. Datele: n m,
 *            cele m arce „x y cost”, apoi s.
 * Complexitate: O(n²) în această variantă (cu matrice și căutarea minimului)
 *
 * Exemplu
 * Intrare:
 * 5 7
 * 1 2 4
 * 1 3 1
 * 3 2 2
 * 2 4 1
 * 3 4 5
 * 4 5 3
 * 3 5 8
 * 1
 * Ieșire:
 * 1: cost 0, drum 1
 * 2: cost 3, drum 1 3 2
 * 3: cost 1, drum 1 3
 * 4: cost 4, drum 1 3 2 4
 * 5: cost 7, drum 1 3 2 4 5
 */
#include <iostream>
using namespace std;

const int INF = 1000000000;
int n, m, s, c[105][105], d[105], tata[105];
bool selectat[105];

void afiseazaDrum(int x)
{
    if (x != s)
    {
        afiseazaDrum(tata[x]);
    }
    cout << ' ' << x;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            c[i][j] = INF;
        }
    }
    for (int k = 1; k <= m; k++)
    {
        int x, y, cost;
        cin >> x >> y >> cost;
        if (cost < c[x][y])
        {
            c[x][y] = cost;
        }
    }
    cin >> s;

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
    }
    d[s] = 0;
    for (int pas = 1; pas <= n; pas++)
    {
        int x = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!selectat[i] && d[i] < INF && (x == 0 || d[i] < d[x]))
            {
                x = i;
            }
        }
        if (x == 0)
        {
            break;
        }
        selectat[x] = true;
        for (int y = 1; y <= n; y++)
        {
            if (c[x][y] < INF && d[x] + c[x][y] < d[y])
            {
                d[y] = d[x] + c[x][y];
                tata[y] = x;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        if (d[i] == INF)
        {
            cout << "inaccesibil\n";
        }
        else
        {
            cout << "cost " << d[i] << ", drum";
            afiseazaDrum(i);
            cout << '\n';
        }
    }
    return 0;
}
