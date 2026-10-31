/*
 * Titlu: Ultima cifră a lui x la puterea y
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Ultima cifră a unui produs depinde doar de ultimele cifre ale
 *            factorilor. Ultimele cifre ale puterilor se repetă cu perioada 4
 *            (de exemplu pentru 3: 3, 9, 7, 1, 3, 9, ...). De aceea ajunge să
 *            ridicăm ultima cifră a lui x la puterea r = y % 4, unde r = 0 se
 *            înlocuiește cu 4. Pentru y = 0 rezultatul este 1.
 * Complexitate: O(1)
 *
 * Exemplu
 * Intrare: 13 2025
 * Ieșire: 3
 *
 * Exemplu
 * Intrare: 2 10
 * Ieșire: 4
 */
#include <iostream>
using namespace std;

int main()
{
    long long x, y;
    cin >> x >> y;
    if (y == 0)
    {
        cout << 1 << '\n';
        return 0;
    }
    int c = x % 10;
    int r = y % 4;
    if (r == 0)
    {
        r = 4;
    }
    int rez = 1;
    for (int i = 1; i <= r; i++)
    {
        rez = rez * c % 10;
    }
    cout << rez << '\n';
    return 0;
}
