/*
 * Titlu: Containerul vector din STL
 * Clasa: 12
 * Capitol: Structuri de date și STL
 * Descriere: vector<int> este un tablou care își gestionează singur memoria:
 *            push_back adaugă la final (în medie O(1)), size() dă numărul de
 *            elemente, iar v[i] accesează direct poziția i. Programul citește n
 *            valori, le afișează în ordine inversă, apoi obține valorile distincte
 *            sortate: sort le ordonează, unique mută duplicatele consecutive la
 *            final și întoarce un iterator spre începutul lor, iar erase le șterge.
 *            Ultima linie este numărul de valori distincte.
 * Complexitate: O(n log n), de la sortare
 *
 * Exemplu
 * Intrare:
 * 8
 * 5 3 9 3 1 5 5 7
 * Ieșire:
 * 7 5 5 1 3 9 3 5
 * 1 3 5 7 9
 * 5
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (int i = (int)v.size() - 1; i >= 0; i--)
        cout << v[i] << (i > 0 ? ' ' : '\n');

    vector<int> distincte = v; // o copie, ca să nu stricăm vectorul inițial
    sort(distincte.begin(), distincte.end());
    distincte.erase(unique(distincte.begin(), distincte.end()), distincte.end());
    for (int i = 0; i < (int)distincte.size(); i++)
        cout << distincte[i] << (i + 1 < (int)distincte.size() ? ' ' : '\n');
    cout << distincte.size() << '\n';
    return 0;
}
