/*
 * Titlu: Stiva implementată cu un vector
 * Clasa: 11
 * Capitol: Alocare dinamică: liste, stive, cozi
 * Descriere: Stiva este o structură de tip LIFO (ultimul intrat, primul ieșit): se adaugă
 *            și se scoate doar în vârf. Cu un vector st și un indice vf (numărul de
 *            elemente): push pune elementul pe poziția vf + 1, pop scade vf, iar vârful
 *            este st[vf]. Programul execută q operații: „push x”, „pop” și „top” (afișează
 *            vârful). Dacă stiva e vidă la pop sau top, se afișează „Stiva vida”.
 * Complexitate: O(1) pentru fiecare operație
 *
 * Exemplu
 * Intrare:
 * 7
 * push 3
 * push 8
 * top
 * pop
 * top
 * pop
 * pop
 * Ieșire:
 * 8
 * 3
 * Stiva vida
 */
#include <iostream>
#include <string>
using namespace std;

int st[10005], vf = 0;

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
            st[++vf] = x;
        }
        else if (vf == 0)
        {
            cout << "Stiva vida\n";
        }
        else if (op == "pop")
        {
            vf--;
        }
        else
        {
            cout << st[vf] << '\n';
        }
    }
    return 0;
}
