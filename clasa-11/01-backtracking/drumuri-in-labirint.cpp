/*
 * Titlu: Drumuri într-un labirint
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Labirintul este o matrice n × m cu 0 (liber) și 1 (zid). Pornim din colțul
 *            stânga-sus (1, 1) și vrem să ajungem în colțul dreapta-jos (n, m), mergând
 *            sus, jos, stânga sau dreapta, fără să trecem de două ori prin aceeași celulă.
 *            Din fiecare celulă încercăm cele 4 direcții; marcăm celula ca vizitată la
 *            intrare și o demarcăm la întoarcere. Se afișează numărul de drumuri și
 *            lungimea celui mai scurt (în celule), sau 0 dacă nu există drum.
 * Complexitate: exponențială (numărul de drumuri poate fi foarte mare)
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 0 0 0
 * 0 1 0
 * 0 0 0
 * Ieșire:
 * Drumuri: 2
 * Cel mai scurt: 5
 */
#include <iostream>
using namespace std;

int n, m, a[12][12], drumuri = 0, minim = 1000;
bool vizitat[12][12];
int dl[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void back(int l, int c, int lungime)
{
    if (l == n && c == m)
    {
        drumuri++;
        if (lungime < minim)
        {
            minim = lungime;
        }
        return;
    }
    for (int d = 0; d < 4; d++)
    {
        int nl = l + dl[d], nc = c + dc[d];
        if (nl >= 1 && nl <= n && nc >= 1 && nc <= m && a[nl][nc] == 0 && !vizitat[nl][nc])
        {
            vizitat[nl][nc] = true;
            back(nl, nc, lungime + 1);
            vizitat[nl][nc] = false;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    if (a[1][1] == 0)
    {
        vizitat[1][1] = true;
        back(1, 1, 1);
    }
    cout << "Drumuri: " << drumuri << '\n';
    cout << "Cel mai scurt: " << (drumuri > 0 ? minim : 0) << '\n';
    return 0;
}
