/*
 * Titlu: Compararea a două numere mari
 * Clasa: 12
 * Capitol: Numere mari
 * Descriere: Fără zerouri nesemnificative, numărul cu mai multe cifre este mai
 *            mare. Dacă au același număr de cifre, le comparăm de la cifra cea
 *            mai semnificativă (ultimul indice din vector) spre unități; prima
 *            poziție pe care diferă decide rezultatul. Programul afișează unul
 *            dintre semnele <, = sau > între primul și al doilea număr.
 * Complexitate: O(k), unde k este numărul de cifre al numerelor
 *
 * Exemplu
 * Intrare: 123456789012345678901 99999999999999999999
 * Ieșire: >
 *
 * Exemplu
 * Intrare: 1234 1243
 * Ieșire: <
 *
 * Exemplu
 * Intrare: 0050 50
 * Ieșire: =
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

// Întoarce -1 dacă a < b, 0 dacă a = b și 1 dacă a > b.
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

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int r = compara(citesteNumar(s1), citesteNumar(s2));
    if (r < 0)
        cout << "<\n";
    else if (r == 0)
        cout << "=\n";
    else
        cout << ">\n";
    return 0;
}
