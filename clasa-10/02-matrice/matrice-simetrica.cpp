/*
 * Titlu: Verificarea matricei simetrice
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: O matrice pătratică este simetrică față de diagonala principală dacă
 *            a[i][j] == a[j][i] pentru orice i și j (este egală cu transpusa ei).
 *            Ajunge să verificăm elementele de deasupra diagonalei (j > i), fiecare
 *            cu perechea lui de sub diagonală; la prima nepotrivire ne oprim.
 * Complexitate: O(n * n) în cel mai rău caz
 *
 * Exemplu
 * Intrare:
 * 3
 * 1 2 3
 * 2 5 7
 * 3 7 9
 * Ieșire: DA
 *
 * Exemplu
 * Intrare:
 * 3
 * 1 2 3
 * 2 5 7
 * 4 7 9
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int a[101][101];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    bool simetrica = true;
    for (int i = 1; i <= n && simetrica; i++)
        for (int j = i + 1; j <= n && simetrica; j++)
            if (a[i][j] != a[j][i])
                simetrica = false;

    if (simetrica)
        cout << "DA\n";
    else
        cout << "NU\n";
    return 0;
}
