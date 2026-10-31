/*
 * Titlu: Generarea permutărilor
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Afișează, în ordine lexicografică, toate permutările mulțimii {1, 2, ..., n}.
 *            Soluția se construiește în vectorul x, poziție cu poziție. Pe poziția k
 *            încercăm pe rând valorile 1..n; o valoare este validă dacă nu a mai fost
 *            folosită (vectorul folosit). Când k ajunge la n avem o soluție completă,
 *            o afișăm și revenim (backtracking) la poziția anterioară.
 * Complexitate: O(n! · n) timp, O(n) memorie
 *
 * Exemplu
 * Intrare: 3
 * Ieșire:
 * 1 2 3
 * 1 3 2
 * 2 1 3
 * 2 3 1
 * 3 1 2
 * 3 2 1
 */
#include <iostream>
using namespace std;

int n, x[20];
bool folosit[20];

void afiseaza()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << ' ';
    }
    cout << '\n';
}

void back(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (!folosit[v])
        {
            x[k] = v;
            folosit[v] = true;
            if (k == n)
            {
                afiseaza();
            }
            else
            {
                back(k + 1);
            }
            folosit[v] = false;
        }
    }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}
