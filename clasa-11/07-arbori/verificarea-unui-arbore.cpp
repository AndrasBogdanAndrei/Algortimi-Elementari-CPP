/*
 * Titlu: Verificarea că un graf este arbore
 * Clasa: 11
 * Capitol: Arbori
 * Descriere: Un arbore este un graf neorientat conex și fără cicluri. Pentru un graf cu n
 *            noduri următoarele afirmații sunt echivalente: este arbore; este conex și are
 *            n - 1 muchii; nu are cicluri și are n - 1 muchii. Verificăm deci numărul de
 *            muchii, apoi conexitatea cu o parcurgere DFS din nodul 1 (toate nodurile trebuie
 *            atinse). Se afișează DA sau NU, cu motivul.
 * Complexitate: O(n²) cu matricea de adiacență
 *
 * Exemplu
 * Intrare:
 * 5 4
 * 1 2
 * 1 3
 * 3 4
 * 3 5
 * Ieșire: DA
 *
 * Exemplu
 * Intrare:
 * 4 3
 * 1 2
 * 2 3
 * 3 1
 * Ieșire: NU (graful nu este conex)
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 1 2
 * 2 3
 * 1 3
 * Ieșire: NU (un arbore cu n noduri are n-1 muchii)
 */
#include <iostream>
using namespace std;

int n, m, a[105][105];
bool vizitat[105];

void dfs(int x)
{
    vizitat[x] = true;
    for (int y = 1; y <= n; y++)
    {
        if (a[x][y] == 1 && !vizitat[y])
        {
            dfs(y);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    if (m != n - 1)
    {
        cout << "NU (un arbore cu n noduri are n-1 muchii)\n";
        return 0;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (!vizitat[i])
        {
            cout << "NU (graful nu este conex)\n";
            return 0;
        }
    }
    cout << "DA\n";
    return 0;
}
