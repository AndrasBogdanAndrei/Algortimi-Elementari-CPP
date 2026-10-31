/*
 * Titlu: Permutarea circulară la stânga
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: Fiecare element se mută cu o poziție la stânga, iar primul ajunge
 *            pe ultima poziție. Salvăm v[1] într-o variabilă, mutăm restul
 *            (v[i] = v[i + 1]) și punem valoarea salvată în v[n].
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 2 3 4 5
 * Ieșire: 2 3 4 5 1
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
    int primul = v[1];
    for (int i = 1; i < n; i++)
    {
        v[i] = v[i + 1];
    }
    v[n] = primul;
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
