/*
 * Titlu: Produsul cifrelor unui număr
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Înmulțește cifrele lui n. Produsul pornește de la 1 (elementul
 *            neutru al înmulțirii), nu de la 0. Cu do-while, pentru n = 0 se
 *            obține corect produsul 0 (singura cifră este 0).
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 234
 * Ieșire: 24
 *
 * Exemplu
 * Intrare: 0
 * Ieșire: 0
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, produs = 1;
    cin >> n;
    do
    {
        produs = produs * (n % 10);
        n = n / 10;
    }
    while (n > 0);
    cout << produs << '\n';
    return 0;
}
