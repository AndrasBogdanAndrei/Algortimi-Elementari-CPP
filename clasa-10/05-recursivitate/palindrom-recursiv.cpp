/*
 * Titlu: Palindrom recursiv
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Un cuvânt este palindrom dacă primul și ultimul caracter sunt egale și
 *            ce rămâne între ele este tot palindrom. Funcția palindrom(s, st, dr)
 *            lucrează pe porțiunea dintre indicii st și dr. Oprire: o porțiune cu
 *            cel mult un caracter (st >= dr) este palindrom; la prima pereche
 *            diferită răspunsul este false, fără alte autoapeluri.
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare: radar
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: rotund
 * Ieșire: NU
 */
#include <iostream>
#include <cstring>
using namespace std;

bool palindrom(char s[], int st, int dr)
{
    if (st >= dr)
        return true;
    if (s[st] != s[dr])
        return false;
    return palindrom(s, st + 1, dr - 1);
}

int main()
{
    char s[256];
    cin >> s;
    int n = strlen(s);
    cout << (palindrom(s, 0, n - 1) ? "DA" : "NU") << '\n';
    return 0;
}
