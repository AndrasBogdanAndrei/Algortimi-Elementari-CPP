/*
 * Titlu: Sortarea prin inserție
 * Clasa: 9
 * Capitol: Sortare și căutare
 * Descriere: Ca la aranjarea cărților de joc în mână: primele i - 1 elemente
 *            sunt deja sortate, iar v[i] este inserat la locul lui printre ele.
 *            Salvăm v[i] în x și mutăm la dreapta elementele mai mari decât x,
 *            apoi punem x în golul rămas.
 * Complexitate: O(n²) în cazul cel mai rău, O(n) dacă vectorul e aproape sortat
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
    for (int i = 2; i <= n; i++)
    {
        int x = v[i];
        int j = i - 1;
        while (j >= 1 && v[j] > x)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
