/*
 * Titlu: Căutarea binară
 * Clasa: 9
 * Capitol: Sortare și căutare
 * Descriere: Funcționează doar pe un vector sortat crescător. Comparăm x cu
 *            elementul din mijlocul zonei [st, dr]: dacă e egal, am terminat;
 *            dacă x e mai mic, căutăm în stânga mijlocului, altfel în dreapta.
 *            La fiecare pas zona se înjumătățește. Se afișează o poziție pe care
 *            se află x sau NU.
 * Complexitate: O(log n)
 *
 * Exemplu
 * Intrare:
 * 8
 * 2 5 8 12 16 23 38 56
 * 23
 * Ieșire: 6
 *
 * Exemplu
 * Intrare:
 * 8
 * 2 5 8 12 16 23 38 56
 * 7
 * Ieșire: NU
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
    int st = 1, dr = n, poz = 0;
    while (st <= dr && poz == 0)
    {
        int mij = (st + dr) / 2;
        if (v[mij] == x)
        {
            poz = mij;
        }
        else if (x < v[mij])
        {
            dr = mij - 1;
        }
        else
        {
            st = mij + 1;
        }
    }
    if (poz != 0)
    {
        cout << poz << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
