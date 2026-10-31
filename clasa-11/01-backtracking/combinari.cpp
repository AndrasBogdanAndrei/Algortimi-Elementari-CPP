/*
 * Titlu: Generarea combinărilor
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Afișează toate submulțimile cu k elemente ale mulțimii {1, ..., n}
 *            (combinări de n luate câte k). Ca să nu obținem aceeași submulțime de mai
 *            multe ori, elementele se generează în ordine strict crescătoare: pe poziția
 *            poz încercăm doar valori mai mari decât x[poz - 1] și cel mult n - (k - poz),
 *            ca să mai rămână loc pentru elementele următoare. Numărul lor este
 *            C(n, k) = n! / (k! · (n - k)!).
 * Complexitate: O(C(n, k) · k) timp, O(k) memorie
 *
 * Exemplu
 * Intrare: 4 2
 * Ieșire:
 * 1 2
 * 1 3
 * 1 4
 * 2 3
 * 2 4
 * 3 4
 */
#include <iostream>
using namespace std;

int n, k, x[20];

void afiseaza()
{
    for (int i = 1; i <= k; i++)
    {
        cout << x[i] << ' ';
    }
    cout << '\n';
}

void back(int poz)
{
    // x[0] = 0, deci pe prima poziție pornim de la 1
    for (int v = x[poz - 1] + 1; v <= n - (k - poz); v++)
    {
        x[poz] = v;
        if (poz == k)
        {
            afiseaza();
        }
        else
        {
            back(poz + 1);
        }
    }
}

int main()
{
    cin >> n >> k;
    back(1);
    return 0;
}
