/*
 * Titlu: Vectorul de frecvență
 * Clasa: 9
 * Capitol: Frecvență, sume parțiale și ciurul lui Eratostene
 * Descriere: Pentru valori naturale mici (aici 0..1000), frecv[x] reține de câte
 *            ori a apărut valoarea x. Valoarea devine indice, așa că fiecare
 *            număr citit se numără într-un singur pas. La final aflăm valoarea
 *            care apare cel mai des (cea mai mică, la egalitate) și frecvența ei.
 * Complexitate: O(n + V), unde V este valoarea maximă posibilă
 *
 * Exemplu
 * Intrare:
 * 8
 * 3 7 3 1 7 3 9 1
 * Ieșire: 3 3
 */
#include <iostream>
using namespace std;

const int VMAX = 1000;
int frecv[VMAX + 1];

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        frecv[x]++;
    }
    int valoare = 0;
    for (int val = 1; val <= VMAX; val++)
    {
        if (frecv[val] > frecv[valoare])
        {
            valoare = val;
        }
    }
    cout << valoare << ' ' << frecv[valoare] << '\n';
    return 0;
}
