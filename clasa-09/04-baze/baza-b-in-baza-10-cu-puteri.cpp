/*
 * Titlu: Conversia în baza 10 cu puterile bazei
 * Clasa: 9
 * Capitol: Baze de numerație
 * Descriere: Varianta pentru b <= 10, când numărul se poate citi ca întreg:
 *            cifrele lui se extrag de la dreapta cu n % 10, iar fiecare cifră
 *            se înmulțește cu puterea corespunzătoare a bazei (1, b, b², ...).
 *            1101 în baza 2 = 1·1 + 0·2 + 1·4 + 1·8 = 13.
 * Complexitate: O(k), unde k este numărul de cifre
 *
 * Exemplu
 * Intrare: 1101 2
 * Ieșire: 13
 *
 * Exemplu
 * Intrare: 207 8
 * Ieșire: 135
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, rez = 0, p = 1;
    int b;
    cin >> n >> b;
    while (n > 0)
    {
        rez = rez + n % 10 * p;
        p = p * b;
        n = n / 10;
    }
    cout << rez << '\n';
    return 0;
}
