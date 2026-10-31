/*
 * Titlu: Exponențierea rapidă
 * Clasa: 12
 * Capitol: Matematică pentru programare
 * Descriere: Calculăm a^n cu aproximativ log2(n) înmulțiri în loc de n.
 *            Ideea: a^n = (a^2)^(n/2) dacă n este par și a^n = a * a^(n-1) dacă n
 *            este impar. Varianta iterativă parcurge biții lui n: când bitul
 *            curent este 1 înmulțim rezultatul cu baza, apoi ridicăm baza la
 *            pătrat și trecem la bitul următor (n = n / 2). De exemplu,
 *            3^13 = 3^8 * 3^4 * 3^1, pentru că 13 = 1101 în baza 2.
 *            Programul presupune că rezultatul încape în long long.
 * Complexitate: O(log n)
 *
 * Exemplu
 * Intrare: 2 62
 * Ieșire: 4611686018427387904
 *
 * Exemplu
 * Intrare: 3 13
 * Ieșire: 1594323
 *
 * Exemplu
 * Intrare: 5 0
 * Ieșire: 1
 */
#include <iostream>
using namespace std;

long long putere(long long baza, long long exponent)
{
    long long rezultat = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            rezultat = rezultat * baza;
        exponent = exponent / 2;
        if (exponent > 0) // evităm o ridicare la pătrat inutilă, care ar putea depăși
            baza = baza * baza;
    }
    return rezultat;
}

int main()
{
    long long a, n;
    cin >> a >> n;
    cout << putere(a, n) << '\n';
    return 0;
}
