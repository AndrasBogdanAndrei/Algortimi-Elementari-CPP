/*
 * Titlu: Sortarea prin selecție
 * Clasa: 9
 * Capitol: Sortare și căutare
 * Descriere: Pentru fiecare poziție i, de la 1 la n - 1, căutăm minimul din
 *            v[i..n] și îl aducem pe poziția i printr-o singură interschimbare.
 *            După pasul i, primele i poziții conțin cele mai mici i valori, în
 *            ordine. Face mereu cam n²/2 comparații, dar cel mult n - 1
 *            interschimbări.
 * Complexitate: O(n²)
 *
 * Exemplu
 * Intrare:
 * 6
 * 5 2 9 1 5 6
 * Ieșire: 1 2 5 5 6 9
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
    for (int i = 1; i < n; i++)
    {
        int pozMin = i;
        for (int j = i + 1; j <= n; j++)
        {
            if (v[j] < v[pozMin])
            {
                pozMin = j;
            }
        }
        int aux = v[i];
        v[i] = v[pozMin];
        v[pozMin] = aux;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
