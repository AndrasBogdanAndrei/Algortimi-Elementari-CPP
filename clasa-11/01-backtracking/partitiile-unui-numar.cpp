/*
 * Titlu: Partițiile unui număr natural
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Afișează toate modurile de a scrie n ca sumă de numere naturale nenule,
 *            fără să conteze ordinea termenilor. Ca să nu repetăm aceeași descompunere,
 *            termenii se generează în ordine crescătoare (x[k] ≥ x[k - 1]). Ținem cât a
 *            rămas din n: un termen e valid dacă nu depășește restul, iar soluția e
 *            completă când restul devine 0.
 * Complexitate: proporțională cu numărul de partiții (crește exponențial cu n)
 *
 * Exemplu
 * Intrare: 4
 * Ieșire:
 * 1+1+1+1
 * 1+1+2
 * 1+3
 * 2+2
 * 4
 */
#include <iostream>
using namespace std;

int n, x[100];

void afiseaza(int lungime)
{
    for (int i = 1; i <= lungime; i++)
    {
        if (i > 1)
        {
            cout << '+';
        }
        cout << x[i];
    }
    cout << '\n';
}

void back(int k, int ramas)
{
    // x[0] = 1, deci primul termen pornește de la 1
    for (int v = x[k - 1]; v <= ramas; v++)
    {
        x[k] = v;
        if (v == ramas)
        {
            afiseaza(k);
        }
        else
        {
            back(k + 1, ramas - v);
        }
    }
}

int main()
{
    cin >> n;
    x[0] = 1;
    back(1, n);
    return 0;
}
