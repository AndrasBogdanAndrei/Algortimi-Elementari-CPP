/*
 * Titlu: Indicatorul lui Euler
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: φ(n) este numărul valorilor din 1..n prime cu n. Dacă p1, p2, ...
 *            sunt divizorii primi ai lui n, atunci φ(n) = n · (1 - 1/p1) · (1 - 1/p2) · ...
 *            Pentru fiecare factor prim p găsit la descompunere facem
 *            rez = rez / p * (p - 1), ca să lucrăm doar cu numere întregi.
 * Complexitate: O(√n)
 *
 * Exemplu
 * Intrare: 12
 * Ieșire: 4
 *
 * Exemplu
 * Intrare: 13
 * Ieșire: 12
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, rez;
    cin >> n;
    rez = n;
    for (long long p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            rez = rez / p * (p - 1);
            while (n % p == 0)
            {
                n = n / p;
            }
        }
    }
    if (n > 1)
    {
        rez = rez / n * (n - 1);
    }
    cout << rez << '\n';
    return 0;
}
