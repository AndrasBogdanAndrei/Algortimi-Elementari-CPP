/*
 * Titlu: Componentele tare conexe
 * Clasa: 11
 * Capitol: Grafuri orientate și drumuri minime
 * Descriere: Un graf orientat este tare conex dacă pentru oricare două noduri x și y există
 *            drum de la x la y și drum de la y la x. O componentă tare conexă este un grup
 *            maximal de noduri cu această proprietate. Pentru un nod x încă neîncadrat facem
 *            două parcurgeri DFS: una pe arcele grafului (nodurile în care se poate ajunge
 *            din x, marcate cu +) și una pe arcele inversate (nodurile din care se ajunge în
 *            x, marcate cu -). Nodurile marcate și cu +, și cu - formează componenta lui x.
 *            Se afișează numărul de componente și nodurile fiecăreia.
 * Complexitate: O(n³) cu matricea de adiacență (n parcurgeri de cost O(n²))
 *
 * Exemplu
 * Intrare:
 * 6 8
 * 1 2
 * 2 3
 * 3 1
 * 3 4
 * 4 5
 * 5 4
 * 6 5
 * 6 1
 * Ieșire:
 * 3
 * 1 2 3
 * 4 5
 * 6
 */
#include <iostream>
using namespace std;

int n, m, a[105][105], comp[105];
bool plusV[105], minusV[105];

void dfsPlus(int x)
{
    plusV[x] = true;
    for (int y = 1; y <= n; y++)
    {
        if (a[x][y] == 1 && !plusV[y])
        {
            dfsPlus(y);
        }
    }
}

void dfsMinus(int x)
{
    minusV[x] = true;
    for (int y = 1; y <= n; y++)
    {
        if (a[y][x] == 1 && !minusV[y])
        {
            dfsMinus(y);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }

    int nrComp = 0;
    for (int x = 1; x <= n; x++)
    {
        if (comp[x] != 0)
        {
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            plusV[i] = minusV[i] = false;
        }
        dfsPlus(x);
        dfsMinus(x);
        nrComp++;
        for (int i = 1; i <= n; i++)
        {
            if (plusV[i] && minusV[i])
            {
                comp[i] = nrComp;
            }
        }
    }

    cout << nrComp << '\n';
    for (int c = 1; c <= nrComp; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (comp[i] == c)
            {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
