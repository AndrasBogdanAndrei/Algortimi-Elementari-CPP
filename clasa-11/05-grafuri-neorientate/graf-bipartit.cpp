/*
 * Titlu: Verificarea unui graf bipartit
 * Clasa: 11
 * Capitol: Grafuri neorientate
 * Descriere: Un graf este bipartit dacă nodurile lui se pot împărți în două mulțimi A și B
 *            astfel încât fiecare muchie să aibă un capăt în A și celălalt în B. Colorăm
 *            nodurile cu două culori printr-o parcurgere BFS: nodul de start primește
 *            culoarea 1, iar fiecare vecin primește culoarea opusă nodului din care a fost
 *            descoperit. Dacă găsim o muchie cu ambele capete de aceeași culoare, graful nu
 *            e bipartit (are un ciclu de lungime impară). Pornim BFS din fiecare nod
 *            necolorat, ca să tratăm și grafurile neconexe.
 * Complexitate: O(n²) cu matricea de adiacență
 *
 * Exemplu
 * Intrare:
 * 6 6
 * 1 2
 * 2 3
 * 3 4
 * 4 1
 * 4 5
 * 5 6
 * Ieșire:
 * DA
 * 1 3 5
 * 2 4 6
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 1 2
 * 2 3
 * 3 1
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int n, m, a[105][105], culoare[105], coada[105];

int main()
{
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    bool bipartit = true;
    for (int s = 1; s <= n && bipartit; s++)
    {
        if (culoare[s] != 0)
        {
            continue;
        }
        int inc = 1, sf = 1;
        coada[1] = s;
        culoare[s] = 1;
        while (inc <= sf && bipartit)
        {
            int x = coada[inc++];
            for (int y = 1; y <= n; y++)
            {
                if (a[x][y] == 1)
                {
                    if (culoare[y] == 0)
                    {
                        culoare[y] = 3 - culoare[x];
                        coada[++sf] = y;
                    }
                    else if (culoare[y] == culoare[x])
                    {
                        bipartit = false;
                    }
                }
            }
        }
    }

    if (!bipartit)
    {
        cout << "NU\n";
        return 0;
    }
    cout << "DA\n";
    for (int c = 1; c <= 2; c++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (culoare[i] == c)
            {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
