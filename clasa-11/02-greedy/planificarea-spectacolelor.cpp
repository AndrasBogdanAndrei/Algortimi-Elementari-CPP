/*
 * Titlu: Planificarea spectacolelor
 * Clasa: 11
 * Capitol: Metoda greedy
 * Descriere: Într-o sală se pot ține n spectacole; spectacolul i începe la ora s[i] și se
 *            termină la ora f[i]. Vrem să programăm cât mai multe spectacole care nu se
 *            suprapun (unul poate începe exact când se termină altul). Alegerea greedy:
 *            sortăm spectacolele după ora de terminare și îl luăm mereu pe primul care
 *            începe după ce s-a terminat ultimul ales. Terminând cât mai devreme, lăsăm
 *            cât mai mult timp pentru restul. Se afișează numărul de spectacole și
 *            numerele lor de ordine, în ordinea în care au fost alese.
 * Complexitate: O(n log n) pentru sortare, apoi O(n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 10 12
 * 11 13
 * 12 14
 * 9 11
 * 14 16
 * 13 15
 * Ieșire:
 * 3
 * 4 2 6
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct spectacol
{
    int inceput, sfarsit, nr;
};

spectacol a[1000];

bool maiDevreme(const spectacol &x, const spectacol &y)
{
    if (x.sfarsit != y.sfarsit)
    {
        return x.sfarsit < y.sfarsit;
    }
    return x.nr < y.nr;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].inceput >> a[i].sfarsit;
        a[i].nr = i + 1;
    }
    sort(a, a + n, maiDevreme);

    int ales[1000], cate = 0;
    int ultimulSfarsit = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i].inceput >= ultimulSfarsit)
        {
            ales[cate++] = a[i].nr;
            ultimulSfarsit = a[i].sfarsit;
        }
    }

    cout << cate << '\n';
    for (int i = 0; i < cate; i++)
    {
        cout << ales[i] << ' ';
    }
    cout << '\n';
    return 0;
}
