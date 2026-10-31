/*
 * Titlu: Diagonala principală și diagonala secundară
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Într-o matrice pătratică n x n, indexată de la 1, elementele de pe
 *            diagonala principală au i == j, iar cele de pe diagonala secundară au
 *            i + j == n + 1. Nu avem nevoie de două for-uri: elementul de pe linia i
 *            este a[i][i] pe principală și a[i][n + 1 - i] pe secundară.
 *            Se afișează elementele fiecărei diagonale și suma lor.
 * Complexitate: O(n) pentru parcurgere (citirea este O(n * n))
 *
 * Exemplu
 * Intrare:
 * 3
 * 1 2 3
 * 4 5 6
 * 7 8 10
 * Ieșire:
 * 1 5 10
 * 16
 * 3 5 7
 * 15
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

    int sp = 0, ss = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i][i] << ' ';
        sp += a[i][i];
    }
    cout << '\n' << sp << '\n';

    for (int i = 1; i <= n; i++)
    {
        cout << a[i][n + 1 - i] << ' ';
        ss += a[i][n + 1 - i];
    }
    cout << '\n' << ss << '\n';
    return 0;
}
