/*
 * Titlu: Coada implementată cu o listă înlănțuită
 * Clasa: 11
 * Capitol: Alocare dinamică: liste, stive, cozi
 * Descriere: Coada se ține ca o listă simplu înlănțuită cu doi pointeri: prim (de unde se
 *            scoate) și ultim (unde se adaugă). push leagă un nod nou după ultim; pop mută
 *            prim pe nodul următor și eliberează nodul vechi. Când coada se golește, și
 *            ultim devine NULL. Operațiile sunt „push x”, „pop” și „front”; la coadă vidă
 *            se afișează „Coada vida”. La final se afișează elementele rămase.
 * Complexitate: O(1) pentru fiecare operație
 *
 * Exemplu
 * Intrare:
 * 8
 * push 2
 * push 6
 * pop
 * front
 * pop
 * pop
 * push 3
 * push 5
 * Ieșire:
 * 6
 * Coada vida
 * Ramase: 3 5
 */
#include <iostream>
#include <string>
using namespace std;

struct nod
{
    int info;
    nod *urm;
};

nod *prim = NULL, *ultim = NULL;

void push(int x)
{
    nod *p = new nod;
    p->info = x;
    p->urm = NULL;
    if (ultim == NULL)
    {
        prim = ultim = p;
    }
    else
    {
        ultim->urm = p;
        ultim = p;
    }
}

void pop()
{
    nod *p = prim;
    prim = prim->urm;
    if (prim == NULL)
    {
        ultim = NULL;
    }
    delete p;
}

int main()
{
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            push(x);
        }
        else if (prim == NULL)
        {
            cout << "Coada vida\n";
        }
        else if (op == "pop")
        {
            pop();
        }
        else
        {
            cout << prim->info << '\n';
        }
    }
    cout << "Ramase:";
    while (prim != NULL)
    {
        cout << ' ' << prim->info;
        pop();
    }
    cout << '\n';
    return 0;
}
