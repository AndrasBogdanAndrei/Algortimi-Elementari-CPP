/*
 * Titlu: Generarea tablei de șah
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Pe o tablă de șah, culoarea pătratului depinde doar de paritatea
 *            sumei i + j: pătratele cu i + j par au o culoare (1), cele cu i + j
 *            impar cealaltă culoare (0). Astfel, colțul a[1][1] este 1 și oricare
 *            două pătrate vecine (pe linie sau pe coloană) au valori diferite.
 * Complexitate: O(n * n)
 *
 * Exemplu
 * Intrare: 4
 * Ieșire:
 * 1 0 1 0
 * 0 1 0 1
 * 1 0 1 0
 * 0 1 0 1
 *
 * Exemplu
 * Intrare: 1
 * Ieșire: 1
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
            a[i][j] = ((i + j) % 2 == 0) ? 1 : 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
