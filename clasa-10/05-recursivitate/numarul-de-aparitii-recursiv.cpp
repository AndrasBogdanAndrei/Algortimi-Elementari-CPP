/*
 * Titlu: Numărul de apariții într-un vector, recursiv
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Numărul aparițiilor lui x printre primele n elemente este numărul
 *            aparițiilor printre primele n - 1 elemente, la care se adaugă 1 dacă
 *            ultimul element v[n - 1] este egal cu x. Oprire: un vector cu 0 elemente
 *            nu conține nicio apariție. Se citesc n, cele n elemente și x.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 7
 * 1 3 2 3 3 5 1
 * 3
 * Ieșire: 3
 *
 * Exemplu
 * Intrare:
 * 3
 * 4 5 6
 * 9
 * Ieșire: 0
 */
#include <iostream>
using namespace std;

int aparitii(int v[], int n, int x)
{
    if (n == 0)
        return 0;
    return aparitii(v, n - 1, x) + (v[n - 1] == x ? 1 : 0);
}

int main()
{
    int v[1000], n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> x;
    cout << aparitii(v, n, x) << '\n';
    return 0;
}
