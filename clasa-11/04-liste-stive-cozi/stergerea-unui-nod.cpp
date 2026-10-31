/*
 * Titlu: Ștergerea nodurilor dintr-o listă simplu înlănțuită
 * Clasa: 11
 * Capitol: Alocare dinamică: liste, stive, cozi
 * Descriere: Se creează o listă din n valori, apoi se șterg toate nodurile care conțin
 *            valoarea x. Ștergerea primului nod mută pointerul prim pe nodul următor.
 *            Pentru un nod din interior avem nevoie de nodul dinaintea lui (q): legăm
 *            q->urm direct de nodul de după cel șters, apoi eliberăm memoria nodului șters
 *            cu delete. Se afișează lista rămasă sau „Lista vida”.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 4 2 7 2 2 9
 * 2
 * Ieșire: 4 7 9
 *
 * Exemplu
 * Intrare:
 * 2
 * 5 5
 * 5
 * Ieșire: Lista vida
 */
#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
};

nod *prim = NULL;

void adaugaSfarsit(nod *&ultim, int x)
{
    nod *p = new nod;
    p->info = x;
    p->urm = NULL;
    if (prim == NULL)
    {
        prim = p;
    }
    else
    {
        ultim->urm = p;
    }
    ultim = p;
}

void stergeValoare(int x)
{
    // întâi ștergem de la începutul listei, cât timp primul nod are valoarea x
    while (prim != NULL && prim->info == x)
    {
        nod *p = prim;
        prim = prim->urm;
        delete p;
    }
    if (prim == NULL)
    {
        return;
    }
    // q este mereu un nod păstrat; verificăm nodul de după el
    nod *q = prim;
    while (q->urm != NULL)
    {
        if (q->urm->info == x)
        {
            nod *p = q->urm;
            q->urm = p->urm;
            delete p;
        }
        else
        {
            q = q->urm;
        }
    }
}

int main()
{
    int n, x;
    nod *ultim = NULL;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        adaugaSfarsit(ultim, v);
    }
    cin >> x;
    stergeValoare(x);

    if (prim == NULL)
    {
        cout << "Lista vida\n";
    }
    else
    {
        for (nod *p = prim; p != NULL; p = p->urm)
        {
            cout << p->info << ' ';
        }
        cout << '\n';
    }
    while (prim != NULL)
    {
        nod *p = prim;
        prim = prim->urm;
        delete p;
    }
    return 0;
}
