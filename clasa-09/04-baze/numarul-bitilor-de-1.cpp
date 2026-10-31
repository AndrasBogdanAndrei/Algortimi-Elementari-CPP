/*
 * Titlu: Numărul de biți 1 din scrierea în baza 2
 * Clasa: 9
 * Capitol: Baze de numerație
 * Descriere: Cifrele în baza 2 se obțin la fel ca cifrele în baza 10, doar că
 *            împărțim la 2: ultima cifră binară este n % 2. Numărăm câte dintre
 *            ele sunt 1. 13 = 1101 în baza 2, deci are 3 biți de 1.
 * Complexitate: O(log n)
 *
 * Exemplu
 * Intrare: 13
 * Ieșire: 3
 *
 * Exemplu
 * Intrare: 1024
 * Ieșire: 1
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    int biti = 0;
    cin >> n;
    while (n > 0)
    {
        biti = biti + n % 2;
        n = n / 2;
    }
    cout << biti << '\n';
    return 0;
}
