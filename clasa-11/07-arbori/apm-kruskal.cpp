/*
 * Titlu: Arborele parțial de cost minim (algoritmul lui Kruskal)
 * Clasa: 11
 * Capitol: Arbori
 * Descriere: Kruskal construiește arborele parțial de cost minim pornind de la n arbori cu
 *            câte un singur nod. Sortăm muchiile crescător după cost (la egalitate rămân în
 *            ordinea citirii) și le parcurgem: o muchie se alege dacă unește doi arbori
 *            diferiți, altfel ar închide un ciclu și se sare peste ea. Fiecare nod are o
 *            etichetă de arbore; când unim doi arbori, toate nodurile cu eticheta unuia o
 *            primesc pe a celuilalt. Ne oprim după n - 1 muchii alese.
 * Complexitate: O(m log m + n²) în această variantă
 *
 * Exemplu
 * Intrare:
 * 6 9
 * 1 2 4
 * 1 3 4
 * 2 3 2
 * 3 4 3
 * 3 5 2
 * 3 6 4
 * 4 6 3
 * 5 6 3
 * 2 4 5
 * Ieșire:
 * Cost: 14
 * 2 3 2
 * 3 5 2
 * 3 4 3
 * 4 6 3
 * 1 2 4
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct muchie
{
    int x, y, cost;
};

muchie e[10005];
int eticheta[105];

bool maiIeftina(const muchie &a, const muchie &b)
{
    return a.cost < b.cost;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> e[i].x >> e[i].y >> e[i].cost;
    }
    stable_sort(e, e + m, maiIeftina);
    for (int i = 1; i <= n; i++)
    {
        eticheta[i] = i;
    }

    int total = 0, alese = 0;
    muchie arbore[105];
    for (int i = 0; i < m && alese < n - 1; i++)
    {
        int ex = eticheta[e[i].x], ey = eticheta[e[i].y];
        if (ex != ey)
        {
            arbore[alese++] = e[i];
            total += e[i].cost;
            for (int j = 1; j <= n; j++)
            {
                if (eticheta[j] == ey)
                {
                    eticheta[j] = ex;
                }
            }
        }
    }

    if (alese < n - 1)
    {
        cout << "Graful nu este conex\n";
        return 0;
    }
    cout << "Cost: " << total << '\n';
    for (int i = 0; i < alese; i++)
    {
        cout << arbore[i].x << ' ' << arbore[i].y << ' ' << arbore[i].cost << '\n';
    }
    return 0;
}
