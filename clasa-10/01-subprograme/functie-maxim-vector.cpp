/*
 * Titlu: Funcție cu vector ca parametru (maximul)
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: Un vector se transmite unei funcții împreună cu numărul de elemente:
 *            int maxim(int v[], int n). Funcția primește de fapt adresa primului
 *            element, deci lucrează direct pe vectorul din main (nu pe o copie).
 *            Avem și o funcție void citeste(int v[], int &n) care umple vectorul;
 *            n este transmis prin referință ca să ajungă valoarea citită în main.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 3 8 -2 8 1
 * Ieșire: 8
 *
 * Exemplu
 * Intrare:
 * 3
 * -5 -1 -9
 * Ieșire: -1
 */
#include <iostream>
using namespace std;

void citeste(int v[], int &n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
}

int maxim(int v[], int n)
{
    int mx = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > mx)
            mx = v[i];
    }
    return mx;
}

int main()
{
    int v[1000], n;
    citeste(v, n);
    cout << maxim(v, n) << '\n';
    return 0;
}
