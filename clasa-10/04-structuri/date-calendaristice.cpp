/*
 * Titlu: Compararea datelor calendaristice
 * Clasa: 10
 * Capitol: Tipul struct
 * Descriere: O dată calendaristică are trei câmpuri: zi, luna, an. Două date se
 *            compară întâi după an, la ani egali după lună, iar la luni egale după
 *            zi; funcția maiDevreme(d1, d2) aplică exact această regulă. O altă
 *            idee este să transformăm data în numărul an * 10000 + luna * 100 + zi,
 *            care păstrează ordinea. Se citesc n date și se afișează în ordine
 *            cronologică.
 * Complexitate: O(n * n) cu sortarea prin selecție
 *
 * Exemplu
 * Intrare:
 * 4
 * 15 3 2024
 * 1 12 2023
 * 15 1 2024
 * 2 3 2024
 * Ieșire:
 * 1 12 2023
 * 15 1 2024
 * 2 3 2024
 * 15 3 2024
 */
#include <iostream>
using namespace std;

struct Data
{
    int zi, luna, an;
};

Data d[1000];

bool maiDevreme(Data a, Data b)
{
    if (a.an != b.an)
        return a.an < b.an;
    if (a.luna != b.luna)
        return a.luna < b.luna;
    return a.zi < b.zi;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> d[i].zi >> d[i].luna >> d[i].an;

    for (int i = 0; i < n - 1; i++)
    {
        int pozMin = i;
        for (int j = i + 1; j < n; j++)
            if (maiDevreme(d[j], d[pozMin]))
                pozMin = j;
        Data aux = d[i];
        d[i] = d[pozMin];
        d[pozMin] = aux;
    }

    for (int i = 0; i < n; i++)
        cout << d[i].zi << ' ' << d[i].luna << ' ' << d[i].an << '\n';
    return 0;
}
