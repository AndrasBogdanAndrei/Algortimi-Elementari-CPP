/*
 * Titlu: Noduri izolate și graful complet
 * Clasa: 11
 * Capitol: Grafuri neorientate
 * Descriere: Un nod izolat are gradul 0. Un graf este complet dacă oricare două noduri
 *            distincte sunt unite printr-o muchie; graful complet cu n noduri are
 *            n · (n - 1) / 2 muchii și fiecare nod are gradul n - 1. Programul calculează
 *            gradele, afișează nodurile izolate, spune dacă graful este complet și câte
 *            muchii ar mai trebui adăugate ca să devină complet.
 * Complexitate: O(n + m)
 *
 * Exemplu
 * Intrare:
 * 5 4
 * 1 2
 * 1 3
 * 2 3
 * 3 5
 * Ieșire:
 * Noduri izolate: 4
 * Complet: NU
 * Muchii lipsa: 6
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 1 2
 * 2 3
 * 1 3
 * Ieșire:
 * Noduri izolate: niciunul
 * Complet: DA
 * Muchii lipsa: 0
 */
#include <iostream>
using namespace std;

int grad[100005];

int main()
{
    long long n, m;
    cin >> n >> m;
    for (long long k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        grad[x]++;
        grad[y]++;
    }

    cout << "Noduri izolate:";
    bool exista = false;
    for (int i = 1; i <= n; i++)
    {
        if (grad[i] == 0)
        {
            cout << ' ' << i;
            exista = true;
        }
    }
    if (!exista)
    {
        cout << " niciunul";
    }
    cout << '\n';

    long long maxim = n * (n - 1) / 2;
    cout << "Complet: " << (m == maxim ? "DA" : "NU") << '\n';
    cout << "Muchii lipsa: " << maxim - m << '\n';
    return 0;
}
