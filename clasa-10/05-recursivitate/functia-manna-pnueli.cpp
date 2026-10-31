/*
 * Titlu: Funcția Manna-Pnueli
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Funcția este definită astfel: f(x) = x - 1 dacă x >= 12, altfel
 *            f(x) = f(f(x + 2)). Autoapelul interior f(x + 2) se calculează primul,
 *            iar rezultatul lui devine argumentul autoapelului exterior. Pentru orice
 *            x < 12 rezultatul este 11, dar numărul de apeluri crește cu cât x este
 *            mai mic. Este un exercițiu bun de urmărire a stivei: se afișează valoarea
 *            și numărul total de apeluri.
 * Complexitate: O(12 - x) apeluri pentru x < 12, O(1) altfel
 *
 * Exemplu
 * Intrare: 8
 * Ieșire: 11 9
 *
 * Exemplu
 * Intrare: 15
 * Ieșire: 14 1
 */
#include <iostream>
using namespace std;

int apeluri;

int f(int x)
{
    apeluri++;
    if (x >= 12)
        return x - 1;
    return f(f(x + 2));
}

int main()
{
    int x;
    cin >> x;
    int rez = f(x);
    cout << rez << ' ' << apeluri << '\n';
    return 0;
}
