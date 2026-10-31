/*
 * Titlu: Verificarea unui vector simetric
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: Un vector este simetric (palindrom) dacă v[i] = v[n - i + 1]
 *            pentru orice i. Comparăm perechile de la capete spre mijloc și ne
 *            oprim la prima pereche diferită.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 2 3 2 1
 * Ieșire: DA
 *
 * Exemplu
 * Intrare:
 * 4
 * 1 2 3 1
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int v[1001];

int main()
{
    int n;
    bool simetric = true;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n / 2 && simetric; i++)
    {
        if (v[i] != v[n - i + 1])
        {
            simetric = false;
        }
    }
    if (simetric)
    {
        cout << "DA" << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
