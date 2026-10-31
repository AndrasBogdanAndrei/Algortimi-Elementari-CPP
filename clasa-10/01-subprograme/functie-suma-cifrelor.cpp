/*
 * Titlu: Funcție pentru suma cifrelor
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: Funcția sumaCifre(x) primește numărul prin valoare (lucrează pe o
 *            copie, deci x-ul din main nu se strică) și întoarce suma cifrelor.
 *            În main citim n numere și păstrăm numărul cu suma cifrelor cea mai
 *            mare; la egalitate rămâne primul găsit (comparăm cu > strict).
 * Complexitate: O(n * k), unde k este numărul de cifre al unui număr
 *
 * Exemplu
 * Intrare:
 * 4
 * 123 99 405 18
 * Ieșire: 99
 *
 * Exemplu
 * Intrare:
 * 3
 * 0 7 70
 * Ieșire: 7
 */
#include <iostream>
using namespace std;

int sumaCifre(int x)
{
    int s = 0;
    while (x > 0)
    {
        s = s + x % 10;
        x = x / 10;
    }
    return s;
}

int main()
{
    int n, x;
    cin >> n;
    int celMaiBun = -1, sumaMaxima = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int s = sumaCifre(x);
        if (s > sumaMaxima)
        {
            sumaMaxima = s;
            celMaiBun = x;
        }
    }
    cout << celMaiBun << '\n';
    return 0;
}
