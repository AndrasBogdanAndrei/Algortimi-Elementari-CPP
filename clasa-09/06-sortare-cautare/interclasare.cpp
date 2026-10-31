/*
 * Titlu: Interclasarea a doi vectori sortați
 * Clasa: 9
 * Capitol: Sortare și căutare
 * Descriere: Din doi vectori sortați crescător construim un al treilea, tot
 *            sortat. Comparăm elementele curente a[i] și b[j], îl copiem pe cel
 *            mai mic și avansăm doar în vectorul din care l-am luat. Când un
 *            vector se termină, copiem ce a rămas din celălalt.
 * Complexitate: O(n + m)
 *
 * Exemplu
 * Intrare:
 * 4
 * 1 4 6 9
 * 3
 * 2 4 10
 * Ieșire: 1 2 4 4 6 9 10
 */
#include <iostream>
using namespace std;

int a[1001], b[1001], c[2001];

int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    for (int j = 1; j <= m; j++)
    {
        cin >> b[j];
    }
    int i = 1, j = 1, k = 0;
    while (i <= n && j <= m)
    {
        if (a[i] <= b[j])
        {
            k++;
            c[k] = a[i];
            i++;
        }
        else
        {
            k++;
            c[k] = b[j];
            j++;
        }
    }
    while (i <= n)
    {
        k++;
        c[k] = a[i];
        i++;
    }
    while (j <= m)
    {
        k++;
        c[k] = b[j];
        j++;
    }
    for (int p = 1; p <= k; p++)
    {
        cout << c[p] << ' ';
    }
    cout << '\n';
    return 0;
}
