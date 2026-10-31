/*
 * Titlu: Coada implementată cu un vector
 * Clasa: 11
 * Capitol: Alocare dinamică: liste, stive, cozi
 * Descriere: Coada este o structură de tip FIFO (primul intrat, primul ieșit): se adaugă
 *            la sfârșit și se scoate de la început, ca la un ghișeu. Cu un vector c și doi
 *            indici: inc (poziția primului element) și sf (poziția ultimului). push pune
 *            elementul pe poziția sf + 1, pop crește inc, iar coada e vidă când inc > sf.
 *            Operațiile sunt „push x”, „pop” și „front” (afișează primul element); la coadă
 *            vidă se afișează „Coada vida”.
 * Complexitate: O(1) pentru fiecare operație
 *
 * Exemplu
 * Intrare:
 * 7
 * push 4
 * push 7
 * push 1
 * front
 * pop
 * front
 * pop
 * Ieșire:
 * 4
 * 7
 */
#include <iostream>
#include <string>
using namespace std;

int c[10005], inc = 1, sf = 0;

int main()
{
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            c[++sf] = x;
        }
        else if (inc > sf)
        {
            cout << "Coada vida\n";
        }
        else if (op == "pop")
        {
            inc++;
        }
        else
        {
            cout << c[inc] << '\n';
        }
    }
    return 0;
}
