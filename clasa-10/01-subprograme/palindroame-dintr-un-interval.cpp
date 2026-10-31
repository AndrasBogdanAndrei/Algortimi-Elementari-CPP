/*
 * Titlu: Palindroame dintr-un interval
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: Problemă rezolvată prin descompunere în funcții mici: oglindit(x)
 *            întoarce răsturnatul lui x, palindrom(x) îl folosește pe primul, iar
 *            main doar parcurge intervalul [a, b] și afișează palindroamele, apoi
 *            numărul lor pe al doilea rând (0 dacă nu există niciunul).
 * Complexitate: O((b - a) * k), unde k este numărul de cifre
 *
 * Exemplu
 * Intrare: 100 150
 * Ieșire:
 * 101 111 121 131 141
 * 5
 *
 * Exemplu
 * Intrare: 5 12
 * Ieșire:
 * 5 6 7 8 9 11
 * 6
 */
#include <iostream>
using namespace std;

int oglindit(int x)
{
    int ogl = 0;
    while (x > 0)
    {
        ogl = ogl * 10 + x % 10;
        x = x / 10;
    }
    return ogl;
}

bool palindrom(int x)
{
    return oglindit(x) == x;
}

int main()
{
    int a, b, cate = 0;
    cin >> a >> b;
    for (int x = a; x <= b; x++)
    {
        if (palindrom(x))
        {
            cout << x << ' ';
            cate++;
        }
    }
    cout << '\n' << cate << '\n';
    return 0;
}
