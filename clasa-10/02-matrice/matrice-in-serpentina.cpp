/*
 * Titlu: Generarea matricei în serpentină
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Completăm matricea cu numerele 1, 2, ..., n * m „în zigzag”: liniile
 *            impare de la stânga la dreapta, liniile pare de la dreapta la stânga.
 *            Un contor val crește la fiecare element scris; doar sensul în care
 *            mergem pe coloane depinde de paritatea liniei.
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare: 3 4
 * Ieșire:
 * 1 2 3 4
 * 8 7 6 5
 * 9 10 11 12
 *
 * Exemplu
 * Intrare: 2 2
 * Ieșire:
 * 1 2
 * 4 3
 */
#include <iostream>
using namespace std;

int a[101][101];

int main()
{
    int n, m, val = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 1; j <= m; j++)
                a[i][j] = val++;
        }
        else
        {
            for (int j = m; j >= 1; j--)
                a[i][j] = val++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
