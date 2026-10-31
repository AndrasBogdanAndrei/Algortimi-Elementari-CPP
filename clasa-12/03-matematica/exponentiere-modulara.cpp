/*
 * Titlu: Exponențierea modulară
 * Clasa: 12
 * Capitol: Matematică pentru programare
 * Descriere: Calculăm a^n mod m pentru n de până la 10^18. Folosim aceeași idee ca
 *            la exponențierea rapidă, dar după fiecare înmulțire luăm restul la m:
 *            (x * y) mod m = ((x mod m) * (y mod m)) mod m. Cum m ≤ 10^9, orice
 *            produs a două resturi este sub 10^18 și încape în long long. Astfel
 *            numerele nu cresc niciodată, iar pașii sunt doar câți biți are n
 *            (cel mult 60).
 * Complexitate: O(log n)
 *
 * Exemplu
 * Intrare: 2 10 1000
 * Ieșire: 24
 *
 * Exemplu
 * Intrare: 3 200 1000000007
 * Ieșire: 136318165
 *
 * Exemplu
 * Intrare: 7 1000000000000000000 1000000007
 * Ieșire: 259616729
 */
#include <iostream>
using namespace std;

long long putereModulara(long long baza, long long exponent, long long mod)
{
    long long rezultat = 1 % mod; // pentru mod = 1 rezultatul trebuie să fie 0
    baza = baza % mod;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            rezultat = rezultat * baza % mod;
        baza = baza * baza % mod;
        exponent = exponent / 2;
    }
    return rezultat;
}

int main()
{
    long long a, n, m;
    cin >> a >> n >> m;
    cout << putereModulara(a, n, m) << '\n';
    return 0;
}
