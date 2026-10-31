/*
 * Titlu: Căutarea secvențială
 * Clasa: 9
 * Capitol: Sortare și căutare
 * Descriere: Verificăm elementele pe rând, de la primul, până găsim valoarea x
 *            sau terminăm vectorul. Merge pe orice vector, sortat sau nu. Se
 *            afișează poziția primei apariții a lui x sau NU dacă x lipsește.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 4 8 15 16 23 15
 * 15
 * Ieșire: 3
 *
 * Exemplu
 * Intrare:
 * 3
 * 1 2 3
 * 7
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int v[1001];

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cin >> x;
    int poz = 0;
    for (int i = 1; i <= n && poz == 0; i++)
    {
        if (v[i] == x)
        {
            poz = i;
        }
    }
    if (poz != 0)
    {
        cout << poz << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
