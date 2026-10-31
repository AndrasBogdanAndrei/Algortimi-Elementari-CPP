/*
 * Titlu: Inversarea unui vector
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: Interschimbăm primul element cu ultimul, al doilea cu penultimul
 *            și așa mai departe: v[i] cu v[n - i + 1]. Ne oprim la jumătate
 *            (i <= n / 2); dacă am merge până la n, fiecare pereche s-ar
 *            interschimba de două ori și vectorul ar reveni la forma inițială.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 2 3 4 5
 * Ieșire: 5 4 3 2 1
 */
#include <iostream>
using namespace std;

int v[1001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n / 2; i++)
    {
        int aux = v[i];
        v[i] = v[n - i + 1];
        v[n - i + 1] = aux;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
