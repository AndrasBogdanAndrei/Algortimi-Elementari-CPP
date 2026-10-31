/*
 * Titlu: Stiva implementată cu o listă înlănțuită
 * Clasa: 11
 * Capitol: Alocare dinamică: liste, stive, cozi
 * Descriere: Vârful stivei este primul nod al unei liste simplu înlănțuite. push creează
 *            un nod nou și îl leagă în fața vârfului; pop mută vârful pe nodul următor și
 *            eliberează nodul vechi cu delete. Așa stiva nu are o dimensiune maximă fixată.
 *            Operațiile sunt „push x”, „pop” și „top”; la stivă vidă se afișează
 *            „Stiva vida”. La final se afișează elementele rămase, din vârf spre bază.
 * Complexitate: O(1) pentru fiecare operație
 *
 * Exemplu
 * Intrare:
 * 6
 * push 5
 * push 1
 * push 9
 * top
 * pop
 * push 4
 * Ieșire:
 * 9
 * Ramase: 4 1 5
 */
#include <iostream>
#include <string>
using namespace std;

struct nod
{
    int info;
    nod *urm;
};

nod *varf = NULL;

void push(int x)
{
    nod *p = new nod;
    p->info = x;
    p->urm = varf;
    varf = p;
}

void pop()
{
    nod *p = varf;
    varf = varf->urm;
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
        else if (varf == NULL)
        {
            cout << "Stiva vida\n";
        }
        else if (op == "pop")
        {
            pop();
        }
        else
        {
            cout << varf->info << '\n';
        }
    }
    cout << "Ramase:";
    while (varf != NULL)
    {
        cout << ' ' << varf->info;
        pop();
    }
    cout << '\n';
    return 0;
}
