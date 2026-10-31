/*
 * Titlu: Ștergerea elementului de pe o poziție
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: Ca să ștergem elementul de pe poziția poz, mutăm elementele de
 *            după el cu o poziție la stânga, de la stânga spre dreapta
 *            (v[i] = v[i + 1]), apoi n scade cu 1.
 *            Se citesc n, cele n elemente și poz (1 <= poz <= n).
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 2 3 4 5
 * 2
 * Ieșire: 1 3 4 5
 */
#include <iostream>
using namespace std;

int v[1001];

int main()
{
    int n, poz;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cin >> poz;
    for (int i = poz; i < n; i++)
    {
        v[i] = v[i + 1];
    }
    n--;
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
