/*
 * Titlu: Verificarea unui lanț
 * Clasa: 11
 * Capitol: Grafuri neorientate
 * Descriere: O succesiune de noduri x1, x2, ..., xk este lanț dacă oricare două noduri
 *            consecutive sunt unite printr-o muchie; lungimea lanțului este k - 1 (numărul
 *            de muchii). Lanțul este elementar dacă nodurile sunt distincte și simplu dacă
 *            muchiile folosite sunt distincte (orice lanț elementar este și simplu). Se
 *            verifică pe rând: muchiile consecutive, apoi nodurile repetate (vector de
 *            frecvență), apoi muchiile repetate (o matrice de muchii folosite). Datele:
 *            n m, cele m muchii, apoi k și cele k noduri.
 * Complexitate: O(n² + k)
 *
 * Exemplu
 * Intrare:
 * 5 6
 * 1 2
 * 2 3
 * 3 4
 * 4 1
 * 2 5
 * 4 5
 * 5
 * 1 2 5 4 3
 * Ieșire:
 * Lant de lungime 4
 * Elementar: DA
 * Simplu: DA
 *
 * Exemplu
 * Intrare:
 * 5 6
 * 1 2
 * 2 3
 * 3 4
 * 4 1
 * 2 5
 * 4 5
 * 6
 * 2 1 4 5 2 3
 * Ieșire:
 * Lant de lungime 5
 * Elementar: NU
 * Simplu: DA
 *
 * Exemplu
 * Intrare:
 * 5 6
 * 1 2
 * 2 3
 * 3 4
 * 4 1
 * 2 5
 * 4 5
 * 3
 * 1 3 4
 * Ieșire: Nu este lant
 */
#include <iostream>
using namespace std;

int a[105][105], x[1005], aparitii[105];
bool folosita[105][105];

int main()
{
    int n, m, k;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u][v] = a[v][u] = 1;
    }
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> x[i];
    }

    for (int i = 1; i < k; i++)
    {
        if (a[x[i]][x[i + 1]] == 0)
        {
            cout << "Nu este lant\n";
            return 0;
        }
    }

    bool elementar = true, simplu = true;
    for (int i = 1; i <= k; i++)
    {
        aparitii[x[i]]++;
        if (aparitii[x[i]] > 1)
        {
            elementar = false;
        }
    }
    for (int i = 1; i < k; i++)
    {
        int u = x[i], v = x[i + 1];
        if (folosita[u][v])
        {
            simplu = false;
        }
        folosita[u][v] = folosita[v][u] = true;
    }

    cout << "Lant de lungime " << k - 1 << '\n';
    cout << "Elementar: " << (elementar ? "DA" : "NU") << '\n';
    cout << "Simplu: " << (simplu ? "DA" : "NU") << '\n';
    return 0;
}
