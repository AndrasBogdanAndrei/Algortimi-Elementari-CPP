/*
 * Titlu: Marcarea intervalelor cu vectorul de diferențe
 * Clasa: 9
 * Capitol: Frecvență, sume parțiale și ciurul lui Eratostene
 * Descriere: Avem n poziții, inițial 0, și m operații „adună 1 pe pozițiile
 *            a..b”. În loc să parcurgem fiecare interval, notăm doar capetele:
 *            d[a]++ (de aici începe) și d[b + 1]-- (aici se termină). La final,
 *            sumele parțiale ale lui d dau valoarea fiecărei poziții.
 *            Se citesc n și m, apoi m perechi a b; se afișează cele n valori.
 * Complexitate: O(n + m), față de O(n · m) cu marcarea directă
 *
 * Exemplu
 * Intrare:
 * 6 3
 * 1 3
 * 2 5
 * 5 6
 * Ieșire: 1 2 2 1 2 1
 */
#include <iostream>
using namespace std;

int d[100002];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int a, b;
        cin >> a >> b;
        d[a]++;
        d[b + 1]--;
    }
    int valoare = 0;
    for (int i = 1; i <= n; i++)
    {
        valoare = valoare + d[i];
        cout << valoare << ' ';
    }
    cout << '\n';
    return 0;
}
