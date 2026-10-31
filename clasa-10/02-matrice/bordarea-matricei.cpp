/*
 * Titlu: Bordarea matricei
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: A borda o matrice înseamnă a-i adăuga o linie și/sau o coloană nouă
 *            pe margine. Aici adăugăm coloana m + 1, cu suma fiecărei linii, și
 *            linia n + 1, cu suma fiecărei coloane; în colțul a[n + 1][m + 1] ajunge
 *            suma tuturor elementelor. Matricea trebuie declarată cu loc pentru
 *            linia și coloana în plus.
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare:
 * 2 3
 * 1 2 3
 * 4 5 6
 * Ieșire:
 * 1 2 3 6
 * 4 5 6 15
 * 5 7 9 21
 */
#include <iostream>
using namespace std;

int a[102][102];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][m + 1] += a[i][j];      // suma liniei i
            a[n + 1][j] += a[i][j];      // suma coloanei j
            a[n + 1][m + 1] += a[i][j];  // suma totală
        }
    }

    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= m + 1; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
