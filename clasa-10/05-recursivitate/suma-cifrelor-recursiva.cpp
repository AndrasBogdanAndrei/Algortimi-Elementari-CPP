/*
 * Titlu: Suma cifrelor, recursiv
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Suma cifrelor lui n este ultima cifră (n % 10) plus suma cifrelor
 *            numărului rămas după tăierea ei (n / 10). Oprirea: un număr cu o
 *            singură cifră (n < 10) are suma egală cu el însuși. Funcția
 *            numarCifre are aceeași structură, dar adună 1 în loc de cifră.
 * Complexitate: O(k), unde k este numărul de cifre
 *
 * Exemplu
 * Intrare: 12345
 * Ieșire: 15 5
 *
 * Exemplu
 * Intrare: 7
 * Ieșire: 7 1
 */
#include <iostream>
using namespace std;

int sumaCifre(long long n)
{
    if (n < 10)
        return n;
    return n % 10 + sumaCifre(n / 10);
}

int numarCifre(long long n)
{
    if (n < 10)
        return 1;
    return 1 + numarCifre(n / 10);
}

int main()
{
    long long n;
    cin >> n;
    cout << sumaCifre(n) << ' ' << numarCifre(n) << '\n';
    return 0;
}
