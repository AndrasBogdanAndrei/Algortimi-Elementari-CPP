/*
 * Titlu: Numere prietene
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: Două numere a și b sunt prietene dacă suma divizorilor proprii ai lui a
 *            (divizorii mai mici decât a) este b și suma divizorilor proprii ai lui b
 *            este a. Exemplul clasic: 220 și 284. Funcția sumaDivizoriProprii(x)
 *            parcurge divizorii în perechi (d și x / d) până la radical din x.
 * Complexitate: O(sqrt(a) + sqrt(b))
 *
 * Exemplu
 * Intrare: 220 284
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: 10 20
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

long long sumaDivizoriProprii(long long x)
{
    if (x == 1)
        return 0;
    long long s = 1;   // 1 este divizor propriu al oricărui x > 1
    for (long long d = 2; d * d <= x; d++)
    {
        if (x % d == 0)
        {
            s = s + d;
            if (d != x / d)
                s = s + x / d;
        }
    }
    return s;
}

bool suntPrietene(long long a, long long b)
{
    return a != b && sumaDivizoriProprii(a) == b && sumaDivizoriProprii(b) == a;
}

int main()
{
    long long a, b;
    cin >> a >> b;
    if (suntPrietene(a, b))
        cout << "DA\n";
    else
        cout << "NU\n";
    return 0;
}
