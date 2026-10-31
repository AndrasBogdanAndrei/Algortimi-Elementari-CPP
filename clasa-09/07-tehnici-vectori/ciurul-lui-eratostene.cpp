/*
 * Titlu: Ciurul lui Eratostene
 * Clasa: 9
 * Capitol: Frecvență, sume parțiale și ciurul lui Eratostene
 * Descriere: Găsește toate numerele prime până la n. Pornim cu toate numerele
 *            nemarcate; pentru fiecare i nemarcat (deci prim) marcăm ca neprimi
 *            multiplii lui, începând de la i * i (multiplii mai mici au fost deja
 *            marcați de factori mai mici). Ajunge să mergem cu i cât timp i * i <= n.
 *            ciur[x] = true înseamnă că x NU este prim.
 * Complexitate: O(n log log n)
 *
 * Exemplu
 * Intrare: 30
 * Ieșire: 2 3 5 7 11 13 17 19 23 29
 */
#include <iostream>
using namespace std;

const int NMAX = 1000000;
bool ciur[NMAX + 1];

int main()
{
    int n;
    cin >> n;
    ciur[0] = ciur[1] = true;
    for (int i = 2; i * i <= n; i++)
    {
        if (!ciur[i])
        {
            for (int j = i * i; j <= n; j = j + i)
            {
                ciur[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (!ciur[i])
        {
            cout << i << ' ';
        }
    }
    cout << '\n';
    return 0;
}
