/*
 * Titlu: Dublarea cifrelor impare
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Fiecare cifră impară a lui n apare de două ori în rezultat.
 *            Construim rezultatul de la dreapta la stânga cu rez = rez + cifra * p;
 *            o cifră impară se adaugă de două ori, deci p crește de două ori.
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 1234
 * Ieșire: 112334
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
        rez = rez + cifra * p;
        p = p * 10;
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
