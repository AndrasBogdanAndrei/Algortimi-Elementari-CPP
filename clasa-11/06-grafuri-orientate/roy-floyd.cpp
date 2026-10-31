/*
 * Titlu: Drumuri minime între toate perechile de noduri (Roy-Floyd)
 * Clasa: 11
 * Capitol: Grafuri orientate și drumuri minime
 * Descriere: Fiecare arc (x, y) are un cost c ≥ 0. Matricea costurilor d pornește cu
 *            d[i][i] = 0, d[x][y] = costul arcului și „infinit” unde nu există arc. Pentru
 *            fiecare nod intermediar k (bucla exterioară) încercăm să scurtăm drumul de la
 *            i la j trecând prin k: dacă d[i][k] + d[k][j] < d[i][j], îl actualizăm. La final
 *            d[i][j] este costul minim al unui drum de la i la j; INF înseamnă că nu există
 *            drum. Dacă între două noduri apar mai multe arce, se păstrează cel mai ieftin.
 * Complexitate: O(n³)
 *
 * Exemplu
 * Intrare:
 * 4 6
 * 1 2 3
 * 1 3 8
 * 2 3 2
 * 3 4 1
 * 4 1 4
 * 2 4 7
 * Ieșire:
 * 0 3 5 6
 * 7 0 2 3
 * 5 8 0 1
 * 4 7 9 0
 *
 * Exemplu
 * Intrare:
 * 3 1
 * 1 2 5
 * Ieșire:
 * 0 5 INF
 * INF 0 INF
 * INF INF 0
 */
#include <iostream>
using namespace std;

const int INF = 1000000000;
int d[105][105];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = (i == j ? 0 : INF);
        }
    }
    for (int k = 1; k <= m; k++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        if (c < d[x][y])
        {
            d[x][y] = c;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (d[i][k] < INF && d[k][j] < INF && d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == INF)
            {
                cout << "INF ";
            }
            else
            {
                cout << d[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
