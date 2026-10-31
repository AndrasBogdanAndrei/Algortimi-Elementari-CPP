/*
 * Titlu: Suma unei progresii aritmetice: formulă vs. buclă
 * Clasa: 12
 * Capitol: Matematică pentru programare
 * Descriere: Progresia are primul termen a, rația r și n termeni: a, a + r, ...,
 *            a + (n-1) * r. Bucla adună termenii unul câte unul, deci face n
 *            pași. Formula lui Gauss dă direct S = n * a + r * n * (n-1) / 2
 *            (produsul n * (n-1) este mereu par, deci împărțirea e exactă).
 *            Programul calculează suma în ambele feluri, ca să vezi că dau
 *            același rezultat; pentru n = 10^12 bucla ar dura minute, formula
 *            răspunde instant. Prima linie: formula, a doua: bucla.
 * Complexitate: O(1) cu formula, O(n) cu bucla
 *
 * Exemplu
 * Intrare: 1 1 100
 * Ieșire:
 * 5050
 * 5050
 *
 * Exemplu
 * Intrare: 3 4 1000000
 * Ieșire:
 * 2000001000000
 * 2000001000000
 */
#include <iostream>
using namespace std;

long long sumaFormula(long long a, long long r, long long n)
{
    return n * a + r * (n * (n - 1) / 2);
}

long long sumaBucla(long long a, long long r, long long n)
{
    long long s = 0, termen = a;
    for (long long i = 1; i <= n; i++)
    {
        s += termen;
        termen += r;
    }
    return s;
}

int main()
{
    long long a, r, n;
    cin >> a >> r >> n;
    cout << sumaFormula(a, r, n) << '\n';
    cout << sumaBucla(a, r, n) << '\n';
    return 0;
}
