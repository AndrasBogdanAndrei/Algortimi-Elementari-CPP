/*
 * Titlu: Sortarea prin numărare
 * Clasa: 9
 * Capitol: Sortare și căutare
 * Descriere: Când valorile sunt numere naturale mici (aici 0..10000), nu
 *            comparăm elemente: numărăm de câte ori apare fiecare valoare într-un
 *            vector de frecvență, apoi parcurgem valorile posibile în ordine
 *            crescătoare și afișăm fiecare valoare de câte ori a apărut.
 * Complexitate: O(n + V), unde V este valoarea maximă posibilă
 *
 * Exemplu
 * Intrare:
 * 8
 * 7 3 0 7 10 3 3 1
 * Ieșire: 0 1 3 3 3 7 7 10
 */
#include <iostream>
using namespace std;

const int VMAX = 10000;
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
        for (int k = 1; k <= frecv[val]; k++)
        {
            cout << val << ' ';
        }
    }
    cout << '\n';
    return 0;
}
