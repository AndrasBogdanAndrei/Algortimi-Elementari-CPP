/*
 * Titlu: Rotirea unei matrice cu 90 de grade
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: La rotirea în sensul acelor de ceasornic, prima coloană citită de jos
 *            în sus devine prima linie. Matricea rezultat b are m linii și n coloane,
 *            iar elementul a[i][j] ajunge în b[j][n + 1 - i]. Folosim o a doua
 *            matrice, ca să nu suprascriem valori pe care încă nu le-am mutat.
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare:
 * 2 3
 * 1 2 3
 * 4 5 6
 * Ieșire:
 * 4 1
 * 5 2
 * 6 3
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * Ieșire:
 * 7 4 1
 * 8 5 2
 * 9 6 3
 */
#include <iostream>
using namespace std;

int a[101][101], b[101][101];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[j][n + 1 - i] = a[i][j];

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << b[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
