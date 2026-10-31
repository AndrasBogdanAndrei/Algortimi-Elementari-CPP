/*
 * Titlu: Perechi de numere prime gemene
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Două numere prime sunt gemene dacă diferența lor este 2
 *            (de exemplu 11 și 13). Afișăm toate perechile (p, p + 2) cu
 *            p + 2 <= n, testând primalitatea ambelor numere până la √x.
 * Complexitate: O(n · √n)
 *
 * Exemplu
 * Intrare: 20
 * Ieșire:
 * 3 5
 * 5 7
 * 11 13
 * 17 19
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int p = 2; p + 2 <= n; p++)
    {
        bool ambelePrime = true;
        for (int x = p; x <= p + 2; x = x + 2)
        {
            for (int d = 2; d * d <= x; d++)
            {
                if (x % d == 0)
                {
                    ambelePrime = false;
                }
            }
        }
        if (ambelePrime)
        {
            cout << p << ' ' << p + 2 << '\n';
        }
    }
    return 0;
}
