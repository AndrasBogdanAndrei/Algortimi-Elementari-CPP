/*
 * Titlu: Inserarea într-o listă ordonată
 * Clasa: 11
 * Capitol: Alocare dinamică: liste, stive, cozi
 * Descriere: Citim n numere și le inserăm pe rând într-o listă simplu înlănțuită păstrată
 *            mereu în ordine crescătoare. Dacă noua valoare este mai mică decât primul
 *            element (sau lista e vidă), noul nod devine primul. Altfel căutăm ultimul nod
 *            q a cărui valoare este cel mult x și legăm noul nod între q și q->urm.
 *            La final lista conține numerele sortate (este o sortare prin inserție pe listă).
 * Complexitate: O(n) pentru o inserare, O(n²) pentru toate
 *
 * Exemplu
 * Intrare:
 * 6
 * 5 2 8 2 1 9
 * Ieșire: 1 2 2 5 8 9
 */
#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
};

nod *prim = NULL;

void insereaza(int x)
{
    nod *p = new nod;
    p->info = x;
    if (prim == NULL || x < prim->info)
    {
        p->urm = prim;
        prim = p;
        return;
    }
    nod *q = prim;
    while (q->urm != NULL && q->urm->info <= x)
    {
        q = q->urm;
    }
    p->urm = q->urm;
    q->urm = p;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        insereaza(v);
    }
    for (nod *p = prim; p != NULL; p = p->urm)
    {
        cout << p->info << ' ';
    }
    cout << '\n';
    while (prim != NULL)
    {
        nod *p = prim;
        prim = prim->urm;
        delete p;
    }
    return 0;
}
