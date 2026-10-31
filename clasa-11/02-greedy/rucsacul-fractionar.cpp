/*
 * Titlu: Problema rucsacului (varianta fracționară)
 * Clasa: 11
 * Capitol: Metoda greedy
 * Descriere: Un rucsac suportă cel mult G kilograme. Avem n obiecte; obiectul i are
 *            greutatea g[i] și valoarea v[i], iar din orice obiect putem lua și o bucată
 *            (o fracțiune). Pentru valoare maximă, sortăm obiectele după valoarea pe
 *            kilogram v[i] / g[i], descrescător, și le luăm întregi cât încap; din primul
 *            obiect care nu mai încape luăm doar fracțiunea care umple rucsacul.
 *            Se afișează valoarea maximă, apoi fracțiunea luată din fiecare obiect
 *            (în ordinea citirii), cu două zecimale.
 * Complexitate: O(n log n)
 *
 * Exemplu
 * Intrare:
 * 3 50
 * 10 60
 * 20 100
 * 30 120
 * Ieșire:
 * 240.00
 * 1.00 1.00 0.67
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct obiect
{
    int greutate, valoare, nr;
};

obiect a[1000];
double luat[1000];

// a valorează mai mult pe kilogram decât b: a.v / a.g > b.v / b.g, fără împărțiri
bool maiBun(const obiect &a, const obiect &b)
{
    return a.valoare * b.greutate > b.valoare * a.greutate;
}

int main()
{
    int n;
    double G;
    cin >> n >> G;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].greutate >> a[i].valoare;
        a[i].nr = i;
    }
    sort(a, a + n, maiBun);

    double total = 0, loc = G;
    for (int i = 0; i < n && loc > 0; i++)
    {
        if (a[i].greutate <= loc)
        {
            luat[a[i].nr] = 1;
            loc -= a[i].greutate;
            total += a[i].valoare;
        }
        else
        {
            double fractiune = loc / a[i].greutate;
            luat[a[i].nr] = fractiune;
            total += fractiune * a[i].valoare;
            loc = 0;
        }
    }

    cout << fixed << setprecision(2) << total << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << luat[i] << ' ';
    }
    cout << '\n';
    return 0;
}
