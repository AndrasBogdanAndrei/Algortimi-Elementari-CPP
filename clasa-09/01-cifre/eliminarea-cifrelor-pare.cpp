/*
 * Titlu: Eliminarea cifrelor pare
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Construim un număr nou din cifrele impare ale lui n, păstrând
 *            ordinea lor. Cifrele vin de la dreapta la stânga, așa că fiecare
 *            cifră păstrată se pune în fața celor deja puse: rez = rez + cifra * p,
 *            unde p este 1, 10, 100, ... (crește doar când păstrăm o cifră).
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 123456
 * Ieșire: 135
 *
 * Exemplu
 * Intrare: 2468
 * Ieșire: 0
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, rez = 0, p = 1;
    cin >> n;
    while (n > 0)
    {
        int cifra = n % 10;
        if (cifra % 2 == 1)
        {
            rez = rez + cifra * p;
            p = p * 10;
        }
        n = n / 10;
    }
    cout << rez << '\n';
    return 0;
}
