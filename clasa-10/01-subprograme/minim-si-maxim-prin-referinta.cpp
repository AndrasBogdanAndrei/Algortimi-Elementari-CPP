/*
 * Titlu: Minim și maxim întoarse prin referință
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: O funcție poate întoarce cu return o singură valoare. Când avem nevoie
 *            de mai multe rezultate, le punem ca parametri prin referință:
 *            void minMax(int v[], int n, int &mn, int &mx). Funcția scrie direct în
 *            variabilele din main. Afișăm minimul și maximul vectorului.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 4 -3 10 7 -3 2
 * Ieșire: -3 10
 *
 * Exemplu
 * Intrare:
 * 1
 * 42
 * Ieșire: 42 42
 */
#include <iostream>
using namespace std;

void minMax(int v[], int n, int &mn, int &mx)
{
    mn = mx = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] < mn)
            mn = v[i];
        if (v[i] > mx)
            mx = v[i];
    }
}

int main()
{
    int v[1000], n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int mic, mare;
    minMax(v, n, mic, mare);
    cout << mic << ' ' << mare << '\n';
    return 0;
}
