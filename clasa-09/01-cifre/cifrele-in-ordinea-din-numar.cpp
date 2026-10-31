/*
 * Titlu: Afișarea cifrelor în ordinea din număr
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Cu n % 10 cifrele ies de la dreapta la stânga. Ca să le afișăm de
 *            la stânga la dreapta, calculăm întâi p = cea mai mare putere a lui
 *            10 cel mult egală cu n. Apoi cifra curentă este n / p % 10, iar p
 *            scade de 10 ori la fiecare pas.
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 4072
 * Ieșire: 4 0 7 2
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, p = 1;
    cin >> n;
    while (p * 10 <= n)
    {
        p = p * 10;
    }
    while (p > 0)
    {
        cout << n / p % 10 << ' ';
        p = p / 10;
    }
    cout << '\n';
    return 0;
}
