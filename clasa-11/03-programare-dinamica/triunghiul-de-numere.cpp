/*
 * Titlu: Suma maximă în triunghiul de numere
 * Clasa: 11
 * Capitol: Programare dinamică
 * Descriere: Un triunghi are n linii; linia i conține i numere. Pornim din vârf și la
 *            fiecare pas coborâm fie drept în jos (a[i+1][j]), fie în jos și la dreapta
 *            (a[i+1][j+1]). Vrem suma maximă a numerelor de pe drum. Lucrăm de jos în sus:
 *            s[i][j] = a[i][j] + max(s[i+1][j], s[i+1][j+1]), iar pe ultima linie
 *            s[n][j] = a[n][j]. Răspunsul este s[1][1]. Drumul se reface de sus în jos,
 *            mergând mereu spre fiul cu s mai mare (drept în jos, la egalitate).
 * Complexitate: O(n²) timp și memorie
 *
 * Exemplu
 * Intrare:
 * 4
 * 5
 * 4 6
 * 2 9 1
 * 8 3 5 7
 * Ieșire:
 * 25
 * 5 6 9 5
 */
#include <iostream>
using namespace std;

int a[105][105], s[105][105];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int j = 1; j <= n; j++)
    {
        s[n][j] = a[n][j];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            s[i][j] = a[i][j] + max(s[i + 1][j], s[i + 1][j + 1]);
        }
    }
    cout << s[1][1] << '\n';

    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i][j] << ' ';
        if (i < n && s[i + 1][j + 1] > s[i + 1][j])
        {
            j++;
        }
    }
    cout << '\n';
    return 0;
}
