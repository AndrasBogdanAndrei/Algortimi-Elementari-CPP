/*
 * Titlu: Punct șa
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Un punct șa este un element care este minim pe linia lui și maxim pe
 *            coloana lui. Pentru fiecare element a[i][j] verificăm cele două
 *            condiții cu două funcții separate. Se afișează linia, coloana și
 *            valoarea fiecărui punct șa, sau NU EXISTA dacă nu există niciunul.
 * Complexitate: O(n * m * (n + m))
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 3 5 7
 * 2 1 4
 * 6 8 9
 * Ieșire: 3 1 6
 *
 * Exemplu
 * Intrare:
 * 2 2
 * 1 2
 * 2 1
 * Ieșire: NU EXISTA
 */
#include <iostream>
using namespace std;

int a[101][101], n, m;

bool minimPeLinie(int i, int j)
{
    for (int k = 1; k <= m; k++)
        if (a[i][k] < a[i][j])
            return false;
    return true;
}

bool maximPeColoana(int i, int j)
{
    for (int k = 1; k <= n; k++)
        if (a[k][j] > a[i][j])
            return false;
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    bool gasit = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (minimPeLinie(i, j) && maximPeColoana(i, j))
            {
                cout << i << ' ' << j << ' ' << a[i][j] << '\n';
                gasit = true;
            }
    if (!gasit)
        cout << "NU EXISTA\n";
    return 0;
}
