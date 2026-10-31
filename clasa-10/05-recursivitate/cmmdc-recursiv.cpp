/*
 * Titlu: Cmmdc recursiv
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Algoritmul lui Euclid scris recursiv: cmmdc(a, 0) = a, iar
 *            cmmdc(a, b) = cmmdc(b, a % b). Autoapelul este ultima operație din
 *            funcție (recursivitate „de coadă”), deci nu mai rămâne nimic de calculat
 *            la întoarcere. Afișăm și numărul de apeluri, ca să vedem cât de repede
 *            se ajunge la rest 0.
 * Complexitate: O(log(min(a, b)))
 *
 * Exemplu
 * Intrare: 48 18
 * Ieșire: 6 4
 *
 * Exemplu
 * Intrare: 7 0
 * Ieșire: 7 1
 */
#include <iostream>
using namespace std;

int apeluri;

long long cmmdc(long long a, long long b)
{
    apeluri++;
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    long long d = cmmdc(a, b);
    cout << d << ' ' << apeluri << '\n';
    return 0;
}
