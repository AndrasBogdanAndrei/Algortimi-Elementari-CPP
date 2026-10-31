/*
 * Titlu: Păduri de mulțimi disjuncte (union-find)
 * Clasa: 12
 * Capitol: Structuri de date și STL
 * Descriere: Avem n elemente, fiecare inițial în propria mulțime. Operația 1 x y
 *            unește mulțimile lui x și y, iar operația 2 x y întreabă dacă x și y
 *            sunt în aceeași mulțime (DA / NU). Fiecare mulțime este un arbore
 *            memorat prin vectorul de tați; rădăcina este reprezentantul. Două
 *            optimizări fac operațiile aproape O(1): compresia drumului (după ce
 *            găsim rădăcina, legăm direct de ea toate nodurile parcurse) și
 *            unirea după rang (arborele mai scund se agață de cel mai înalt). La
 *            final afișăm câte mulțimi au rămas.
 * Complexitate: O((n + m) * α(n)), unde α crește atât de încet încât e practic constant
 *
 * Exemplu
 * Intrare:
 * 5 6
 * 1 1 2
 * 2 1 3
 * 1 3 4
 * 1 2 4
 * 2 1 3
 * 2 1 5
 * Ieșire:
 * NU
 * DA
 * NU
 * 2
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> tata, rang;

int radacina(int x)
{
    if (tata[x] != x)
        tata[x] = radacina(tata[x]); // compresia drumului
    return tata[x];
}

// Întoarce true dacă x și y erau în mulțimi diferite (și le-a unit).
bool uneste(int x, int y)
{
    int rx = radacina(x), ry = radacina(y);
    if (rx == ry)
        return false;
    if (rang[rx] < rang[ry])
        tata[rx] = ry;
    else if (rang[rx] > rang[ry])
        tata[ry] = rx;
    else
    {
        tata[ry] = rx;
        rang[rx]++;
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;
    tata.resize(n + 1);
    rang.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        tata[i] = i;
    int multimi = n;
    for (int i = 0; i < m; i++)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1)
        {
            if (uneste(x, y))
                multimi--;
        }
        else
            cout << (radacina(x) == radacina(y) ? "DA" : "NU") << '\n';
    }
    cout << multimi << '\n';
    return 0;
}
