/*
 * Titlu: Căutare binară recursivă
 * Clasa: 10
 * Capitol: Divide et impera
 * Descriere: Vectorul este sortat crescător. Comparăm x cu elementul din mijloc:
 *            dacă sunt egale am terminat; dacă x este mai mic, căutăm doar în
 *            jumătatea stângă, altfel doar în cea dreaptă. Spre deosebire de suma
 *            sau maximul prin divide et impera, aici rezolvăm o singură subproblemă
 *            la fiecare pas. Dacă porțiunea devine vidă (st > dr), x nu apare.
 *            Se afișează poziția lui x (numerotată de la 1) sau 0.
 * Complexitate: O(log n)
 *
 * Exemplu
 * Intrare:
 * 7
 * 1 3 5 7 9 11 13
 * 9
 * Ieșire: 5
 *
 * Exemplu
 * Intrare:
 * 7
 * 1 3 5 7 9 11 13
 * 4
 * Ieșire: 0
 */
#include <iostream>
using namespace std;

int v[100001];

int cauta(int st, int dr, int x)
{
    if (st > dr)
        return 0;
    int m = (st + dr) / 2;
    if (v[m] == x)
        return m;
    if (x < v[m])
        return cauta(st, m - 1, x);
    return cauta(m + 1, dr, x);
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    cin >> x;
    cout << cauta(1, n, x) << '\n';
    return 0;
}
