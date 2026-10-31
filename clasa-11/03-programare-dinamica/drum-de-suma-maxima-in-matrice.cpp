/*
 * Titlu: Drum de sumă maximă în matrice
 * Clasa: 11
 * Capitol: Programare dinamică
 * Descriere: Într-o matrice n × m pornim din colțul (1, 1) și ajungem în (n, m) mergând
 *            doar la dreapta sau în jos. Vrem suma maximă a elementelor de pe drum.
 *            În celula (i, j) se poate ajunge doar de sus sau din stânga, deci
 *            d[i][j] = a[i][j] + max(d[i-1][j], d[i][j-1]) (pe prima linie și pe prima
 *            coloană există o singură variantă). Drumul se reface înapoi din (n, m), mergând
 *            mereu spre vecinul (sus sau stânga) cu d mai mare; la egalitate urcăm.
 *            Se afișează suma și celulele drumului.
 * Complexitate: O(n · m) timp și memorie
 *
 * Exemplu
 * Intrare:
 * 3 4
 * 1 3 1 2
 * 2 5 1 4
 * 4 2 3 1
 * Ieșire:
 * 15
 * (1,1) (1,2) (2,2) (2,3) (2,4) (3,4)
 */
#include <iostream>
using namespace std;

int a[105][105], d[105][105];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
            {
                d[i][j] = a[i][j];
            }
            else if (i == 1)
            {
                d[i][j] = a[i][j] + d[i][j - 1];
            }
            else if (j == 1)
            {
                d[i][j] = a[i][j] + d[i - 1][j];
            }
            else
            {
                d[i][j] = a[i][j] + max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    cout << d[n][m] << '\n';

    // refacem drumul de la final spre început, apoi îl afișăm invers
    int lin[210], col[210], k = 0;
    int i = n, j = m;
    while (true)
    {
        lin[k] = i;
        col[k] = j;
        k++;
        if (i == 1 && j == 1)
        {
            break;
        }
        if (j == 1 || (i > 1 && d[i - 1][j] >= d[i][j - 1]))
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for (int p = k - 1; p >= 0; p--)
    {
        cout << '(' << lin[p] << ',' << col[p] << ") ";
    }
    cout << '\n';
    return 0;
}
