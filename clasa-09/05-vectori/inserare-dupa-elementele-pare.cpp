/*
 * Titlu: Inserarea unei valori după fiecare element par
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: Parcurgem vectorul de la sfârșit spre început. Când v[i] este par,
 *            mutăm elementele de după el cu o poziție la dreapta și punem x pe
 *            poziția i + 1. Mergând de la capăt, elementele deja tratate se
 *            mută, dar nu ajung să fie verificate din nou. Valoarea x se inserează
 *            chiar dacă este și ea pară. Se citesc n, cele n elemente și x.
 * Complexitate: O(n²) în cazul cel mai rău (multe inserări)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 2 3 4 5
 * 0
 * Ieșire: 1 2 0 3 4 0 5
 */
#include <iostream>
using namespace std;

int v[2001];

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cin >> x;
    for (int i = n; i >= 1; i--)
    {
        if (v[i] % 2 == 0)
        {
            for (int j = n; j > i; j--)
            {
                v[j + 1] = v[j];
            }
            v[i + 1] = x;
            n++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
