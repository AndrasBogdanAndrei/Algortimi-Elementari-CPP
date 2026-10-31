/*
 * Titlu: Sortarea cu std::sort
 * Clasa: 9
 * Capitol: Sortare și căutare
 * Descriere: Biblioteca <algorithm> are funcția sort, care ordonează în
 *            O(n log n). Primește începutul și sfârșitul zonei: pentru pozițiile
 *            1..n scriem sort(v + 1, v + n + 1). Pentru ordine descrescătoare se
 *            adaugă al treilea argument greater<int>(). Se afișează vectorul
 *            sortat crescător, apoi descrescător.
 * Complexitate: O(n log n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 3 1 4 1 5
 * Ieșire:
 * 1 1 3 4 5
 * 5 4 3 1 1
 */
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int v[100001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    sort(v + 1, v + n + 1, greater<int>());
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
