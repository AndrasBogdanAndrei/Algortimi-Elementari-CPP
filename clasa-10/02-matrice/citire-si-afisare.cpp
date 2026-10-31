/*
 * Titlu: Citirea și afișarea unei matrice
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: O matrice cu n linii și m coloane se declară ca int a[101][101] și se
 *            parcurge cu două for-uri imbricate: primul alege linia i, al doilea
 *            coloana j. Indexăm de la 1, ca în enunțurile de bacalaureat. La afișare
 *            punem un spațiu după fiecare element și un rând nou după fiecare linie.
 *            Pentru verificare afișăm și elementul din colțul dreapta-jos, a[n][m].
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare:
 * 2 3
 * 1 2 3
 * 4 5 6
 * Ieșire:
 * 1 2 3
 * 4 5 6
 * 6
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

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    cout << a[n][m] << '\n';
    return 0;
}
