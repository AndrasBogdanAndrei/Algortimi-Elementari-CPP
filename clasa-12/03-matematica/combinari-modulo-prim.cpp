/*
 * Titlu: Combinări modulo un număr prim
 * Clasa: 12
 * Capitol: Matematică pentru programare
 * Descriere: Calculăm C(n, k) mod P, cu P = 1 000 000 007 (prim) și n ≤ 10^6.
 *            Avem C(n, k) = n! / (k! * (n-k)!), dar împărțirea nu se poate face
 *            direct pe resturi. Înlocuim împărțirea cu înmulțirea cu inversul
 *            modular: după mica teoremă a lui Fermat, x^(P-1) ≡ 1 (mod P) pentru
 *            x nedivizibil cu P, deci inversul lui x este x^(P-2) mod P, calculat
 *            cu exponențiere rapidă. Precalculăm factorialele modulo P, apoi
 *            C(n, k) = n! * inv(k!) * inv((n-k)!) mod P.
 * Complexitate: O(n + log P)
 *
 * Exemplu
 * Intrare: 5 2
 * Ieșire: 10
 *
 * Exemplu
 * Intrare: 100 50
 * Ieșire: 538992043
 *
 * Exemplu
 * Intrare: 1000000 500000
 * Ieșire: 996692777
 *
 * Exemplu
 * Intrare: 3 7
 * Ieșire: 0
 */
#include <iostream>
#include <vector>
using namespace std;

const long long P = 1000000007;

long long putere(long long baza, long long exponent)
{
    long long rezultat = 1;
    baza %= P;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            rezultat = rezultat * baza % P;
        baza = baza * baza % P;
        exponent /= 2;
    }
    return rezultat;
}

long long invers(long long x)
{
    return putere(x, P - 2); // mica teoremă a lui Fermat
}

int main()
{
    int n, k;
    cin >> n >> k;
    if (k < 0 || k > n)
    {
        cout << 0 << '\n';
        return 0;
    }
    vector<long long> fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % P;
    long long rez = fact[n] * invers(fact[k]) % P * invers(fact[n - k]) % P;
    cout << rez << '\n';
    return 0;
}
