/*
 * Titlu: Înmulțirea unui număr mare cu un număr mic
 * Clasa: 12
 * Capitol: Numere mari
 * Descriere: Numărul mic k (cel mult 10^9) încape într-un int, deci nu trebuie
 *            despărțit în cifre. Pentru fiecare cifră a[i], de la unități,
 *            calculăm t = a[i] * k + transport (în long long, ca să nu depășim);
 *            cifra rezultatului este t % 10, iar transportul devine t / 10.
 *            Transportul rămas la final poate avea mai multe cifre, așa că îl
 *            descompunem cifră cu cifră. Dacă k = 0, rezultatul este 0.
 * Complexitate: O(k1 + c), unde k1 este numărul de cifre al numărului mare și c
 *               numărul de cifre al lui k
 *
 * Exemplu
 * Intrare: 123456789012345678901234567890 9
 * Ieșire: 1111111101111111110111111111010
 *
 * Exemplu
 * Intrare: 99999999999 1000000000
 * Ieșire: 99999999999000000000
 *
 * Exemplu
 * Intrare: 123456789 0
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

vector<int> inmultesteMic(const vector<int> &a, long long k)
{
    if (k == 0)
        return vector<int>(1, 0);
    vector<int> c;
    long long transport = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        long long t = a[i] * k + transport;
        c.push_back(t % 10);
        transport = t / 10;
    }
    while (transport > 0)
    {
        c.push_back(transport % 10);
        transport /= 10;
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}

int main()
{
    string s;
    long long k;
    cin >> s >> k;
    afiseazaNumar(inmultesteMic(citesteNumar(s), k));
    return 0;
}
