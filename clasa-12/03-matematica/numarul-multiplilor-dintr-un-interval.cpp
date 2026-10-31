/*
 * Titlu: Numărul multiplilor lui k dintr-un interval
 * Clasa: 12
 * Capitol: Matematică pentru programare
 * Descriere: Câte numere din [a, b] se divid cu k? Numerele din [1, x] divizibile
 *            cu k sunt k, 2k, ..., (x / k) * k, adică x / k bucăți (împărțire
 *            întreagă). Scădem multiplii din [1, a - 1] și obținem
 *            b / k - (a - 1) / k, fără nicio buclă. Pentru „divizibile cu k1 sau
 *            cu k2” aplicăm includerea și excluderea: adunăm numărătorile pentru
 *            k1 și k2 și scădem pe cea pentru cmmmc(k1, k2). Programul afișează
 *            ambele rezultate. Se presupune 1 ≤ a ≤ b.
 * Complexitate: O(log min(k1, k2)), de la calculul cmmdc
 *
 * Exemplu
 * Intrare: 10 100 3 5
 * Ieșire:
 * 30
 * 43
 *
 * Exemplu
 * Intrare: 1 1000000000000 4 6
 * Ieșire:
 * 250000000000
 * 333333333333
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

// Câți multipli de k sunt în intervalul [a, b].
long long multipli(long long a, long long b, long long k)
{
    return b / k - (a - 1) / k;
}

int main()
{
    long long a, b, k1, k2;
    cin >> a >> b >> k1 >> k2;
    long long cmmmc = k1 / cmmdc(k1, k2) * k2;
    cout << multipli(a, b, k1) << '\n';
    cout << multipli(a, b, k1) + multipli(a, b, k2) - multipli(a, b, cmmmc) << '\n';
    return 0;
}
