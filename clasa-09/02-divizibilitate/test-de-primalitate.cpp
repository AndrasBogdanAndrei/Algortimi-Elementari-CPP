/*
 * Titlu: Test de primalitate
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Un număr este prim dacă are exact doi divizori: 1 și el însuși
 *            (deci 0 și 1 nu sunt prime). Dacă n are un divizor d între 2 și n - 1,
 *            are și unul cel mult egal cu √n, așa că verificăm doar până acolo.
 *            Tratăm separat numerele pare, apoi încercăm doar divizori impari.
 * Complexitate: O(√n)
 *
 * Exemplu
 * Intrare: 97
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: 1
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    bool prim = true;
    cin >> n;
    if (n < 2)
    {
        prim = false;
    }
    else if (n % 2 == 0)
    {
        prim = (n == 2);
    }
    else
    {
        for (long long d = 3; d * d <= n; d = d + 2)
        {
            if (n % d == 0)
            {
                prim = false;
                break;
            }
        }
    }
    if (prim)
    {
        cout << "DA" << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
