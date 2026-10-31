/*
 * Titlu: Maximul unui vector prin divide et impera
 * Clasa: 10
 * Capitol: Divide et impera
 * Descriere: Cele trei etape ale metodei: împărțim porțiunea [st, dr] în două
 *            jumătăți, la mijlocul m = (st + dr) / 2 (divide); aflăm recursiv maximul
 *            fiecărei jumătăți (stăpânește); maximul total este cel mai mare dintre
 *            cele două rezultate (combină). Cazul elementar: o porțiune cu un singur
 *            element, care este chiar maximul ei.
 * Complexitate: O(n), cu adâncimea stivei O(log n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 4 9 2 17 5 8
 * Ieșire: 17
 *
 * Exemplu
 * Intrare:
 * 1
 * -3
 * Ieșire: -3
 */
#include <iostream>
using namespace std;

int v[1000];

int maxim(int st, int dr)
{
    if (st == dr)
        return v[st];
    int m = (st + dr) / 2;
    int a = maxim(st, m);
    int b = maxim(m + 1, dr);
    return a > b ? a : b;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << maxim(0, n - 1) << '\n';
    return 0;
}
