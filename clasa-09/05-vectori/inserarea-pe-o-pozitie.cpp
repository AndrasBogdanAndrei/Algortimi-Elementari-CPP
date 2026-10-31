/*
 * Titlu: Inserarea unui element pe o poziție
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: Ca să punem val pe poziția poz, facem loc: mutăm elementele
 *            v[poz..n] cu o poziție la dreapta. Mutarea începe de la capăt
 *            (de la n spre poz); de la stânga spre dreapta am suprascrie valori
 *            încă nemutate. Apoi v[poz] = val și n crește cu 1.
 *            Se citesc n, cele n elemente, apoi poz (1 <= poz <= n + 1) și val.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 2 3 4 5
 * 3 9
 * Ieșire: 1 2 9 3 4 5
 */
#include <iostream>
using namespace std;

int v[1002];

int main()
{
    int n, poz, val;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    cin >> poz >> val;
    for (int i = n; i >= poz; i--)
    {
        v[i + 1] = v[i];
    }
    v[poz] = val;
    n++;
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
    return 0;
}
