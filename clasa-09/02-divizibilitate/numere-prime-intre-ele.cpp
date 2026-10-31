/*
 * Titlu: Numere prime între ele
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Două numere sunt prime între ele dacă singurul lor divizor comun
 *            este 1, adică cmmdc(a, b) = 1. Numerele nu trebuie să fie prime:
 *            15 și 28 sunt prime între ele.
 * Complexitate: O(log(min(a, b)))
 *
 * Exemplu
 * Intrare: 15 28
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: 12 18
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    if (a == 1)
    {
        cout << "DA" << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
