/*
 * Titlu: Suma pe linii și pe coloane
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Pentru suma liniei i ținem i fix și plimbăm j de la 1 la m. Pentru
 *            suma coloanei j facem invers: j fix în bucla din afară, i variabil în
 *            bucla din interior. Pe primul rând se afișează sumele celor n linii,
 *            pe al doilea sumele celor m coloane.
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare:
 * 2 3
 * 1 2 3
 * 4 5 6
 * Ieșire:
 * 6 15
 * 5 7 9
 *
 * Exemplu
 * Intrare:
 * 3 2
 * 1 -1
 * 0 7
 * 2 2
 * Ieșire:
 * 0 7 4
 * 3 8
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
        int s = 0;
        for (int j = 1; j <= m; j++)
            s += a[i][j];
        cout << s << ' ';
    }
    cout << '\n';

    for (int j = 1; j <= m; j++)
    {
        int s = 0;
        for (int i = 1; i <= n; i++)
            s += a[i][j];
        cout << s << ' ';
    }
    cout << '\n';
    return 0;
}
