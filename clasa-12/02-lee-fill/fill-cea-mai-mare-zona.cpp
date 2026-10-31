/*
 * Titlu: Fill — cea mai mare zonă
 * Clasa: 12
 * Capitol: Algoritmi pe grile: Lee și fill
 * Descriere: Aceeași matrice de 0 și 1, dar acum vrem numărul de celule al celei
 *            mai mari zone de 1 (vecinătate prin laturi). Umplerea se face de data
 *            asta fără recursivitate, cu o coadă: punem celula de start în coadă,
 *            apoi scoatem pe rând celule și adăugăm vecinii 1 nemarcați, numărând
 *            câte celule au trecut prin coadă. Varianta cu coadă nu riscă să umple
 *            stiva de apeluri pe matrice mari (de exemplu 1000 x 1000).
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare:
 * 5 6
 * 1 1 0 1 1 1
 * 0 1 0 0 0 1
 * 1 1 1 0 1 1
 * 0 0 0 0 1 0
 * 1 0 1 1 1 0
 * Ieșire: 10
 *
 * Exemplu
 * Intrare:
 * 1 3
 * 1 0 1
 * Ieșire: 1
 */
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

const int DIM = 1002;
int a[DIM][DIM];
int dl[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// Umple zona care conține celula (i, j) și întoarce numărul ei de celule.
int umple(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    a[i][j] = 0;
    int nr = 0;
    while (!q.empty())
    {
        int l = q.front().first, c = q.front().second;
        q.pop();
        nr++;
        for (int d = 0; d < 4; d++)
        {
            int lv = l + dl[d], cv = c + dc[d];
            if (a[lv][cv] == 1)
            {
                a[lv][cv] = 0; // marcăm la introducere, ca să nu intre de două ori
                q.push({lv, cv});
            }
        }
    }
    return nr;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int maxim = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)
                maxim = max(maxim, umple(i, j));
    cout << maxim << '\n';
    return 0;
}
