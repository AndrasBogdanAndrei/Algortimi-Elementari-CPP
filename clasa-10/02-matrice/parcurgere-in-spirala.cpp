/*
 * Titlu: Parcurgerea în spirală
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Ținem patru margini: sus, jos, stanga, dreapta. La fiecare tură
 *            parcurgem linia de sus (spre dreapta), coloana din dreapta (în jos),
 *            linia de jos (spre stânga) și coloana din stânga (în sus), apoi
 *            strângem marginile cu câte o poziție. Verificările sus <= jos și
 *            stanga <= dreapta din mijlocul turei evită afișarea de două ori a
 *            unei linii sau coloane rămase singure (matrice dreptunghiulare).
 * Complexitate: O(n * m), fiecare element este afișat o singură dată
 *
 * Exemplu
 * Intrare:
 * 3 4
 * 1 2 3 4
 * 5 6 7 8
 * 9 10 11 12
 * Ieșire: 1 2 3 4 8 12 11 10 9 5 6 7
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 1 2 3
 * 4 5 6
 * 7 8 9
 * Ieșire: 1 2 3 6 9 8 7 4 5
 */
#include <iostream>
using namespace std;

int a[101][101];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int sus = 1, jos = n, stanga = 1, dreapta = m;
    while (sus <= jos && stanga <= dreapta)
    {
        for (int j = stanga; j <= dreapta; j++)
            cout << a[sus][j] << ' ';
        sus++;
        for (int i = sus; i <= jos; i++)
            cout << a[i][dreapta] << ' ';
        dreapta--;
        if (sus <= jos)
        {
            for (int j = dreapta; j >= stanga; j--)
                cout << a[jos][j] << ' ';
            jos--;
        }
        if (stanga <= dreapta)
        {
            for (int i = jos; i >= sus; i--)
                cout << a[i][stanga] << ' ';
            stanga++;
        }
    }
    cout << '\n';
    return 0;
}
