/*
 * Titlu: Maximul și minimul unui șir
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Se citesc n și apoi n numere întregi. Maximul și minimul pornesc
 *            de la primul număr citit (nu de la 0, pentru că toate numerele pot
 *            fi negative), apoi fiecare număr următor este comparat cu ele.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 3 -2 8 0 8
 * Ieșire: 8 -2
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    long long x, maxim, minim;
    cin >> n >> x;
    maxim = x;
    minim = x;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        if (x > maxim)
        {
            maxim = x;
        }
        if (x < minim)
        {
            minim = x;
        }
    }
    cout << maxim << ' ' << minim << '\n';
    return 0;
}
