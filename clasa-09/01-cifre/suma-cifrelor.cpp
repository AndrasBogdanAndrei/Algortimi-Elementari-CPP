/*
 * Titlu: Suma cifrelor unui număr
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Adună cifrele lui n. Ultima cifră se obține cu n % 10, apoi este
 *            eliminată cu n / 10. Repetăm până când n devine 0.
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 2025
 * Ieșire: 9
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    int suma = 0;
    cin >> n;
    while (n > 0)
    {
        suma = suma + n % 10;
        n = n / 10;
    }
    cout << suma << '\n';
    return 0;
}
