/*
 * Titlu: Distanța de editare
 * Clasa: 11
 * Capitol: Programare dinamică
 * Descriere: Câte operații sunt necesare, minim, ca să transformăm cuvântul a în cuvântul b?
 *            O operație înseamnă inserarea, ștergerea sau înlocuirea unei litere.
 *            d[i][j] este răspunsul pentru primele i litere din a și primele j din b.
 *            d[i][0] = i (ștergem tot), d[0][j] = j (inserăm tot). Dacă a[i] = b[j],
 *            d[i][j] = d[i-1][j-1]; altfel d[i][j] = 1 + min(d[i-1][j] (ștergere),
 *            d[i][j-1] (inserare), d[i-1][j-1] (înlocuire)).
 * Complexitate: O(n · m) timp și memorie
 *
 * Exemplu
 * Intrare:
 * soare
 * stare
 * Ieșire: 1
 *
 * Exemplu
 * Intrare:
 * carte
 * cartof
 * Ieșire: 2
 */
#include <iostream>
#include <cstring>
using namespace std;

char a[1005], b[1005];
int d[1005][1005];

int main()
{
    cin >> (a + 1) >> (b + 1);
    int n = strlen(a + 1), m = strlen(b + 1);

    for (int i = 0; i <= n; i++)
    {
        d[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        d[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                d[i][j] = d[i - 1][j - 1];
            }
            else
            {
                d[i][j] = 1 + min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1]));
            }
        }
    }
    cout << d[n][m] << '\n';
    return 0;
}
