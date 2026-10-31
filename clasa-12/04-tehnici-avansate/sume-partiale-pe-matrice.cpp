/*
 * Titlu: Sume parțiale pe matrice
 * Clasa: 12
 * Capitol: Tehnici avansate: doi pointeri, căutare binară pe răspuns, stive monotone
 * Descriere: s[i][j] = suma elementelor din dreptunghiul cu colțurile (1, 1) și
 *            (i, j). Se calculează o singură dată: s[i][j] = a[i][j] + s[i-1][j] +
 *            s[i][j-1] - s[i-1][j-1] (colțul comun a fost adunat de două ori).
 *            Apoi suma oricărui dreptunghi (x1, y1) - (x2, y2) se obține din patru
 *            valori: s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]. Astfel
 *            q întrebări costă O(1) fiecare, nu O(n * m).
 * Complexitate: O(n * m) pentru precalculare, O(1) pentru fiecare întrebare
 *
 * Exemplu
 * Intrare:
 * 3 4
 * 1 2 3 4
 * 5 6 7 8
 * 9 10 11 12
 * 3
 * 1 1 3 4
 * 2 2 3 3
 * 1 4 3 4
 * Ieșire:
 * 78
 * 34
 * 24
 */
#include <iostream>
using namespace std;

const int DIM = 1001;
long long s[DIM][DIM]; // linia 0 și coloana 0 rămân 0

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            long long x;
            cin >> x;
            s[i][j] = x + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    int q;
    cin >> q;
    for (int t = 0; t < q; t++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long suma = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
        cout << suma << '\n';
    }
    return 0;
}
