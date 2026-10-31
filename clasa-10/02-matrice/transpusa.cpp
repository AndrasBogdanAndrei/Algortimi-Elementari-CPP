/*
 * Titlu: Transpusa unei matrice
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Transpusa matricei a (n linii, m coloane) are m linii și n coloane:
 *            linia i a transpusei este coloana i a lui a, adică t[j][i] = a[i][j].
 *            Nu e nevoie de o a doua matrice dacă doar o afișăm: parcurgem a pe
 *            coloane în loc de linii.
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare:
 * 2 3
 * 1 2 3
 * 4 5 6
 * Ieșire:
 * 1 4
 * 2 5
 * 3 6
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

    // Coloana j a lui a devine linia j a transpusei.
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
