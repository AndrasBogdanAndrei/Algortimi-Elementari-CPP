/*
 * Titlu: Înmulțirea a două numere mari
 * Clasa: 12
 * Capitol: Numere mari
 * Descriere: Cifra a[i] (rangul 10^i) înmulțită cu cifra b[j] (rangul 10^j)
 *            contribuie la rangul 10^(i+j). Adunăm întâi toate produsele în
 *            c[i + j], fără să ne ocupăm de transport, apoi facem o singură
 *            trecere de la unități în care păstrăm c[i] % 10 și ducem c[i] / 10
 *            la rangul următor. Produsul are cel mult k1 + k2 cifre.
 * Complexitate: O(k1 * k2), unde k1 și k2 sunt numerele de cifre
 *
 * Exemplu
 * Intrare: 12345678901234567890 98765432109876543210
 * Ieșire: 1219326311370217952237463801111263526900
 *
 * Exemplu
 * Intrare: 999 999
 * Ieșire: 998001
 *
 * Exemplu
 * Intrare: 123456789123456789 0
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

vector<int> inmulteste(const vector<int> &a, const vector<int> &b)
{
    // Folosim long long: c[i + j] poate aduna multe produse de câte cel mult 81.
    vector<long long> c(a.size() + b.size(), 0);
    for (int i = 0; i < (int)a.size(); i++)
        for (int j = 0; j < (int)b.size(); j++)
            c[i + j] += a[i] * b[j];
    vector<int> rez;
    long long transport = 0;
    for (int i = 0; i < (int)c.size(); i++)
    {
        long long t = c[i] + transport;
        rez.push_back(t % 10);
        transport = t / 10;
    }
    while (transport > 0)
    {
        rez.push_back(transport % 10);
        transport /= 10;
    }
    while (rez.size() > 1 && rez.back() == 0)
        rez.pop_back();
    return rez;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    afiseazaNumar(inmulteste(citesteNumar(s1), citesteNumar(s2)));
    return 0;
}
