/*
 * Titlu: Interschimbare prin referință
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: Comparăm două funcții care încearcă să schimbe între ele valorile a
 *            două variabile. schimbaValoare(int x, int y) primește copii, deci
 *            modificările se pierd la ieșirea din funcție. schimbaReferinta(int &x,
 *            int &y) primește chiar variabilele din main (prin referință, semnul &),
 *            așa că interschimbarea se vede și după apel.
 * Complexitate: O(1)
 *
 * Exemplu
 * Intrare: 3 7
 * Ieșire:
 * dupa transmiterea prin valoare: 3 7
 * dupa transmiterea prin referinta: 7 3
 */
#include <iostream>
using namespace std;

// x și y sunt copii: schimbarea nu ajunge înapoi în main.
void schimbaValoare(int x, int y)
{
    int aux = x;
    x = y;
    y = aux;
}

// x și y sunt alte nume pentru variabilele primite: schimbarea rămâne.
void schimbaReferinta(int &x, int &y)
{
    int aux = x;
    x = y;
    y = aux;
}

int main()
{
    int a, b;
    cin >> a >> b;
    schimbaValoare(a, b);
    cout << "dupa transmiterea prin valoare: " << a << ' ' << b << '\n';
    schimbaReferinta(a, b);
    cout << "dupa transmiterea prin referinta: " << a << ' ' << b << '\n';
    return 0;
}
