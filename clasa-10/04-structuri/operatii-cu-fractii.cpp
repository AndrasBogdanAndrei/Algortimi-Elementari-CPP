/*
 * Titlu: Operații cu fracții
 * Clasa: 10
 * Capitol: Tipul struct
 * Descriere: O fracție are două câmpuri, numărătorul a și numitorul b, deci o
 *            reprezentăm cu struct Fractie { long long a, b; }. O funcție poate
 *            întoarce o structură întreagă, așa că aduna(x, y) și inmulteste(x, y)
 *            întorc direct fracția rezultat. simplifica(f) primește fracția prin
 *            referință și o împarte la cmmdc(a, b). Formule: a/b + c/d = (ad + bc)/bd
 *            și a/b * c/d = ac/bd. Se citesc două fracții, se afișează suma și produsul.
 * Complexitate: O(log(numitor)) pentru simplificare
 *
 * Exemplu
 * Intrare: 1 2 1 3
 * Ieșire:
 * 5/6
 * 1/6
 *
 * Exemplu
 * Intrare: 3 4 5 6
 * Ieșire:
 * 19/12
 * 5/8
 */
#include <iostream>
using namespace std;

struct Fractie
{
    long long a, b;   // a = numărător, b = numitor
};

long long cmmdc(long long x, long long y)
{
    while (y != 0)
    {
        long long r = x % y;
        x = y;
        y = r;
    }
    return x;
}

void simplifica(Fractie &f)
{
    long long d = cmmdc(f.a, f.b);
    f.a /= d;
    f.b /= d;
}

Fractie aduna(Fractie x, Fractie y)
{
    Fractie r;
    r.a = x.a * y.b + y.a * x.b;
    r.b = x.b * y.b;
    simplifica(r);
    return r;
}

Fractie inmulteste(Fractie x, Fractie y)
{
    Fractie r;
    r.a = x.a * y.a;
    r.b = x.b * y.b;
    simplifica(r);
    return r;
}

void afiseaza(Fractie f)
{
    cout << f.a << '/' << f.b << '\n';
}

int main()
{
    Fractie x, y;
    cin >> x.a >> x.b >> y.a >> y.b;
    afiseaza(aduna(x, y));
    afiseaza(inmulteste(x, y));
    return 0;
}
