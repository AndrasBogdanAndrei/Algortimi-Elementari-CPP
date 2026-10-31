/*
 * Titlu: Descompunerea în factori primi
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Încercăm factorii d = 2, 3, 4, ... și împărțim n la d de câte ori
 *            se poate, numărând de câte ori (exponentul). Un d compus nu mai
 *            divide n, pentru că factorii lui primi au fost deja eliminați.
 *            Ne oprim când d * d > n; dacă a rămas n > 1, acesta este un
 *            ultim factor prim, cu exponentul 1.
 *            Se afișează pe fiecare linie factorul și exponentul.
 * Complexitate: O(√n)
 *
 * Exemplu
 * Intrare: 360
 * Ieșire:
 * 2 3
 * 3 2
 * 5 1
 *
 * Exemplu
 * Intrare: 26
 * Ieșire:
 * 2 1
 * 13 1
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    for (long long d = 2; d * d <= n; d++)
    {
        int exponent = 0;
        while (n % d == 0)
        {
            n = n / d;
            exponent++;
        }
        if (exponent > 0)
        {
            cout << d << ' ' << exponent << '\n';
        }
    }
    if (n > 1)
    {
        cout << n << ' ' << 1 << '\n';
    }
    return 0;
}
