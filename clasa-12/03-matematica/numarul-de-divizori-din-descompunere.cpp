/*
 * Titlu: Numărul și suma divizorilor din descompunerea în factori primi
 * Clasa: 12
 * Capitol: Matematică pentru programare
 * Descriere: Dacă n = p1^e1 * p2^e2 * ... * pk^ek, un divizor alege pentru fiecare
 *            prim un exponent între 0 și ei, deci numărul divizorilor este
 *            (e1 + 1) * (e2 + 1) * ... * (ek + 1). Suma divizorilor este produsul
 *            sumelor 1 + p + p^2 + ... + p^ei. Descompunem n încercând divizorii
 *            d = 2, 3, ... cât timp d * d ≤ n; ce rămâne la final, dacă e mai mare
 *            decât 1, este un factor prim. Programul afișează numărul și suma
 *            divizorilor, pentru n ≤ 10^12.
 * Complexitate: O(sqrt(n))
 *
 * Exemplu
 * Intrare: 360
 * Ieșire: 24 1170
 *
 * Exemplu
 * Intrare: 1000000000000
 * Ieșire: 169 2499694822171
 *
 * Exemplu
 * Intrare: 999999999989
 * Ieșire: 2 999999999990
 *
 * Exemplu
 * Intrare: 1
 * Ieșire: 1 1
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long nrDiv = 1, sumaDiv = 1;
    for (long long d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            int e = 0;
            long long putere = 1, suma = 1; // suma = 1 + d + ... + d^e
            while (n % d == 0)
            {
                n /= d;
                e++;
                putere *= d;
                suma += putere;
            }
            nrDiv *= (e + 1);
            sumaDiv *= suma;
        }
    }
    if (n > 1) // a rămas un factor prim, cu exponentul 1
    {
        nrDiv *= 2;
        sumaDiv *= (1 + n);
    }
    cout << nrDiv << ' ' << sumaDiv << '\n';
    return 0;
}
