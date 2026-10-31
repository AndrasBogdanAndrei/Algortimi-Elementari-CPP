/*
 * Titlu: set și map — frecvența cuvintelor
 * Clasa: 12
 * Capitol: Structuri de date și STL
 * Descriere: Citim cuvinte (litere mici) până la sfârșitul datelor. Un set<string>
 *            păstrează fiecare cuvânt o singură dată, în ordine alfabetică, deci
 *            size() dă numărul de cuvinte distincte. Un map<string, int> asociază
 *            fiecărui cuvânt un contor: frecventa[cuvant]++ creează intrarea cu 0
 *            dacă nu exista și apoi o crește. Ambele sunt arbori echilibrați:
 *            inserarea și căutarea costă O(log n) comparații de șiruri, iar
 *            parcurgerea le dă în ordine crescătoare a cheilor.
 * Complexitate: O(n log n) comparații de cuvinte, n = numărul de cuvinte
 *
 * Exemplu
 * Intrare:
 * ana are mere ana are pere
 * mere ana
 * Ieșire:
 * 4
 * ana 3
 * are 2
 * mere 2
 * pere 1
 */
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main()
{
    set<string> distincte;
    map<string, int> frecventa;
    string cuvant;
    while (cin >> cuvant)
    {
        distincte.insert(cuvant);
        frecventa[cuvant]++;
    }
    cout << distincte.size() << '\n';
    for (auto &p : frecventa)
        cout << p.first << ' ' << p.second << '\n';
    return 0;
}
