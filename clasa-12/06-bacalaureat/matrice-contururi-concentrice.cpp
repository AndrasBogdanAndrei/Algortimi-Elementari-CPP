/*
 * Titlu: Matrice — contururi concentrice
 * Clasa: 12
 * Capitol: Recapitulare pentru bacalaureat
 * Descriere: Cerința (tip subiectul III.2): se citește n (2 ≤ n ≤ 20). Construiți
 *            în memorie o matrice cu n linii și n coloane în care elementele de pe
 *            conturul exterior sunt 1, cele de pe conturul următor 2 și așa mai
 *            departe, apoi afișați-o. În loc să „desenăm” contur după contur,
 *            observăm că elementul (i, j) (numerotare de la 0) se află pe conturul
 *            dat de distanța lui până la cea mai apropiată margine:
 *            min(i, j, n-1-i, n-1-j) + 1. Așa fiecare element se calculează
 *            direct, o singură dată.
 * Complexitate: O(n^2)
 *
 * Exemplu
 * Intrare: 5
 * Ieșire:
 * 1 1 1 1 1
 * 1 2 2 2 1
 * 1 2 3 2 1
 * 1 2 2 2 1
 * 1 1 1 1 1
 *
 * Exemplu
 * Intrare: 4
 * Ieșire:
 * 1 1 1 1
 * 1 2 2 1
 * 1 2 2 1
 * 1 1 1 1
 */
#include <iostream>
using namespace std;

int main()
{
    int n, a[20][20];
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int d = i;
            if (j < d)
                d = j;
            if (n - 1 - i < d)
                d = n - 1 - i;
            if (n - 1 - j < d)
                d = n - 1 - j;
            a[i][j] = d + 1;
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}
