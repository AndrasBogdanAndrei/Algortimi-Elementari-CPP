/*
 * Titlu: Numere superprime
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: Un număr este superprim dacă toate prefixele lui sunt numere prime.
 *            De exemplu 239 este superprim: 2, 23 și 239 sunt prime. Funcția
 *            estePrim(x) este refolosită de funcția superprim(x), care taie pe rând
 *            ultima cifră (x / 10) și verifică fiecare prefix. Se afișează toate
 *            numerele superprime mai mici sau egale cu n.
 * Complexitate: O(n * k * sqrt(n)), unde k este numărul de cifre
 *
 * Exemplu
 * Intrare: 100
 * Ieșire: 2 3 5 7 23 29 31 37 53 59 71 73 79
 *
 * Exemplu
 * Intrare: 10
 * Ieșire: 2 3 5 7
 */
#include <iostream>
using namespace std;

bool estePrim(int x)
{
    if (x < 2)
        return false;
    for (int d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}

bool superprim(int x)
{
    while (x > 0)
    {
        if (!estePrim(x))
            return false;
        x = x / 10;   // trecem la prefixul mai scurt
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int x = 2; x <= n; x++)
    {
        if (superprim(x))
            cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
