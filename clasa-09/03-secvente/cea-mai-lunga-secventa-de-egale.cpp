/*
 * Titlu: Cea mai lungă secvență de elemente egale
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: O secvență înseamnă elemente aflate pe poziții consecutive.
 *            lung este lungimea secvenței curente: crește când numărul nou este
 *            egal cu cel anterior și revine la 1 când este diferit. După fiecare
 *            pas actualizăm lungimea maximă și valoarea care o formează.
 *            Se afișează lungimea maximă și valoarea (prima, la egalitate).
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 10
 * 1 1 2 2 2 3 2 2 2 2
 * Ieșire: 4 2
 */
#include <iostream>
using namespace std;

int main()
{
    int n, lung = 1, lungMax = 1;
    long long ant, x, valoare;
    cin >> n >> ant;
    valoare = ant;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        if (x == ant)
        {
            lung++;
        }
        else
        {
            lung = 1;
        }
        if (lung > lungMax)
        {
            lungMax = lung;
            valoare = x;
        }
        ant = x;
    }
    cout << lungMax << ' ' << valoare << '\n';
    return 0;
}
