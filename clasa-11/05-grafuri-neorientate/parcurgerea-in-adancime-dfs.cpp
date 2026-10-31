/*
 * Titlu: Parcurgerea în adâncime (DFS)
 * Clasa: 11
 * Capitol: Grafuri neorientate
 * Descriere: Parcurgerea în adâncime merge cât de departe se poate: din nodul curent trece
 *            în primul vecin nevizitat, de acolo în primul vecin nevizitat al acestuia și
 *            așa mai departe; când un nod nu mai are vecini nevizitați, se întoarce la nodul
 *            din care a venit. Revenirea se face natural prin recursivitate (stiva de
 *            apeluri). Vecinii se iau în ordine crescătoare. Datele: n m, cele m muchii,
 *            apoi nodul de start.
 * Complexitate: O(n²) cu matricea de adiacență (O(n + m) cu liste de adiacență)
 *
 * Exemplu
 * Intrare:
 * 7 8
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * 3 5
 * 4 6
 * 5 6
 * 6 7
 * 5
 * Ieșire: 5 2 1 3 4 6 7
 */
#include <iostream>
using namespace std;

int n, m, a[105][105];
bool vizitat[105];

void dfs(int x)
{
    vizitat[x] = true;
    cout << x << ' ';
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
    int start;
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    cin >> start;
    dfs(start);
    cout << '\n';
    return 0;
}
