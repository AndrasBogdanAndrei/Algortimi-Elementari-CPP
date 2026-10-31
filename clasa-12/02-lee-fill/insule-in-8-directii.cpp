/*
 * Titlu: Insule în 8 direcții
 * Clasa: 12
 * Capitol: Algoritmi pe grile: Lee și fill
 * Descriere: Ca la numărarea zonelor, dar două celule de uscat (1) aparțin
 *            aceleiași insule dacă se ating și pe colț, adică vecinătatea are 8
 *            direcții. Singura schimbare este în vectorii de deplasare, care au
 *            acum 8 perechi (dl, dc). Pentru fiecare celulă 1 nevizitată numărăm
 *            o insulă și o ștergem cu fill, folosind o coadă.
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare:
 * 4 5
 * 1 0 0 1 0
 * 0 1 0 0 1
 * 0 0 0 0 0
 * 1 1 0 0 1
 * Ieșire: 4
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 1 0 1
 * 0 1 0
 * 1 0 1
 * Ieșire: 1
 */
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int DIM = 1002;
int a[DIM][DIM];
int dl[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void sterge(int i, int j)
{
    queue<pair<int, int>> q;
    a[i][j] = 0;
    q.push({i, j});
    while (!q.empty())
    {
        int l = q.front().first, c = q.front().second;
        q.pop();
        for (int k = 0; k < 8; k++)
        {
            int lv = l + dl[k], cv = c + dc[k];
            if (a[lv][cv] == 1)
            {
                a[lv][cv] = 0;
                q.push({lv, cv});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int insule = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)
            {
                insule++;
                sterge(i, j);
            }
    cout << insule << '\n';
    return 0;
}
