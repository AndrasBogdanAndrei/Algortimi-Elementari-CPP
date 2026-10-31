/*
 * Titlu: Înlocuirea unei cifre cu alta
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Înlocuiește în n fiecare apariție a cifrei x cu cifra y.
 *            Reconstruim numărul de la dreapta la stânga cu rez = rez + cifra * p,
 *            punând y în locul fiecărei cifre egale cu x.
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 2721 2 5
 * Ieșire: 5751
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, rez = 0, p = 1;
    int x, y;
    cin >> n >> x >> y;
    do
    {
        int cifra = n % 10;
        if (cifra == x)
        {
            cifra = y;
        }
        rez = rez + cifra * p;
        p = p * 10;
        n = n / 10;
    }
    while (n > 0);
    cout << rez << '\n';
    return 0;
}
