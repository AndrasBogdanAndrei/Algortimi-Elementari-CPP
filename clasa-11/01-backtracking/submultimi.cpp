/*
 * Titlu: Generarea submulțimilor
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Afișează toate submulțimile nevide ale mulțimii {1, ..., n}, în ordine
 *            lexicografică. Elementele unei submulțimi se pun în ordine strict crescătoare
 *            (ca la combinări), dar fiecare soluție parțială este și ea o soluție: o afișăm
 *            imediat, apoi încercăm s-o prelungim. Există 2^n submulțimi, inclusiv
 *            mulțimea vidă (care aici nu se afișează).
 * Complexitate: O(2^n · n) timp, O(n) memorie
 *
 * Exemplu
 * Intrare: 3
 * Ieșire:
 * 1
 * 1 2
 * 1 2 3
 * 1 3
 * 2
 * 2 3
 * 3
 */
#include <iostream>
using namespace std;

int n, x[25];

void afiseaza(int lungime)
{
    for (int i = 1; i <= lungime; i++)
    {
        cout << x[i] << ' ';
    }
    cout << '\n';
}

void back(int poz)
{
    for (int v = x[poz - 1] + 1; v <= n; v++)
    {
        x[poz] = v;
        afiseaza(poz);
        back(poz + 1);
    }
}

int main()
{
    cin >> n;
    back(1);
    return 0;
}
