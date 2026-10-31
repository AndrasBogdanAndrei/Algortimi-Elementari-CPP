/*
 * Titlu: Componentele conexe
 * Clasa: 11
 * Capitol: Grafuri neorientate
 * Descriere: Un graf este conex dacă între oricare două noduri există un lanț. O componentă
 *            conexă este o „bucată” conexă maximală a grafului. Luăm nodurile în ordine; din
 *            fiecare nod încă nevizitat pornim o parcurgere DFS, iar toate nodurile atinse
 *            primesc același număr de componentă. Numărul de parcurgeri pornite este
 *            numărul de componente (graful e conex dacă iese 1). Se afișează numărul de
 *            componente și nodurile fiecăreia, în ordine crescătoare.
 * Complexitate: O(n²) cu matricea de adiacență
 *
 * Exemplu
 * Intrare:
 * 8 5
 * 1 4
 * 4 6
 * 2 7
 * 3 8
 * 8 2
 * Ieșire:
 * 3
 * 1 4 6
 * 2 3 7 8
 * 5
 */
#include <iostream>
using namespace std;

int n, m, a[105][105], comp[105];

void dfs(int x, int c)
{
    comp[x] = c;
    for (int y = 1; y <= n; y++)
    {
        if (a[x][y] == 1 && comp[y] == 0)
        {
            dfs(y, c);
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

    int nrComp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (comp[i] == 0)
        {
            nrComp++;
            dfs(i, nrComp);
        }
    }

    cout << nrComp << '\n';
    for (int c = 1; c <= nrComp; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (comp[i] == c)
            {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
