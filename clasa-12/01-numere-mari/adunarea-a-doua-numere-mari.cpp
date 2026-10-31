/*
 * Titlu: Adunarea a două numere mari
 * Clasa: 12
 * Capitol: Numere mari
 * Descriere: Adunăm ca pe hârtie, de la unități spre stânga. La rangul i
 *            calculăm s = a[i] + b[i] + transport; cifra rezultatului este
 *            s % 10, iar noul transport este s / 10 (0 sau 1). Dacă un număr
 *            are mai puține cifre, considerăm cifrele lipsă egale cu 0. La final,
 *            un transport rămas devine o cifră nouă.
 * Complexitate: O(max(k1, k2)), unde k1 și k2 sunt numerele de cifre
 *
 * Exemplu
 * Intrare: 99999999999999999999 1
 * Ieșire: 100000000000000000000
 *
 * Exemplu
 * Intrare: 123456789123456789 987654321987654321
 * Ieșire: 1111111111111111110
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

vector<int> aduna(const vector<int> &a, const vector<int> &b)
{
    vector<int> c;
    int transport = 0;
    int k = max(a.size(), b.size());
    for (int i = 0; i < k; i++)
    {
        int s = transport;
        if (i < (int)a.size())
            s += a[i];
        if (i < (int)b.size())
            s += b[i];
        c.push_back(s % 10);
        transport = s / 10;
    }
    if (transport > 0)
        c.push_back(transport);
    return c;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    afiseazaNumar(aduna(citesteNumar(s1), citesteNumar(s2)));
    return 0;
}
