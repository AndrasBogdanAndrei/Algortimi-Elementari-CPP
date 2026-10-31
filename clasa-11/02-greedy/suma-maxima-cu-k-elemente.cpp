/*
 * Titlu: Suma maximă cu k elemente
 * Clasa: 11
 * Capitol: Metoda greedy
 * Descriere: Dintr-un șir de n numere întregi alegem exact k elemente (pe poziții
 *            diferite) cu suma cât mai mare. Alegerea greedy este evidentă: luăm cele mai
 *            mari k valori. Le obținem sortând șirul descrescător și păstrând primele k.
 *            Se afișează suma și elementele alese, de la cel mai mare la cel mai mic.
 * Complexitate: O(n log n)
 *
 * Exemplu
 * Intrare:
 * 6 3
 * 4 -2 7 -5 3 1
 * Ieșire:
 * 14
 * 7 4 3
 */
#include <iostream>
#include <algorithm>
using namespace std;

bool descrescator(int x, int y)
{
    return x > y;
}

int main()
{
    int n, k, a[1000];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, descrescator);

    long long suma = 0;
    for (int i = 0; i < k; i++)
    {
        suma += a[i];
    }
    cout << suma << '\n';
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}
