/*
 * Titlu: Lee cu mai multe surse
 * Clasa: 12
 * Capitol: Algoritmi pe grile: Lee și fill
 * Descriere: Grila conține 0 (liber), 1 (zid) și 2 (sursă, de exemplu o fântână).
 *            Pentru fiecare celulă liberă vrem numărul minim de pași până la cea
 *            mai apropiată sursă. În loc să pornim Lee din fiecare sursă (prea
 *            lent), punem toate sursele în coadă de la început, cu distanța 0, și
 *            facem o singură parcurgere în lățime. Undele pornite din surse se
 *            extind simultan, iar fiecare celulă este atinsă întâi de sursa cea mai
 *            apropiată. Zidurile și celulele la care nu se poate ajunge primesc -1.
 * Complexitate: O(n * m), indiferent de numărul de surse
 *
 * Exemplu
 * Intrare:
 * 3 4
 * 2 0 0 1
 * 0 1 0 0
 * 0 0 0 2
 * Ieșire:
 * 0 1 2 -1
 * 1 -1 2 1
 * 2 2 1 0
 *
 * Exemplu
 * Intrare:
 * 2 3
 * 2 1 0
 * 0 1 0
 * Ieșire:
 * 0 -1 -1
 * 1 -1 -1
 */
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int DIM = 1002;
int a[DIM][DIM], d[DIM][DIM];
int dl[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
        {
            a[i][j] = 1; // bordura se comportă ca un zid
            d[i][j] = -1;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
            {
                d[i][j] = 0;
                q.push({i, j});
            }
        }
    while (!q.empty())
    {
        int l = q.front().first, c = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int lv = l + dl[k], cv = c + dc[k];
            if (a[lv][cv] != 1 && d[lv][cv] == -1)
            {
                d[lv][cv] = d[l][c] + 1;
                q.push({lv, cv});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << d[i][j] << (j < m ? ' ' : '\n');
    }
    return 0;
}
