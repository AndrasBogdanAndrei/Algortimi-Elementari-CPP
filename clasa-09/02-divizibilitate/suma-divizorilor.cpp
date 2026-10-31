/*
 * Titlu: Suma divizorilor
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Adunăm divizorii în perechi (d și n / d) pentru d * d <= n; când
 *            n este pătrat perfect, rădăcina se adună o singură dată.
 * Complexitate: O(√n)
 *
 * Exemplu
 * Intrare: 12
 * Ieșire: 28
 *
 * Exemplu
 * Intrare: 16
 * Ieșire: 31
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, suma = 0;
    cin >> n;
    for (long long d = 1; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            suma = suma + d;
            if (d * d != n)
            {
                suma = suma + n / d;
            }
        }
    }
    cout << suma << '\n';
    return 0;
}
