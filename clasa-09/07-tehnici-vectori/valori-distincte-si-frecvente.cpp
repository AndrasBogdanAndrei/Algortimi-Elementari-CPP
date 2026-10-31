/*
 * Titlu: Valorile distincte și frecvențele lor
 * Clasa: 9
 * Capitol: Frecvență, sume parțiale și ciurul lui Eratostene
 * Descriere: După ce am construit vectorul de frecvență, valorile distincte
 *            sunt indicii val cu frecv[val] > 0. Parcurgându-i crescător, le
 *            afișăm direct în ordine, fiecare cu frecvența ei, câte una pe linie.
 *            Valorile sunt între 0 și 1000.
 * Complexitate: O(n + V), unde V este valoarea maximă posibilă
 *
 * Exemplu
 * Intrare:
 * 8
 * 5 2 5 9 2 5 0 2
 * Ieșire:
 * 0 1
 * 2 3
 * 5 3
 * 9 1
 */
#include <iostream>
using namespace std;

const int VMAX = 1000;
int frecv[VMAX + 1];

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        frecv[x]++;
    }
    for (int val = 0; val <= VMAX; val++)
    {
        if (frecv[val] > 0)
        {
            cout << val << ' ' << frecv[val] << '\n';
        }
    }
    return 0;
}
