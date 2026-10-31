/*
 * Titlu: Sortarea după două criterii
 * Clasa: 9
 * Capitol: Sortare și căutare
 * Descriere: Ordonăm numerele crescător după ultima cifră, iar numerele cu
 *            aceeași ultimă cifră descrescător după valoare. Algoritmul de
 *            sortare rămâne același (aici comparăm fiecare v[i] cu toate v[j] de
 *            după el); se schimbă doar condiția care spune când două elemente sunt în
 *            ordine greșită: ultima cifră mai mare, sau aceeași ultimă cifră și
 *            valoare mai mică.
 * Complexitate: O(n²)
 *
 * Exemplu
 * Intrare:
 * 7
 * 31 20 41 12 5 15 70
 * Ieșire: 70 20 41 31 12 15 5
 */
#include <iostream>
using namespace std;

int v[1001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int ci = v[i] % 10, cj = v[j] % 10;
            if (ci > cj || (ci == cj && v[i] < v[j]))
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
