/*
 * Titlu: Prima poziție cu valoare mai mare sau egală cu x
 * Clasa: 9
 * Capitol: Sortare și căutare
 * Descriere: Varianta de căutare binară care nu se oprește la prima potrivire:
 *            într-un vector sortat crescător, căutăm cea mai mică poziție p cu
 *            v[p] >= x. Dacă v[mij] >= x, mij este un candidat (îl reținem și
 *            căutăm mai la stânga); altfel răspunsul este în dreapta. Dacă toate
 *            valorile sunt mai mici decât x, răspunsul este n + 1.
 * Complexitate: O(log n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 1 3 3 5 8 13
 * 4
 * Ieșire: 4
 *
 * Exemplu
 * Intrare:
 * 6
 * 1 3 3 5 8 13
 * 3
 * Ieșire: 2
 */
#include <iostream>
using namespace std;

int v[100001];

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cin >> x;
    int st = 1, dr = n, rez = n + 1;
    while (st <= dr)
    {
        int mij = (st + dr) / 2;
        if (v[mij] >= x)
        {
            rez = mij;
            dr = mij - 1;
        }
        else
        {
            st = mij + 1;
        }
    }
    cout << rez << '\n';
    return 0;
}
