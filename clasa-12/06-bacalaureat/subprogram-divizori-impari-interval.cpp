/*
 * Titlu: Subprogram — câte numere dintr-un interval au un număr impar de divizori
 * Clasa: 12
 * Capitol: Recapitulare pentru bacalaureat
 * Descriere: Cerința (tip subiectul III.1): subprogramul impare are parametrii a și
 *            b (1 ≤ a ≤ b ≤ 10^12) și întoarce câte numere din [a, b] au un număr
 *            impar de divizori. Varianta directă numără divizorii fiecărui număr
 *            și ar face miliarde de operații. Observația care o face eficientă:
 *            divizorii lui x vin în perechi (d, x / d), cu excepția lui d = x / d,
 *            deci numărul lor e impar exact când x este pătrat perfect. Pătratele
 *            din [1, x] sunt 1^2, ..., r^2 cu r = partea întreagă din radical din
 *            x, deci răspunsul este r(b) - r(a - 1). Radicalul calculat cu sqrt se
 *            corectează cu două bucle scurte, ca să evităm erorile de rotunjire.
 * Complexitate: O(1)
 *
 * Exemplu
 * Intrare: 1 100
 * Ieșire: 10
 *
 * Exemplu
 * Intrare: 10 50
 * Ieșire: 4
 *
 * Exemplu
 * Intrare: 26 35
 * Ieșire: 0
 *
 * Exemplu
 * Intrare: 1 1000000000000
 * Ieșire: 1000000
 */
#include <cmath>
#include <iostream>
using namespace std;

// Cel mai mare r cu r * r <= x.
long long radical(long long x)
{
    long long r = (long long)sqrt((double)x);
    while (r * r > x)
        r--;
    while ((r + 1) * (r + 1) <= x)
        r++;
    return r;
}

long long impare(long long a, long long b)
{
    return radical(b) - radical(a - 1);
}

int main()
{
    long long a, b;
    cin >> a >> b;
    cout << impare(a, b) << '\n';
    return 0;
}
