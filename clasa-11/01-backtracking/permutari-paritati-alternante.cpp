/*
 * Titlu: Permutări cu vecini de parități diferite
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Afișează permutările mulțimii {1, ..., n} în care oricare două elemente
 *            vecine au parități diferite (unul par, celălalt impar). Față de generarea
 *            permutărilor apare o condiție de continuare în plus: valoarea de pe poziția k
 *            trebuie să aibă altă paritate decât x[k - 1]. Verificând-o imediat, tăiem
 *            devreme ramurile care nu pot duce la soluții.
 * Complexitate: O(n! · n) în cel mai rău caz, practic mult mai puțin
 *
 * Exemplu
 * Intrare: 4
 * Ieșire:
 * 1 2 3 4
 * 1 4 3 2
 * 2 1 4 3
 * 2 3 4 1
 * 3 2 1 4
 * 3 4 1 2
 * 4 1 2 3
 * 4 3 2 1
 */
#include <iostream>
using namespace std;

int n, x[20];
bool folosit[20];

void back(int k)
{
    for (int v = 1; v <= n; v++)
    {
        if (!folosit[v] && (k == 1 || v % 2 != x[k - 1] % 2))
        {
            x[k] = v;
            folosit[v] = true;
            if (k == n)
            {
                for (int i = 1; i <= n; i++)
                {
                    cout << x[i] << ' ';
                }
                cout << '\n';
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
