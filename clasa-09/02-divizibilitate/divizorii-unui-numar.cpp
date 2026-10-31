/*
 * Titlu: Divizorii unui număr
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Divizorii vin în perechi: dacă d divide n, atunci și n / d divide n,
 *            iar unul dintre ei este cel mult rădăcina pătrată a lui n. Ajunge
 *            deci să încercăm d de la 1 cât timp d * d <= n. Ca să-i afișăm în
 *            ordine crescătoare, facem două treceri: întâi divizorii mici d (în
 *            sus), apoi perechile lor n / d (în jos), fără să repetăm rădăcina
 *            când n este pătrat perfect.
 * Complexitate: O(√n)
 *
 * Exemplu
 * Intrare: 12
 * Ieșire: 1 2 3 4 6 12
 *
 * Exemplu
 * Intrare: 36
 * Ieșire: 1 2 3 4 6 9 12 18 36
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, d;
    cin >> n;
    // prima trecere: divizorii d cu d * d <= n
    for (d = 1; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            cout << d << ' ';
        }
    }
    // a doua trecere: perechile n / d, de la d mare spre d mic
    for (d = d - 1; d >= 1; d--)
    {
        if (n % d == 0 && d * d != n)
        {
            cout << n / d << ' ';
        }
    }
    cout << '\n';
    return 0;
}
