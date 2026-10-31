/*
 * Titlu: Numărul de drumuri într-o grilă cu obstacole
 * Clasa: 11
 * Capitol: Programare dinamică
 * Descriere: O grilă n × m are celule libere (0) și obstacole (1). Câte drumuri duc din
 *            (1, 1) în (n, m) dacă ne mișcăm doar la dreapta sau în jos și nu intrăm în
 *            obstacole? Într-o celulă liberă se ajunge de sus sau din stânga, deci
 *            nr[i][j] = nr[i-1][j] + nr[i][j-1], iar într-un obstacol nr[i][j] = 0.
 *            Pornim cu nr[1][1] = 1 (dacă celula e liberă). Spre deosebire de
 *            backtracking, nu enumerăm drumurile, ci doar le numărăm.
 * Complexitate: O(n · m) timp și memorie
 *
 * Exemplu
 * Intrare:
 * 3 4
 * 0 0 0 0
 * 0 1 0 0
 * 0 0 0 0
 * Ieșire: 4
 *
 * Exemplu
 * Intrare:
 * 2 2
 * 0 1
 * 1 0
 * Ieșire: 0
 */
#include <iostream>
using namespace std;

int a[105][105];
long long nr[105][105];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 1)
            {
                nr[i][j] = 0;
            }
            else if (i == 1 && j == 1)
            {
                nr[i][j] = 1;
            }
            else
            {
                nr[i][j] = nr[i - 1][j] + nr[i][j - 1];
            }
        }
    }
    cout << nr[n][m] << '\n';
    return 0;
}
