/*
 * Titlu: Maximul și pozițiile pe care apare
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: Spre deosebire de un șir citit pe rând, un vector poate fi
 *            parcurs de mai multe ori: la prima parcurgere aflăm maximul, la a
 *            doua afișăm toate pozițiile pe care apare.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 4 9 2 9 1 9
 * Ieșire:
 * 9
 * 2 4 6
 */
#include <iostream>
using namespace std;

int v[1001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int maxim = v[1];
    for (int i = 2; i <= n; i++)
    {
        if (v[i] > maxim)
        {
            maxim = v[i];
        }
    }
    cout << maxim << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == maxim)
        {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}
