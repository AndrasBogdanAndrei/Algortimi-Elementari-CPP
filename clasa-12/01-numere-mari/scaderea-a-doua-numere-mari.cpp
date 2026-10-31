/*
 * Titlu: Scăderea a două numere mari
 * Clasa: 12
 * Capitol: Numere mari
 * Descriere: Calculăm A - B. Dacă A < B, calculăm B - A și punem semnul minus
 *            în față. Scădem de la unități: d = a[i] - b[i] - împrumut; dacă d
 *            iese negativ, adăugăm 10 și împrumutăm 1 de la rangul următor.
 *            La final eliminăm zerourile apărute în față (de exemplu 1000 - 999
 *            lasă cifrele 0001, adică 1).
 * Complexitate: O(k), unde k este numărul de cifre al celui mai mare număr
 *
 * Exemplu
 * Intrare: 100000000000000000000 1
 * Ieșire: 99999999999999999999
 *
 * Exemplu
 * Intrare: 25 1000
 * Ieșire: -975
 *
 * Exemplu
 * Intrare: 777 777
 * Ieșire: 0
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> citesteNumar(const string &s)
{
    vector<int> a;
    for (int i = (int)s.size() - 1; i >= 0; i--)
        a.push_back(s[i] - '0');
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return a;
}

void afiseazaNumar(const vector<int> &a)
{
    for (int i = (int)a.size() - 1; i >= 0; i--)
        cout << a[i];
    cout << '\n';
}

int compara(const vector<int> &a, const vector<int> &b)
{
    if (a.size() != b.size())
        return a.size() < b.size() ? -1 : 1;
    for (int i = (int)a.size() - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
            return a[i] < b[i] ? -1 : 1;
    }
    return 0;
}

// Presupune a >= b.
vector<int> scade(const vector<int> &a, const vector<int> &b)
{
    vector<int> c;
    int imprumut = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        int d = a[i] - imprumut;
        if (i < (int)b.size())
            d -= b[i];
        if (d < 0)
        {
            d += 10;
            imprumut = 1;
        }
        else
            imprumut = 0;
        c.push_back(d);
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> a = citesteNumar(s1), b = citesteNumar(s2);
    if (compara(a, b) < 0)
    {
        cout << '-';
        afiseazaNumar(scade(b, a));
    }
    else
        afiseazaNumar(scade(a, b));
    return 0;
}
