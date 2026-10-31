/*
 * Titlu: Numărul de schimbări de semn
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Se citesc n numere nenule. O schimbare de semn are loc între doi
 *            termeni consecutivi de semne opuse, adică atunci când produsul lor
 *            este negativ. Comparăm semnele (ant < 0) != (x < 0) în loc să
 *            înmulțim, ca produsul să nu depășească tipul de date.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 7
 * 3 -1 -4 2 5 -6 8
 * Ieșire: 4
 */
#include <iostream>
using namespace std;

int main()
{
    int n, schimbari = 0;
    long long ant, x;
    cin >> n >> ant;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        if ((ant < 0) != (x < 0))
        {
            schimbari++;
        }
        ant = x;
    }
    cout << schimbari << '\n';
    return 0;
}
