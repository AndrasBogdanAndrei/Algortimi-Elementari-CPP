/*
 * Titlu: Parcurgerea în lățime (BFS)
 * Clasa: 11
 * Capitol: Grafuri neorientate
 * Descriere: Parcurgerea în lățime vizitează nodurile „pe straturi”: întâi nodul de start,
 *            apoi toți vecinii lui, apoi vecinii vecinilor etc. Folosim o coadă: scoatem
 *            nodul din față și adăugăm la sfârșit vecinii lui încă nevizitați (marcându-i
 *            vizitați chiar când intră în coadă). Vecinii se iau în ordine crescătoare,
 *            ca ordinea să fie unică. Datele: n m, cele m muchii, apoi nodul de start.
 * Complexitate: O(n²) cu matricea de adiacență (O(n + m) cu liste de adiacență)
 *
 * Exemplu
 * Intrare:
 * 7 8
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * 3 5
 * 4 6
 * 5 6
 * 6 7
 * 5
 * Ieșire: 5 2 3 6 1 4 7
 */
#include <iostream>
using namespace std;

int a[105][105], coada[105];
bool vizitat[105];

int main()
{
    int n, m, start;
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    cin >> start;

    int inc = 1, sf = 1;
    coada[1] = start;
    vizitat[start] = true;
    while (inc <= sf)
    {
        int x = coada[inc++];
        cout << x << ' ';
        for (int y = 1; y <= n; y++)
        {
            if (a[x][y] == 1 && !vizitat[y])
            {
                vizitat[y] = true;
                coada[++sf] = y;
            }
        }
    }
    cout << '\n';
    return 0;
}
