/*
 * Titlu: Divizorii proprii ai unui număr
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Divizorii proprii sunt divizorii diferiți de 1 și de n. Folosim
 *            aceleași două treceri ca la afișarea tuturor divizorilor, dar
 *            pornim de la d = 2, deci lipsesc și 1, și perechea lui, n. Un număr
 *            prim nu are divizori proprii.
 * Complexitate: O(√n)
 *
 * Exemplu
 * Intrare: 12
 * Ieșire: 2 3 4 6
 *
 * Exemplu
 * Intrare: 13
 * Ieșire: nu are divizori proprii
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, d;
    int gasiti = 0;
    cin >> n;
    for (d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            cout << d << ' ';
            gasiti++;
        }
    }
    for (d = d - 1; d >= 2; d--)
    {
        if (n % d == 0 && d * d != n)
        {
            cout << n / d << ' ';
            gasiti++;
        }
    }
    if (gasiti == 0)
    {
        cout << "nu are divizori proprii";
    }
    cout << '\n';
    return 0;
}
