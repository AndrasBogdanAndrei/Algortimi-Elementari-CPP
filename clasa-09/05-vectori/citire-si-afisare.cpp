/*
 * Titlu: Citirea și afișarea unui vector
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: Un vector păstrează mai multe valori de același tip, accesate prin
 *            indice. Declarăm vectorul cu o dimensiune maximă fixă și folosim
 *            pozițiile 1..n. Se citesc n și cele n elemente, apoi se afișează
 *            elementele în ordine, și pe a doua linie în ordine inversă.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 3 1 4 1 5
 * Ieșire:
 * 3 1 4 1 5
 * 5 1 4 1 3
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
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    for (int i = n; i >= 1; i--)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
