/*
 * Titlu: Plata unei sume cu număr minim de bancnote
 * Clasa: 11
 * Capitol: Metoda greedy
 * Descriere: Se dau n valori de bancnote (din fiecare avem oricâte) și o sumă S.
 *            Strategia greedy: plătim cât mai mult cu bancnota cea mai mare, apoi
 *            continuăm cu restul și bancnota următoare. Pentru sistemele „canonice”, ca
 *            cel al leului (1, 5, 10, 50, 100, 200, 500), metoda dă numărul minim de
 *            bancnote. Atenție: pentru valori oarecare (de exemplu 1, 3, 4 și S = 6)
 *            greedy poate greși; acolo se folosește programarea dinamică.
 * Complexitate: O(n log n) pentru sortare, apoi O(n)
 *
 * Exemplu
 * Intrare:
 * 7
 * 1 5 10 50 100 200 500
 * 1288
 * Ieșire:
 * 500 x 2
 * 200 x 1
 * 50 x 1
 * 10 x 3
 * 5 x 1
 * 1 x 3
 * Total: 11
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, v[100];
    long long S;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cin >> S;
    sort(v, v + n);

    long long total = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        long long bucati = S / v[i];
        if (bucati > 0)
        {
            cout << v[i] << " x " << bucati << '\n';
            total += bucati;
            S -= bucati * v[i];
        }
    }
    if (S > 0)
    {
        cout << "Rest neplatit: " << S << '\n';
    }
    cout << "Total: " << total << '\n';
    return 0;
}
