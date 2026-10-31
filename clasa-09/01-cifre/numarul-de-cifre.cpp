/*
 * Titlu: Numărul de cifre ale unui număr
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Numără cifrele lui n tăind la fiecare pas ultima cifră (n / 10)
 *            până când numărul devine 0. Folosim do-while ca numărul 0 să fie
 *            numărat corect: el are o cifră, deși o buclă while nu s-ar executa.
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 12345
 * Ieșire: 5
 *
 * Exemplu
 * Intrare: 0
 * Ieșire: 1
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    int nrCifre = 0;
    cin >> n;
    do
    {
        nrCifre++;
        n = n / 10;
    }
    while (n > 0);
    cout << nrCifre << '\n';
    return 0;
}
