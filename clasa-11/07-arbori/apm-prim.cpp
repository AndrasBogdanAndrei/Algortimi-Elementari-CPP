/*
 * Titlu: Arborele parțial de cost minim (algoritmul lui Prim)
 * Clasa: 11
 * Capitol: Arbori
 * Descriere: Într-un graf neorientat conex cu costuri pe muchii căutăm un arbore parțial
 *            (n - 1 muchii care leagă toate nodurile) cu suma costurilor minimă. Prim crește
 *            arborele dintr-un singur nod (nodul 1). Pentru fiecare nod din afara arborelui
 *            ținem cheie[y] = costul celei mai ieftine muchii spre arbore și tata[y] = capătul
 *            ei din arbore. La fiecare pas adăugăm nodul cu cheia minimă (la egalitate, pe cel
 *            cu numărul mai mic), apoi actualizăm cheile vecinilor lui. Se afișează costul
 *            total și muchiile, în ordinea adăugării.
 * Complexitate: O(n²)
 *
 * Exemplu
 * Intrare:
 * 5 7
 * 1 2 2
 * 1 4 6
 * 2 3 3
 * 2 4 8
 * 2 5 5
 * 3 5 7
 * 4 5 9
 * Ieșire:
 * Cost: 16
 * 1 2 2
 * 2 3 3
 * 2 5 5
 * 1 4 6
 */
#include <iostream>
using namespace std;

const int INF = 1000000000;
int c[105][105], cheie[105], tata[105];
bool inArbore[105];

int main()
{
    int n, m;
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
            c[x][y] = c[y][x] = cost;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cheie[i] = INF;
    }
    cheie[1] = 0;
    int total = 0;
    int mx[105], my[105], mc[105], nrMuchii = 0;
    for (int pas = 1; pas <= n; pas++)
    {
        int x = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!inArbore[i] && cheie[i] < INF && (x == 0 || cheie[i] < cheie[x]))
            {
                x = i;
            }
        }
        if (x == 0)
        {
            cout << "Graful nu este conex\n";
            return 0;
        }
        inArbore[x] = true;
        if (x != 1)
        {
            total += cheie[x];
            mx[nrMuchii] = tata[x];
            my[nrMuchii] = x;
            mc[nrMuchii] = cheie[x];
            nrMuchii++;
        }
        for (int y = 1; y <= n; y++)
        {
            if (!inArbore[y] && c[x][y] < cheie[y])
            {
                cheie[y] = c[x][y];
                tata[y] = x;
            }
        }
    }

    cout << "Cost: " << total << '\n';
    for (int i = 0; i < nrMuchii; i++)
    {
        cout << mx[i] << ' ' << my[i] << ' ' << mc[i] << '\n';
    }
    return 0;
}
