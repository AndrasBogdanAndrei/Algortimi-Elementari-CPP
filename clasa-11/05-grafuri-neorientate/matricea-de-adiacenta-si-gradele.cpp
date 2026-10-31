/*
 * Titlu: Matricea de adiacență și gradele nodurilor
 * Clasa: 11
 * Capitol: Grafuri neorientate
 * Descriere: Un graf neorientat cu n noduri și m muchii se poate memora într-o matrice
 *            a cu n linii și n coloane: a[i][j] = 1 dacă există muchia [i, j], altfel 0.
 *            Matricea este simetrică față de diagonala principală, iar pe diagonală are 0.
 *            Gradul nodului i (numărul de muchii care pleacă din el) este suma elementelor
 *            de pe linia i. Suma tuturor gradelor este 2 · m, pentru că fiecare muchie se
 *            numără la ambele capete. Se afișează matricea, gradele și suma lor.
 * Complexitate: O(n² + m)
 *
 * Exemplu
 * Intrare:
 * 4 4
 * 1 2
 * 1 3
 * 2 3
 * 3 4
 * Ieșire:
 * 0 1 1 0
 * 1 0 1 0
 * 1 1 0 1
 * 0 0 1 0
 * Grade: 2 2 3 1
 * Suma gradelor: 8
 */
#include <iostream>
using namespace std;

int a[105][105], grad[105];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    int suma = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << ' ';
            grad[i] += a[i][j];
        }
        cout << '\n';
        suma += grad[i];
    }
    cout << "Grade:";
    for (int i = 1; i <= n; i++)
    {
        cout << ' ' << grad[i];
    }
    cout << '\n';
    cout << "Suma gradelor: " << suma << '\n';
    return 0;
}
