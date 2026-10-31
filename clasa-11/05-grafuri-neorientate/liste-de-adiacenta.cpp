/*
 * Titlu: Listele de adiacență
 * Clasa: 11
 * Capitol: Grafuri neorientate
 * Descriere: Pentru fiecare nod reținem doar lista vecinilor lui. Muchia [x, y] se adaugă
 *            de două ori: y în lista lui x și x în lista lui y. Memoria folosită este
 *            proporțională cu n + m (nu cu n², ca la matrice), ceea ce contează pentru
 *            grafuri mari cu puține muchii. Lungimea listei nodului i este gradul lui.
 *            Listele se sortează ca vecinii să fie afișați în ordine crescătoare.
 * Complexitate: O(n + m log m)
 *
 * Exemplu
 * Intrare:
 * 5 5
 * 1 2
 * 1 5
 * 2 3
 * 4 5
 * 2 5
 * Ieșire:
 * 1: 2 5
 * 2: 1 3 5
 * 3: 2
 * 4: 5
 * 5: 1 2 4
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vecini[100005];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        vecini[x].push_back(y);
        vecini[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(vecini[i].begin(), vecini[i].end());
        cout << i << ':';
        for (int v : vecini[i])
        {
            cout << ' ' << v;
        }
        cout << '\n';
    }
    return 0;
}
