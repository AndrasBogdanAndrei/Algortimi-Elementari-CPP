/*
 * Titlu: Puncte în plan
 * Clasa: 10
 * Capitol: Tipul struct
 * Descriere: Un punct are coordonatele x și y: struct Punct { int x, y; }. Distanța
 *            dintre două puncte este sqrt((x1 - x2)^2 + (y1 - y2)^2). Pentru comparații
 *            folosim pătratul distanței (număr întreg, fără erori de rotunjire) și
 *            facem radicalul doar la afișare. Se citesc n puncte; se afișează punctul
 *            cel mai apropiat de origine (primul, la egalitate) și cea mai mare
 *            distanță dintre două puncte, cu două zecimale.
 * Complexitate: O(n * n) pentru distanța maximă
 *
 * Exemplu
 * Intrare:
 * 4
 * 3 4
 * -1 2
 * 5 0
 * 2 -2
 * Ieșire:
 * -1 2
 * 6.32
 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Punct
{
    int x, y;
};

Punct p[1000];

long long distantaPatrat(Punct a, Punct b)
{
    long long dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    Punct origine = {0, 0};
    int celMaiAproape = 0;
    for (int i = 1; i < n; i++)
        if (distantaPatrat(p[i], origine) < distantaPatrat(p[celMaiAproape], origine))
            celMaiAproape = i;
    cout << p[celMaiAproape].x << ' ' << p[celMaiAproape].y << '\n';

    long long maxim = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (distantaPatrat(p[i], p[j]) > maxim)
                maxim = distantaPatrat(p[i], p[j]);
    cout << fixed << setprecision(2) << sqrt((double)maxim) << '\n';
    return 0;
}
