/*
 * Titlu: Problema rucsacului (varianta discretă)
 * Clasa: 11
 * Capitol: Programare dinamică
 * Descriere: Un rucsac suportă cel mult G kilograme; avem n obiecte cu greutățile g[i] și
 *            valorile v[i], iar un obiect se ia întreg sau deloc. Aici greedy-ul după
 *            valoare pe kilogram nu mai merge. best[i][c] este valoarea maximă folosind
 *            doar primele i obiecte și o capacitate c: fie nu luăm obiectul i
 *            (best[i-1][c]), fie îl luăm, dacă încape (best[i-1][c - g[i]] + v[i]).
 *            Pentru a afla obiectele alese mergem înapoi: dacă best[i][c] diferă de
 *            best[i-1][c], obiectul i a fost luat. Se afișează valoarea maximă și
 *            numerele obiectelor alese.
 * Complexitate: O(n · G) timp și memorie
 *
 * Exemplu
 * Intrare:
 * 4 10
 * 5 10
 * 4 40
 * 6 30
 * 3 50
 * Ieșire:
 * 90
 * 2 4
 */
#include <iostream>
using namespace std;

int g[105], v[105], best[105][10005];

int main()
{
    int n, G;
    cin >> n >> G;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i] >> v[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int c = 0; c <= G; c++)
        {
            best[i][c] = best[i - 1][c];
            if (g[i] <= c && best[i - 1][c - g[i]] + v[i] > best[i][c])
            {
                best[i][c] = best[i - 1][c - g[i]] + v[i];
            }
        }
    }
    cout << best[n][G] << '\n';

    int ales[105], cate = 0, c = G;
    for (int i = n; i >= 1; i--)
    {
        if (best[i][c] != best[i - 1][c])
        {
            ales[cate++] = i;
            c -= g[i];
        }
    }
    for (int i = cate - 1; i >= 0; i--)
    {
        cout << ales[i] << ' ';
    }
    cout << '\n';
    return 0;
}
