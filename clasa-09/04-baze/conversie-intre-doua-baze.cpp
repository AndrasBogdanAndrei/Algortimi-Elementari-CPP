/*
 * Titlu: Conversia între două baze oarecare
 * Clasa: 9
 * Capitol: Baze de numerație
 * Descriere: Trecem prin baza 10: întâi transformăm numărul din baza b1 în
 *            baza 10 (schema lui Horner), apoi din baza 10 în baza b2 (împărțiri
 *            repetate). Se citesc numărul (ca text), b1 și b2, cu 2 <= b1, b2 <= 16.
 * Complexitate: O(k1 + k2), unde k1, k2 sunt numerele de cifre în cele două baze
 *
 * Exemplu
 * Intrare: FF 16 2
 * Ieșire: 11111111
 *
 * Exemplu
 * Intrare: 1202 3 5
 * Ieșire: 142
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int b1, b2;
    const string CIFRE = "0123456789ABCDEF";
    cin >> s >> b1 >> b2;
    long long n = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        int cifra = (int)CIFRE.find(s[i]);
        n = n * b1 + cifra;
    }
    string rez = "";
    do
    {
        rez = CIFRE[n % b2] + rez;
        n = n / b2;
    }
    while (n > 0);
    cout << rez << '\n';
    return 0;
}
