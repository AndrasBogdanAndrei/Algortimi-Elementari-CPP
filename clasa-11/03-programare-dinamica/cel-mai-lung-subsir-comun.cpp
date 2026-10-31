/*
 * Titlu: Cel mai lung subșir comun
 * Clasa: 11
 * Capitol: Programare dinamică
 * Descriere: Se dau două cuvinte a și b. Căutăm cel mai lung șir de litere care apare ca
 *            subșir (litere în ordine, nu neapărat alăturate) în ambele. L[i][j] este
 *            lungimea celui mai lung subșir comun al primelor i litere din a și primelor j
 *            litere din b. Dacă a[i] = b[j], atunci L[i][j] = L[i-1][j-1] + 1; altfel
 *            L[i][j] = max(L[i-1][j], L[i][j-1]). Reconstituirea pornește din colțul
 *            (n, m) și merge înapoi: la litere egale o păstrăm și urcăm pe diagonală,
 *            altfel ne mutăm spre vecinul cu valoarea mai mare (sus, la egalitate).
 * Complexitate: O(n · m) timp și memorie
 *
 * Exemplu
 * Intrare:
 * PROGRAMARE
 * PARCARE
 * Ieșire:
 * 5
 * PRARE
 */
#include <iostream>
#include <cstring>
using namespace std;

char a[1005], b[1005], rez[1005];
int L[1005][1005];

int main()
{
    cin >> (a + 1) >> (b + 1);
    int n = strlen(a + 1), m = strlen(b + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else if (L[i - 1][j] >= L[i][j - 1])
            {
                L[i][j] = L[i - 1][j];
            }
            else
            {
                L[i][j] = L[i][j - 1];
            }
        }
    }

    int k = L[n][m];
    rez[k] = 0;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (a[i] == b[j])
        {
            rez[--k] = a[i];
            i--;
            j--;
        }
        else if (L[i - 1][j] >= L[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << L[n][m] << '\n' << rez << '\n';
    return 0;
}
