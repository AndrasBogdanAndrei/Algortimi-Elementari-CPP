/*
 * Titlu: Sortare cu comparator
 * Clasa: 12
 * Capitol: Structuri de date și STL
 * Descriere: sort(început, sfârșit, cmp) ordonează după regula noastră: cmp(x, y)
 *            întoarce true dacă x trebuie pus înaintea lui y. Aici sortăm
 *            participanții unui concurs descrescător după punctaj, iar la punctaj
 *            egal alfabetic după nume. Comparatorul trebuie să fie „strict”: pentru
 *            elemente echivalente întoarce false (niciodată <= sau >=), altfel
 *            sort se poate comporta greșit.
 * Complexitate: O(n log n)
 *
 * Exemplu
 * Intrare:
 * 5
 * Ana 87
 * Mihai 95
 * Bogdan 87
 * Ioana 100
 * Dan 95
 * Ieșire:
 * Ioana 100
 * Dan 95
 * Mihai 95
 * Ana 87
 * Bogdan 87
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Participant
{
    string nume;
    int punctaj;
};

bool inainte(const Participant &x, const Participant &y)
{
    if (x.punctaj != y.punctaj)
        return x.punctaj > y.punctaj; // punctajul mai mare primul
    return x.nume < y.nume;           // la egalitate, ordinea alfabetică
}

int main()
{
    int n;
    cin >> n;
    vector<Participant> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i].nume >> p[i].punctaj;
    sort(p.begin(), p.end(), inainte);
    for (const Participant &x : p)
        cout << x.nume << ' ' << x.punctaj << '\n';
    return 0;
}
