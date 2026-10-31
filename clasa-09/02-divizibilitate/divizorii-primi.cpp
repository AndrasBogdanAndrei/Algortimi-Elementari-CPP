/*
 * Titlu: Divizorii primi ai unui număr
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Este descompunerea în factori primi, din care afișăm doar factorii,
 *            fără exponenți. Fiecare factor găsit este eliminat complet din n.
 * Complexitate: O(√n)
 *
 * Exemplu
 * Intrare: 360
 * Ieșire: 2 3 5
 *
 * Exemplu
 * Intrare: 49
 * Ieșire: 7
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    for (long long d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            cout << d << ' ';
            while (n % d == 0)
            {
                n = n / d;
            }
        }
    }
    if (n > 1)
    {
        cout << n;
    }
    cout << '\n';
    return 0;
}
