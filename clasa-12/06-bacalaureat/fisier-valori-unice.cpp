/*
 * Titlu: Fișier — valorile care apar o singură dată
 * Clasa: 12
 * Capitol: Recapitulare pentru bacalaureat
 * Descriere: Cerința (tip subiectul III.3): fișierul date.in conține cel mult 10^6
 *            numere naturale de cel mult trei cifre, separate prin spații. Afișați
 *            pe ecran, în ordine crescătoare, valorile care apar exact o dată în
 *            fișier, sau „nu exista”. Eficiența: nu memorăm șirul și nu îl sortăm.
 *            Cum valorile sunt între 0 și 999, un vector de frecvență f[1000]
 *            numără aparițiile la citire (O(1) pe număr), apoi parcurgerea
 *            vectorului de la 0 la 999 dă direct ordinea crescătoare. Memoria
 *            folosită nu depinde de câte numere sunt în fișier.
 * Complexitate: O(n + 1000) timp, O(1000) memorie
 *
 * Exemplu
 * Intrare: 5 12 7 5 300 12 999 0 0
 * Ieșire: 7 300 999
 *
 * Exemplu
 * Intrare: 4 4 4
 * Ieșire: nu exista
 */
#include <fstream>
#include <iostream>
using namespace std;

int f[1000];

int main()
{
    ifstream fin("date.in");
    int x;
    while (fin >> x)
        f[x]++;
    bool gasit = false;
    for (int v = 0; v < 1000; v++)
        if (f[v] == 1)
        {
            cout << v << ' ';
            gasit = true;
        }
    if (!gasit)
        cout << "nu exista";
    cout << '\n';
    return 0;
}
