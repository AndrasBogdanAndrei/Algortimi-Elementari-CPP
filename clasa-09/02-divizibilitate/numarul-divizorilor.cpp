/*
 * Titlu: Numărul divizorilor
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Pentru fiecare d cu d * d <= n care divide n numărăm doi divizori,
 *            d și n / d, cu excepția cazului d * d == n, când cei doi coincid.
 * Complexitate: O(√n)
 *
 * Exemplu
 * Intrare: 36
 * Ieșire: 9
 *
 * Exemplu
 * Intrare: 1
 * Ieșire: 1
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    int nrDiv = 0;
    cin >> n;
    for (long long d = 1; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            if (d * d == n)
            {
                nrDiv = nrDiv + 1;
            }
            else
            {
                nrDiv = nrDiv + 2;
            }
        }
    }
    cout << nrDiv << '\n';
    return 0;
}
