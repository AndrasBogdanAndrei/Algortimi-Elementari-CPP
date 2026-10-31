/*
 * Titlu: Parcurgerile unui arbore binar
 * Clasa: 11
 * Capitol: Arbori
 * Descriere: Într-un arbore binar fiecare nod are cel mult doi fii: unul stâng și unul drept.
 *            Îl memorăm prin vectorii st[i] și dr[i] (0 dacă fiul lipsește). Rădăcina este
 *            singurul nod care nu e fiul nimănui. Cele trei parcurgeri diferă doar prin
 *            momentul în care afișăm rădăcina subarborelui: preordine = rădăcină, stânga,
 *            dreapta (RSD); inordine = stânga, rădăcină, dreapta (SRD); postordine = stânga,
 *            dreapta, rădăcină (SDR). Datele: n, apoi pentru fiecare nod i perechea st[i] dr[i].
 * Complexitate: O(n) pentru fiecare parcurgere
 *
 * Exemplu
 * Intrare:
 * 7
 * 2 3
 * 4 5
 * 0 6
 * 0 0
 * 7 0
 * 0 0
 * 0 0
 * Ieșire:
 * Preordine: 1 2 4 5 7 3 6
 * Inordine: 4 2 7 5 1 3 6
 * Postordine: 4 7 5 2 6 3 1
 */
#include <iostream>
using namespace std;

int st[100005], dr[100005];
bool esteFiu[100005];

void preordine(int x)
{
    if (x == 0)
    {
        return;
    }
    cout << ' ' << x;
    preordine(st[x]);
    preordine(dr[x]);
}

void inordine(int x)
{
    if (x == 0)
    {
        return;
    }
    inordine(st[x]);
    cout << ' ' << x;
    inordine(dr[x]);
}

void postordine(int x)
{
    if (x == 0)
    {
        return;
    }
    postordine(st[x]);
    postordine(dr[x]);
    cout << ' ' << x;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> st[i] >> dr[i];
        esteFiu[st[i]] = true;
        esteFiu[dr[i]] = true;
    }
    int radacina = 1;
    while (esteFiu[radacina])
    {
        radacina++;
    }

    cout << "Preordine:";
    preordine(radacina);
    cout << "\nInordine:";
    inordine(radacina);
    cout << "\nPostordine:";
    postordine(radacina);
    cout << '\n';
    return 0;
}
