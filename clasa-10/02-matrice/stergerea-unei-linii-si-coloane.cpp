/*
 * Titlu: Ștergerea unei linii și a unei coloane
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Ca la vectori, ștergerea înseamnă mutarea elementelor peste cel șters.
 *            Pentru linia k, fiecare linie i de la k la n - 1 primește linia i + 1,
 *            apoi n scade cu 1. Pentru coloana c, pe fiecare linie, elementele de
 *            la c la m - 1 primesc valoarea vecinului din dreapta, apoi m scade.
 *            Se citesc matricea, apoi k și c (numerotate de la 1).
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * 2 3
 * Ieșire:
 * 1 2
 * 7 8
 *
 * Exemplu
 * Intrare:
 * 2 4
 * 1 2 3 4
 * 5 6 7 8
 * 1 1
 * Ieșire: 6 7 8
 */
#include <iostream>
using namespace std;

int a[101][101];

int main()
{
    int n, m, k, c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    cin >> k >> c;

    // ștergem linia k
    for (int i = k; i < n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = a[i + 1][j];
    n--;

    // ștergem coloana c
    for (int i = 1; i <= n; i++)
        for (int j = c; j < m; j++)
            a[i][j] = a[i][j + 1];
    m--;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
