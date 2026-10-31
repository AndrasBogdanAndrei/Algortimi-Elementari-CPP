/*
 * Titlu: Eliminarea elementelor pare
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: În loc să ștergem elementele pare unul câte unul (fiecare ștergere
 *            mută tot restul vectorului), facem o singură trecere: k numără
 *            elementele păstrate, iar fiecare element impar este copiat pe
 *            poziția k. La final vectorul are k elemente.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 7
 * 1 2 3 4 6 7 8
 * Ieșire: 1 3 7
 */
#include <iostream>
using namespace std;

int v[1001];

int main()
{
    int n, k = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] % 2 != 0)
        {
            k++;
            v[k] = v[i];
        }
    }
    n = k;
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
