/*
 * Titlu: Cmmdc-ul elementelor unui vector prin divide et impera
 * Clasa: 10
 * Capitol: Divide et impera
 * Descriere: Cmmdc-ul unei porțiuni este cmmdc-ul dintre cmmdc-ul jumătății stângi
 *            și cmmdc-ul jumătății drepte, pentru că cmmdc(a, b, c, d) =
 *            cmmdc(cmmdc(a, b), cmmdc(c, d)). Cazul elementar: un singur element.
 *            Pasul de combinare folosește algoritmul lui Euclid.
 * Complexitate: O(n log M), unde M este cea mai mare valoare
 *
 * Exemplu
 * Intrare:
 * 4
 * 12 18 24 30
 * Ieșire: 6
 *
 * Exemplu
 * Intrare:
 * 3
 * 7 14 9
 * Ieșire: 1
 */
#include <iostream>
using namespace std;

int v[1000];

int cmmdc(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int cmmdcVector(int st, int dr)
{
    if (st == dr)
        return v[st];
    int m = (st + dr) / 2;
    return cmmdc(cmmdcVector(st, m), cmmdcVector(m + 1, dr));
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << cmmdcVector(0, n - 1) << '\n';
    return 0;
}
