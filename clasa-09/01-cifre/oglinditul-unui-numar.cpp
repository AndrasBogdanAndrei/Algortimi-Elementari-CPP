/*
 * Titlu: Oglinditul unui număr
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Construiește numărul format din cifrele lui n scrise în ordine inversă.
 *            La fiecare pas luăm ultima cifră (n % 10), o lipim la dreapta
 *            oglinditului (ogl * 10 + cifra) și o tăiem din n (n / 10).
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 2134
 * Ieșire: 4312
 *
 * Exemplu
 * Intrare: 1200
 * Ieșire: 21
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, ogl = 0;
    cin >> n;
    while (n > 0)
    {
        int cifra = n % 10;
        ogl = ogl * 10 + cifra;
        n = n / 10;
    }
    cout << ogl << '\n';
    return 0;
}
