/*
 * Titlu: Permutarea circulară la dreapta
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: Fiecare element se mută cu o poziție la dreapta, iar ultimul
 *            ajunge pe prima poziție. Salvăm v[n], mutăm restul de la capăt spre
 *            început (v[i] = v[i - 1]) și punem valoarea salvată în v[1].
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 2 3 4 5
 * Ieșire: 5 1 2 3 4
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
    int ultimul = v[n];
    for (int i = n; i > 1; i--)
    {
        v[i] = v[i - 1];
    }
    v[1] = ultimul;
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
