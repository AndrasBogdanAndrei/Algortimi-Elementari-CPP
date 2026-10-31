/*
 * Titlu: Lee cu reconstituirea drumului
 * Clasa: 12
 * Capitol: Algoritmi pe grile: Lee și fill
 * Descriere: După ce Lee a completat matricea de distanțe, drumul se reface de la
 *            final spre start: dacă suntem într-o celulă cu valoarea k, unul
 *            dintre vecini are sigur valoarea k - 1 (cel din care am ajuns aici).
 *            Mergem în el și repetăm până la valoarea 1. Vecinii sunt încercați
 *            mereu în ordinea sus, dreapta, jos, stânga, deci drumul afișat este
 *            unic. Celulele sunt adunate de la final spre start, așa că le afișăm
 *            în ordine inversă. Prima linie conține lungimea (numărul de celule).
 * Complexitate: O(n * m) pentru Lee, O(lungimea drumului) pentru reconstituire
 *
 * Exemplu
 * Intrare:
 * 5 5
 * 0 0 0 1 0
 * 1 1 0 1 0
 * 0 0 0 0 0
 * 0 1 1 1 0
 * 0 0 0 1 0
 * 1 1 5 5
 * Ieșire:
 * 9
 * 1 1
 * 1 2
 * 1 3
 * 2 3
 * 3 3
 * 3 4
 * 3 5
 * 4 5
 * 5 5
 *
 * Exemplu
 * Intrare:
 * 2 2
 * 0 1
 * 1 0
 * 1 1 2 2
 * Ieșire: -1
 */
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int DIM = 1002;
int d[DIM][DIM];
int dl[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            d[i][j] = -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            d[i][j] = (x == 1 ? -1 : 0);
        }
    int xs, ys, xf, yf;
    cin >> xs >> ys >> xf >> yf;

    queue<pair<int, int>> q;
    d[xs][ys] = 1;
    q.push({xs, ys});
    while (!q.empty())
    {
        int l = q.front().first, c = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int lv = l + dl[k], cv = c + dc[k];
            if (d[lv][cv] == 0)
            {
                d[lv][cv] = d[l][c] + 1;
                q.push({lv, cv});
            }
        }
    }
    if (d[xf][yf] <= 0)
    {
        cout << -1 << '\n';
        return 0;
    }

    vector<pair<int, int>> drum;
    int l = xf, c = yf;
    drum.push_back({l, c});
    while (d[l][c] > 1)
    {
        for (int k = 0; k < 4; k++)
        {
            int lv = l + dl[k], cv = c + dc[k];
            if (d[lv][cv] == d[l][c] - 1)
            {
                l = lv;
                c = cv;
                break;
            }
        }
        drum.push_back({l, c});
    }
    cout << drum.size() << '\n';
    for (int i = (int)drum.size() - 1; i >= 0; i--)
        cout << drum[i].first << ' ' << drum[i].second << '\n';
    return 0;
}
