/*
 * Titlu: Cele patru zone ale matricei pătratice
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Cele două diagonale împart o matrice pătratică în patru zone (fără
 *            elementele de pe diagonale). Cu indici de la 1:
 *            Nord: i < j și i + j < n + 1 (deasupra ambelor diagonale);
 *            Sud: i > j și i + j > n + 1 (sub ambele diagonale);
 *            Est: i < j și i + j > n + 1 (deasupra principalei, sub secundară);
 *            Vest: i > j și i + j < n + 1 (sub principală, deasupra secundarei).
 *            Se afișează suma elementelor din fiecare zonă.
 * Complexitate: O(n * n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 2 3 4 5
 * 6 7 8 9 10
 * 11 12 13 14 15
 * 16 17 18 19 20
 * 21 22 23 24 25
 * Ieșire:
 * N 17
 * S 87
 * E 59
 * V 45
 */
#include <iostream>
using namespace std;

int a[101][101];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    int nord = 0, sud = 0, est = 0, vest = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i < j && i + j < n + 1)
                nord += a[i][j];
            else if (i > j && i + j > n + 1)
                sud += a[i][j];
            else if (i < j && i + j > n + 1)
                est += a[i][j];
            else if (i > j && i + j < n + 1)
                vest += a[i][j];
        }
    }
    cout << "N " << nord << '\n';
    cout << "S " << sud << '\n';
    cout << "E " << est << '\n';
    cout << "V " << vest << '\n';
    return 0;
}
