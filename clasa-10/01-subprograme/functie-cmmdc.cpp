/*
 * Titlu: Funcție cmmdc și cmmmc
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: Funcția cmmdc(a, b) aplică algoritmul lui Euclid prin împărțiri:
 *            cât timp b nu este 0, perechea (a, b) devine (b, a % b). Funcția
 *            cmmmc(a, b) o refolosește pe prima: cmmmc = a / cmmdc(a, b) * b
 *            (împărțim întâi, ca produsul să nu depășească tipul de date).
 * Complexitate: O(log(min(a, b)))
 *
 * Exemplu
 * Intrare: 12 18
 * Ieșire: 6 36
 *
 * Exemplu
 * Intrare: 17 5
 * Ieșire: 1 85
 */
#include <iostream>
using namespace std;

long long cmmdc(long long a, long long b)
{
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long cmmmc(long long a, long long b)
{
    return a / cmmdc(a, b) * b;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << cmmdc(a, b) << ' ' << cmmmc(a, b) << '\n';
    return 0;
}
