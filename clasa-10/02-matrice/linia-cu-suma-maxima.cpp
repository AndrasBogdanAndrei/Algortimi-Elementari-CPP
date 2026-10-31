/*
 * Titlu: Linia cu suma maximă
 * Clasa: 10
 * Capitol: Tablouri bidimensionale (matrice)
 * Descriere: Calculăm suma fiecărei linii și o comparăm cu cea mai mare sumă găsită
 *            până acum. Pornim maximul de la suma primei linii (nu de la 0, pentru
 *            că sumele pot fi negative). Comparația strictă > păstrează prima linie
 *            în caz de egalitate. Se afișează indicele liniei (de la 1) și suma.
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 1 2 3
 * 9 0 1
 * 4 4 2
 * Ieșire: 2 10
 *
 * Exemplu
 * Intrare:
 * 2 2
 * -5 -1
 * -2 -3
 * Ieșire: 2 -5
 */
#include <iostream>
using namespace std;

int a[101][101];

int sumaLinie(int i, int m)
{
    int s = 0;
    for (int j = 1; j <= m; j++)
        s += a[i][j];
    return s;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    int linieMax = 1, sumaMax = sumaLinie(1, m);
    for (int i = 2; i <= n; i++)
    {
        int s = sumaLinie(i, m);
        if (s > sumaMax)
        {
            sumaMax = s;
            linieMax = i;
        }
    }
    cout << linieMax << ' ' << sumaMax << '\n';
    return 0;
}
