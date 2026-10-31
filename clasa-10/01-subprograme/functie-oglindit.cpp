/*
 * Titlu: Funcție care întoarce oglinditul
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: Funcția oglindit(x) construiește numărul cu cifrele lui x în ordine
 *            inversă și îl întoarce cu return. Cu ajutorul ei, funcția palindrom(x)
 *            se scrie într-un singur rând: x este palindrom dacă este egal cu
 *            oglinditul său. Se afișează oglinditul și DA/NU pentru palindrom.
 * Complexitate: O(k), unde k este numărul de cifre ale lui x
 *
 * Exemplu
 * Intrare: 1221
 * Ieșire: 1221 DA
 *
 * Exemplu
 * Intrare: 1230
 * Ieșire: 321 NU
 */
#include <iostream>
using namespace std;

long long oglindit(long long x)
{
    long long ogl = 0;
    while (x > 0)
    {
        ogl = ogl * 10 + x % 10;
        x = x / 10;
    }
    return ogl;
}

bool palindrom(long long x)
{
    return x == oglindit(x);
}

int main()
{
    long long n;
    cin >> n;
    cout << oglindit(n) << ' ';
    if (palindrom(n))
        cout << "DA\n";
    else
        cout << "NU\n";
    return 0;
}
