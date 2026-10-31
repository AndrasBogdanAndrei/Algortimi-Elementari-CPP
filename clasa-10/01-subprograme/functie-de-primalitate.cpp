/*
 * Titlu: Funcție de primalitate
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: Scriem o singură dată funcția estePrim(x), care întoarce true dacă
 *            x este prim, și o apelăm pentru fiecare număr citit. Funcția caută
 *            un divizor d între 2 și radical din x (condiția d * d <= x); dacă
 *            găsește unul, iese imediat cu return false. Numerele 0 și 1 nu sunt prime.
 *            Se citesc n și apoi n numere naturale; se afișează cele prime.
 * Complexitate: O(n * sqrt(M)), unde M este cea mai mare valoare citită
 *
 * Exemplu
 * Intrare:
 * 6
 * 2 9 13 1 17 20
 * Ieșire: 2 13 17
 *
 * Exemplu
 * Intrare:
 * 4
 * 97 100 0 101
 * Ieșire: 97 101
 */
#include <iostream>
using namespace std;

// Întoarce true dacă x este număr prim.
bool estePrim(int x)
{
    if (x < 2)
        return false;
    for (int d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (estePrim(x))
            cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
