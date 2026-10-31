/*
 * Titlu: Prima cifră a unui număr
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Prima cifră (cea din stânga) rămâne după ce tăiem toate celelalte
 *            cifre: împărțim la 10 cât timp numărul are cel puțin două cifre
 *            (n >= 10).
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 7351
 * Ieșire: 7
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    while (n >= 10)
    {
        n = n / 10;
    }
    cout << n << '\n';
    return 0;
}
