/*
 * Titlu: Matricea drumurilor (algoritmul Roy-Warshall)
 * Clasa: 11
 * Capitol: Grafuri orientate și drumuri minime
 * Descriere: Matricea drumurilor are d[i][j] = 1 dacă există un drum (de lungime cel puțin 1)
 *            de la i la j și 0 altfel. Pornim de la matricea de adiacență. Pentru fiecare
 *            nod intermediar k, dacă există drum de la i la k și drum de la k la j, atunci
 *            există și drum de la i la j. Bucla după k trebuie să fie cea exterioară.
 *            Pe diagonală apare 1 doar pentru nodurile aflate pe un circuit.
 * Complexitate: O(n³)
 *
 * Exemplu
 * Intrare:
 * 5 5
 * 1 2
 * 2 3
 * 3 1
 * 3 4
 * 5 4
 * Ieșire:
 * 1 1 1 1 0
 * 1 1 1 1 0
 * 1 1 1 1 0
 * 0 0 0 0 0
 * 0 0 0 1 0
 */
#include <iostream>
using namespace std;

int d[105][105];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        d[x][y] = 1;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] == 1 && d[k][j] == 1)
                {
                    d[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
