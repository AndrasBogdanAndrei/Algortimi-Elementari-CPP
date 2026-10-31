/*
 * Titlu: Sortarea prin metoda bulelor
 * Clasa: 9
 * Capitol: Sortare și căutare
 * Descriere: Parcurgem vectorul și interschimbăm oricare două elemente vecine
 *            aflate în ordine greșită (v[i] > v[i + 1]). După fiecare parcurgere,
 *            cel mai mare element rămas ajunge la capăt, ca o bulă care urcă.
 *            Repetăm cât timp la parcurgerea anterioară a avut loc cel puțin o
 *            interschimbare (variabila sortat).
 * Complexitate: O(n²) în cazul cel mai rău, O(n) dacă vectorul e deja sortat
 *
 * Exemplu
 * Intrare:
 * 6
 * 5 2 9 1 5 6
 * Ieșire: 1 2 5 5 6 9
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
    bool sortat;
    int sfarsit = n;
    do
    {
        sortat = true;
        for (int i = 1; i < sfarsit; i++)
        {
            if (v[i] > v[i + 1])
            {
                int aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sortat = false;
            }
        }
        sfarsit--;
    }
    while (!sortat);
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
