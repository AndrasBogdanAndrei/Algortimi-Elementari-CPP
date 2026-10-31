/*
 * Titlu: Detectarea unui ciclu
 * Clasa: 11
 * Capitol: Grafuri neorientate
 * Descriere: Un ciclu este un lanț simplu în care primul nod coincide cu ultimul. Facem o
 *            parcurgere DFS și reținem pentru fiecare nod tatăl lui (nodul din care am venit).
 *            Dacă din nodul x găsim un vecin y deja vizitat care nu este tatăl lui x, muchia
 *            [x, y] închide un ciclu: el este format din y, coborând prin arborele DFS până
 *            la x, și înapoi în y. Ciclul se reface urcând din x prin tați până la y.
 *            Se afișează DA și un ciclu, sau NU. (Echivalent: un graf cu n noduri, m muchii
 *            și p componente conexe are cicluri exact când m > n - p.)
 * Complexitate: O(n²) cu matricea de adiacență
 *
 * Exemplu
 * Intrare:
 * 6 6
 * 1 2
 * 2 3
 * 3 4
 * 4 5
 * 5 2
 * 5 6
 * Ieșire:
 * DA
 * 2 3 4 5 2
 *
 * Exemplu
 * Intrare:
 * 4 3
 * 1 2
 * 2 3
 * 2 4
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int n, m, a[105][105], tata[105];
bool vizitat[105], gasit = false;
int capatSus, capatJos;

void dfs(int x)
{
    vizitat[x] = true;
    for (int y = 1; y <= n && !gasit; y++)
    {
        if (a[x][y] == 1)
        {
            if (!vizitat[y])
            {
                tata[y] = x;
                dfs(y);
            }
            else if (y != tata[x])
            {
                gasit = true;
                capatSus = y;
                capatJos = x;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for (int i = 1; i <= n && !gasit; i++)
    {
        if (!vizitat[i])
        {
            tata[i] = 0;
            dfs(i);
        }
    }

    if (!gasit)
    {
        cout << "NU\n";
        return 0;
    }
    int ciclu[105], k = 0;
    for (int v = capatJos; v != capatSus; v = tata[v])
    {
        ciclu[k++] = v;
    }
    ciclu[k++] = capatSus;
    cout << "DA\n";
    for (int i = k - 1; i >= 0; i--)
    {
        cout << ciclu[i] << ' ';
    }
    cout << capatSus << '\n';
    return 0;
}
