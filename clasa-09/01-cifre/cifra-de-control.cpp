/*
 * Titlu: Cifra de control
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Cifra de control se obține înlocuind numărul cu suma cifrelor lui,
 *            în mod repetat, până când rămâne o singură cifră
 *            (de exemplu 99999 -> 45 -> 9). Același rezultat dă formula
 *            1 + (n - 1) % 9, pentru n > 0.
 * Complexitate: O(k), unde k este numărul de cifre ale lui n (după prima sumă
 *               rămân foarte puține cifre)
 *
 * Exemplu
 * Intrare: 99999
 * Ieșire: 9
 *
 * Exemplu
 * Intrare: 1234
 * Ieșire: 1
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while (n >= 10)
    {
        long long suma = 0;
        while (n > 0)
        {
            suma = suma + n % 10;
            n = n / 10;
        }
        n = suma;
    }
    cout << n << '\n';
    return 0;
}
