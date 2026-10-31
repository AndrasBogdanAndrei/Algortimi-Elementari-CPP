/*
 * Titlu: Lista simplu înlănțuită: creare, afișare, adăugare
 * Clasa: 11
 * Capitol: Alocare dinamică: liste, stive, cozi
 * Descriere: Fiecare element al listei este un nod alocat dinamic (cu new), care reține
 *            o valoare (info) și adresa nodului următor (urm). Ținem adresa primului nod
 *            (prim) și a ultimului (ultim); ultimul nod are urm = NULL. Adăugarea la
 *            început leagă noul nod în fața lui prim; adăugarea la sfârșit îl leagă după
 *            ultim. Programul creează lista din n valori (adăugând la sfârșit), o afișează,
 *            apoi adaugă x la început și y la sfârșit și o afișează din nou. La final
 *            memoria se eliberează cu delete.
 * Complexitate: O(1) pentru fiecare adăugare, O(n) pentru afișare
 *
 * Exemplu
 * Intrare:
 * 4
 * 3 8 1 5
 * 7 9
 * Ieșire:
 * 3 8 1 5
 * 7 3 8 1 5 9
 */
#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *urm;
};

nod *prim = NULL, *ultim = NULL;

void adaugaSfarsit(int x)
{
    nod *p = new nod;
    p->info = x;
    p->urm = NULL;
    if (prim == NULL)
    {
        prim = ultim = p;
    }
    else
    {
        ultim->urm = p;
        ultim = p;
    }
}

void adaugaInceput(int x)
{
    nod *p = new nod;
    p->info = x;
    p->urm = prim;
    prim = p;
    if (ultim == NULL)
    {
        ultim = p;
    }
}

void afiseaza()
{
    for (nod *p = prim; p != NULL; p = p->urm)
    {
        cout << p->info << ' ';
    }
    cout << '\n';
}

void elibereaza()
{
    while (prim != NULL)
    {
        nod *p = prim;
        prim = prim->urm;
        delete p;
    }
    ultim = NULL;
}

int main()
{
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        adaugaSfarsit(v);
    }
    afiseaza();
    cin >> x >> y;
    adaugaInceput(x);
    adaugaSfarsit(y);
    afiseaza();
    elibereaza();
    return 0;
}
