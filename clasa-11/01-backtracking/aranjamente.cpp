/*
 * Titlu: Generarea aranjamentelor
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Afișează, în ordine lexicografică, toate aranjamentele de n elemente luate
 *            câte k: șiruri de k valori distincte din {1, ..., n}, în care ordinea contează.
 *            Este schema de la permutări, dar soluția se oprește la lungimea k.
 *            Numărul lor este A(n, k) = n! / (n - k)!.
 * Complexitate: O(A(n, k) · k) timp, O(n) memorie
 *
 * Exemplu
 * Intrare: 3 2
 * Ieșire:
 * 1 2
 * 1 3
 * 2 1
 * 2 3
 * 3 1
 * 3 2
 */
#include <iostream>
using namespace std;

int n, k, x[20];
bool folosit[20];

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
    for (int v = 1; v <= n; v++)
    {
        if (!folosit[v])
        {
            x[poz] = v;
            folosit[v] = true;
            if (poz == k)
            {
                afiseaza();
            }
            else
            {
                back(poz + 1);
            }
            folosit[v] = false;
        }
    }
}

int main()
{
    cin >> n >> k;
    back(1);
    return 0;
}
