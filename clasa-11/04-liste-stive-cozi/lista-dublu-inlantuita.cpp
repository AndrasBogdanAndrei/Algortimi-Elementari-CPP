/*
 * Titlu: Lista dublu înlănțuită
 * Clasa: 11
 * Capitol: Alocare dinamică: liste, stive, cozi
 * Descriere: Într-o listă dublu înlănțuită fiecare nod reține atât adresa nodului următor
 *            (urm), cât și a celui anterior (ant), deci lista se poate parcurge în ambele
 *            sensuri. Programul creează lista din n valori, o afișează de la început spre
 *            sfârșit și invers, apoi șterge primul nod cu valoarea x și o afișează din nou
 *            în ambele sensuri. La ștergere trebuie refăcute două legături: vecinul din
 *            stânga trebuie să indice spre vecinul din dreapta și invers.
 * Complexitate: O(1) pentru adăugare la capete, O(n) pentru căutare și afișare
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 2 3 4 5
 * 3
 * Ieșire:
 * 1 2 3 4 5
 * 5 4 3 2 1
 * 1 2 4 5
 * 5 4 2 1
 */
#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *ant, *urm;
};

nod *prim = NULL, *ultim = NULL;

void adaugaSfarsit(int x)
{
    nod *p = new nod;
    p->info = x;
    p->urm = NULL;
    p->ant = ultim;
    if (ultim == NULL)
    {
        prim = p;
    }
    else
    {
        ultim->urm = p;
    }
    ultim = p;
}

void stergePrimul(int x)
{
    nod *p = prim;
    while (p != NULL && p->info != x)
    {
        p = p->urm;
    }
    if (p == NULL)
    {
        return;
    }
    if (p->ant != NULL)
    {
        p->ant->urm = p->urm;
    }
    else
    {
        prim = p->urm;
    }
    if (p->urm != NULL)
    {
        p->urm->ant = p->ant;
    }
    else
    {
        ultim = p->ant;
    }
    delete p;
}

void afiseazaInainte()
{
    for (nod *p = prim; p != NULL; p = p->urm)
    {
        cout << p->info << ' ';
    }
    cout << '\n';
}

void afiseazaInapoi()
{
    for (nod *p = ultim; p != NULL; p = p->ant)
    {
        cout << p->info << ' ';
    }
    cout << '\n';
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        adaugaSfarsit(v);
    }
    cin >> x;
    afiseazaInainte();
    afiseazaInapoi();
    stergePrimul(x);
    afiseazaInainte();
    afiseazaInapoi();
    while (prim != NULL)
    {
        nod *p = prim;
        prim = prim->urm;
        delete p;
    }
    return 0;
}
