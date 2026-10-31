/*
 * Titlu: Arbore binar de căutare: inserare, căutare, afișare sortată
 * Clasa: 11
 * Capitol: Arbori
 * Descriere: Într-un arbore binar de căutare, pentru fiecare nod, toate valorile din
 *            subarborele stâng sunt mai mici decât valoarea nodului, iar cele din subarborele
 *            drept sunt mai mari. Inserarea coboară din rădăcină: la stânga dacă valoarea e mai
 *            mică, la dreapta dacă e mai mare, până găsește un loc liber (valorile deja
 *            existente nu se mai inserează). Căutarea urmează același drum. Parcurgerea în
 *            inordine afișează valorile sortate crescător. Nodurile sunt alocate cu new.
 *            Datele: n, cele n valori, apoi valoarea x căutată.
 * Complexitate: O(h) pentru inserare și căutare (h = înălțimea), O(n) pentru afișare
 *
 * Exemplu
 * Intrare:
 * 7
 * 50 30 70 20 40 60 80
 * 60
 * Ieșire:
 * Inordine: 20 30 40 50 60 70 80
 * Preordine: 50 30 20 40 70 60 80
 * Inaltime: 2
 * Gasit: DA
 *
 * Exemplu
 * Intrare:
 * 5
 * 3 1 4 1 5
 * 2
 * Ieșire:
 * Inordine: 1 3 4 5
 * Preordine: 3 1 4 5
 * Inaltime: 2
 * Gasit: NU
 */
#include <iostream>
using namespace std;

struct nod
{
    int info;
    nod *st, *dr;
};

void insereaza(nod *&r, int x)
{
    if (r == NULL)
    {
        r = new nod;
        r->info = x;
        r->st = r->dr = NULL;
    }
    else if (x < r->info)
    {
        insereaza(r->st, x);
    }
    else if (x > r->info)
    {
        insereaza(r->dr, x);
    }
}

bool cauta(nod *r, int x)
{
    while (r != NULL)
    {
        if (x == r->info)
        {
            return true;
        }
        r = (x < r->info ? r->st : r->dr);
    }
    return false;
}

void inordine(nod *r)
{
    if (r != NULL)
    {
        inordine(r->st);
        cout << ' ' << r->info;
        inordine(r->dr);
    }
}

void preordine(nod *r)
{
    if (r != NULL)
    {
        cout << ' ' << r->info;
        preordine(r->st);
        preordine(r->dr);
    }
}

// înălțimea = numărul de muchii de pe cel mai lung drum rădăcină-frunză
int inaltime(nod *r)
{
    if (r == NULL)
    {
        return -1;
    }
    return 1 + max(inaltime(r->st), inaltime(r->dr));
}

void sterge(nod *r)
{
    if (r != NULL)
    {
        sterge(r->st);
        sterge(r->dr);
        delete r;
    }
}

int main()
{
    int n, x;
    nod *radacina = NULL;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int v;
        cin >> v;
        insereaza(radacina, v);
    }
    cin >> x;

    cout << "Inordine:";
    inordine(radacina);
    cout << "\nPreordine:";
    preordine(radacina);
    cout << "\nInaltime: " << inaltime(radacina) << '\n';
    cout << "Gasit: " << (cauta(radacina, x) ? "DA" : "NU") << '\n';
    sterge(radacina);
    return 0;
}
