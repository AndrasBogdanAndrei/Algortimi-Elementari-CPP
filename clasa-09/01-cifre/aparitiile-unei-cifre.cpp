/*
 * Titlu: Numărul de apariții ale cifrei k
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Parcurgem cifrele lui n și numărăm câte sunt egale cu k.
 *            Cu do-while, pentru n = 0 și k = 0 răspunsul este corect 1.
 * Complexitate: O(c), unde c este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 1213141 1
 * Ieșire: 4
 *
 * Exemplu
 * Intrare: 0 0
 * Ieșire: 1
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    int k, aparitii = 0;
    cin >> n >> k;
    do
    {
        if (n % 10 == k)
        {
            aparitii++;
        }
        n = n / 10;
    }
    while (n > 0);
    cout << aparitii << '\n';
    return 0;
}
