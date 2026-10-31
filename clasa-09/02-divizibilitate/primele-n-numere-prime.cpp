/*
 * Titlu: Primele n numere prime
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Luăm pe rând candidații 2, 3, 4, ... și îi testăm cu testul de
 *            primalitate până la √x. Ne oprim după ce am afișat n numere prime.
 * Complexitate: aproximativ O(n · √P), unde P este al n-lea număr prim
 *
 * Exemplu
 * Intrare: 10
 * Ieșire: 2 3 5 7 11 13 17 19 23 29
 */
#include <iostream>
using namespace std;

int main()
{
    int n, gasite = 0;
    cin >> n;
    for (long long x = 2; gasite < n; x++)
    {
        bool prim = true;
        for (long long d = 2; d * d <= x; d++)
        {
            if (x % d == 0)
            {
                prim = false;
                break;
            }
        }
        if (prim)
        {
            cout << x << ' ';
            gasite++;
        }
    }
    cout << '\n';
    return 0;
}
