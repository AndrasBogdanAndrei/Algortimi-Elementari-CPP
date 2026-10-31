/*
 * Titlu: Produsul a două matrice
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Produsul se poate face doar dacă numărul de coloane al lui A este egal
 *            cu numărul de linii al lui B. Pentru A (n x m) și B (m x p) rezultatul
 *            C are n x p elemente, iar C[i][j] este suma produselor A[i][k] * B[k][j]
 *            pentru k de la 1 la m: linia i din A „înmulțită” cu coloana j din B.
 *            Se citesc n, m, p, apoi A și B.
 * Complexitate: O(n * m * p)
 *
 * Exemplu
 * Intrare:
 * 2 2 2
 * 1 2
 * 3 4
 * 5 6
 * 7 8
 * Ieșire:
 * 19 22
 * 43 50
 *
 * Exemplu
 * Intrare:
 * 1 3 1
 * 1 2 3
 * 4
 * 5
 * 6
 * Ieșire: 32
 */
#include <iostream>
using namespace std;

long long A[51][51], B[51][51], C[51][51];

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
        for (int k = 1; k <= m; k++)
            cin >> A[i][k];
    for (int k = 1; k <= m; k++)
        for (int j = 1; j <= p; j++)
            cin >> B[k][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= p; j++)
        {
            C[i][j] = 0;
            for (int k = 1; k <= m; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
            cout << C[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
