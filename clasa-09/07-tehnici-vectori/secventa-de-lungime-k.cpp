/*
 * Titlu: Secvența de lungime k cu suma maximă
 * Clasa: 9
 * Capitol: Frecvență, sume parțiale și ciurul lui Eratostene
 * Descriere: Fereastra glisantă: calculăm suma primelor k elemente, apoi
 *            mutăm fereastra cu câte o poziție la dreapta: adăugăm elementul care
 *            intră (v[i]) și scădem elementul care iese (v[i - k]). Fiecare
 *            fereastră nouă costă O(1). Se citesc n și k, apoi vectorul; se
 *            afișează suma maximă și poziția de început a primei ferestre maxime.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 7 3
 * 1 5 2 8 1 9 0
 * Ieșire: 18 4
 */
#include <iostream>
using namespace std;

int v[100001];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    long long suma = 0;
    for (int i = 1; i <= k; i++)
    {
        suma = suma + v[i];
    }
    long long sumaMax = suma;
    int inceput = 1;
    for (int i = k + 1; i <= n; i++)
    {
        suma = suma + v[i] - v[i - k];
        if (suma > sumaMax)
        {
            sumaMax = suma;
            inceput = i - k + 1;
        }
    }
    cout << sumaMax << ' ' << inceput << '\n';
    return 0;
}
