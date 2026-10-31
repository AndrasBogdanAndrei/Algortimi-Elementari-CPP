/*
 * Titlu: Lanțul de lungime minimă între două noduri (BFS)
 * Clasa: 11
 * Capitol: Grafuri neorientate
 * Descriere: Lungimea unui lanț este numărul de muchii. Parcurgerea în lățime pornită din x
 *            descoperă nodurile în ordinea distanței față de x, deci prima dată când ajunge
 *            într-un nod o face pe un lanț de lungime minimă. Reținem dist[y] (distanța) și
 *            tata[y] (nodul din care a fost descoperit y). Lanțul se reface mergând din y
 *            prin tați până la x, apoi se afișează invers. Datele: n m, cele m muchii, apoi
 *            nodurile x și y.
 * Complexitate: O(n²) cu matricea de adiacență
 *
 * Exemplu
 * Intrare:
 * 6 7
 * 1 2
 * 1 3
 * 2 4
 * 3 4
 * 4 5
 * 3 6
 * 6 5
 * 1 5
 * Ieșire:
 * 3
 * 1 2 4 5
 *
 * Exemplu
 * Intrare:
 * 4 2
 * 1 2
 * 3 4
 * 1 4
 * Ieșire: Nu exista lant
 */
#include <iostream>
using namespace std;

int n, m, a[105][105], dist[105], tata[105], coada[105];

int main()
{
    int x, y;
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    cin >> x >> y;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = -1;
    }
    int inc = 1, sf = 1;
    coada[1] = x;
    dist[x] = 0;
    while (inc <= sf)
    {
        int u = coada[inc++];
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] == 1 && dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                tata[v] = u;
                coada[++sf] = v;
            }
        }
    }

    if (dist[y] == -1)
    {
        cout << "Nu exista lant\n";
        return 0;
    }
    cout << dist[y] << '\n';
    int lant[105], k = 0;
    for (int v = y; v != x; v = tata[v])
    {
        lant[k++] = v;
    }
    lant[k++] = x;
    for (int i = k - 1; i >= 0; i--)
    {
        cout << lant[i] << ' ';
    }
    cout << '\n';
    return 0;
}
