/*
 * Titlu: Număr perfect
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Un număr este perfect dacă este egal cu suma divizorilor săi mai
 *            mici decât el (6 = 1 + 2 + 3). Calculăm suma tuturor divizorilor în
 *            O(√n) și scădem n.
 * Complexitate: O(√n)
 *
 * Exemplu
 * Intrare: 28
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: 12
 * Ieșire: NU
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
    if (n > 1 && suma - n == n)
    {
        cout << "DA" << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
