/*
 * Titlu: Fișier — cel mai mare și cel mai mic număr format din cifre date
 * Clasa: 12
 * Capitol: Recapitulare pentru bacalaureat
 * Descriere: Cerința (tip subiectul III.3): fișierul date.in conține cel mult 10^6
 *            cifre separate prin spații. Folosind toate cifrele, fiecare o singură
 *            dată, afișați pe prima linie cel mai mare număr care se poate forma,
 *            iar pe a doua cel mai mic număr fără zerouri nesemnificative (dacă
 *            toate cifrele sunt 0, numărul este 0). Eficiența: nu sortăm cifrele;
 *            un vector de frecvență cu 10 poziții le numără la citire. Cel mai mare
 *            număr scrie cifrele de la 9 la 0, de câte ori apar. Cel mai mic începe
 *            cu cea mai mică cifră nenulă, continuă cu toate zerourile și apoi cu
 *            restul cifrelor crescător.
 * Complexitate: O(n) timp, O(10) memorie
 *
 * Exemplu
 * Intrare: 3 0 9 0 1 3
 * Ieșire:
 * 933100
 * 100339
 *
 * Exemplu
 * Intrare: 0 0 0
 * Ieșire:
 * 0
 * 0
 */
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream fin("date.in");
    int f[10] = {0}, c;
    while (fin >> c)
        f[c]++;

    int nenule = 0;
    for (int i = 1; i <= 9; i++)
        nenule += f[i];
    if (nenule == 0)
    {
        cout << "0\n0\n";
        return 0;
    }

    // cel mai mare număr
    for (int i = 9; i >= 0; i--)
        for (int k = 0; k < f[i]; k++)
            cout << i;
    cout << '\n';

    // cel mai mic număr: prima cifră nenulă minimă, apoi zerourile, apoi restul
    int prima = 1;
    while (f[prima] == 0)
        prima++;
    f[prima]--;
    cout << prima;
    for (int i = 0; i <= 9; i++)
        for (int k = 0; k < f[i]; k++)
            cout << i;
    cout << '\n';
    return 0;
}
