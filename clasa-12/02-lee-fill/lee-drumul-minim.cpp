/*
 * Titlu: Lee — drumul minim într-o grilă
 * Clasa: 12
 * Capitol: Algoritmi pe grile: Lee și fill
 * Descriere: Grila are n linii și m coloane: 0 = liber, 1 = obstacol. Ne putem
 *            deplasa sus, jos, stânga, dreapta. Algoritmul lui Lee este o
 *            parcurgere în lățime: d[xs][ys] = 1, apoi scoatem celulele din coadă
 *            în ordinea distanței și dăm fiecărui vecin liber nevizitat valoarea
 *            d + 1. Prima dată când o celulă primește o valoare, aceasta este
 *            minimă, pentru că toate celulele de la distanța k sunt prelucrate
 *            înaintea celor de la distanța k + 1. Afișăm d[xf][yf], adică numărul
 *            de celule ale drumului (inclusiv capetele), sau -1 dacă nu există drum.
 * Complexitate: O(n * m)
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
 * Ieșire: 9
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 0 1 0
 * 1 1 0
 * 0 0 0
 * 1 1 3 3
 * Ieșire: -1
 */
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int DIM = 1002;
int d[DIM][DIM]; // -1 = obstacol sau bordură, 0 = nevizitat, k > 0 = distanța
int dl[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
            d[i][j] = -1; // bordura
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
    while (!q.empty() && d[xf][yf] == 0)
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
    cout << (d[xf][yf] > 0 ? d[xf][yf] : -1) << '\n';
    return 0;
}
