/*
 * Titlu: Împărțirea unui număr mare la un număr mic
 * Clasa: 12
 * Capitol: Numere mari
 * Descriere: Spre deosebire de adunare, împărțirea începe de la cifra cea mai
 *            semnificativă, exact ca la împărțirea „în colțuri” de pe hârtie.
 *            Ținem restul r; la fiecare cifră formăm r = r * 10 + a[i], cifra
 *            câtului este r / k, iar restul devine r % k. Câtul se obține astfel
 *            de la stânga la dreapta, deci îl punem pe poziția i, apoi tăiem
 *            zerourile din față. Programul afișează câtul și restul.
 * Complexitate: O(k1), unde k1 este numărul de cifre al deîmpărțitului
 *
 * Exemplu
 * Intrare: 1000000000000000000000 7
 * Ieșire:
 * 142857142857142857142
 * 6
 *
 * Exemplu
 * Intrare: 5 12
 * Ieșire:
 * 0
 * 5
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

// Calculează câtul a / k și pune restul în variabila rest.
vector<int> imparte(const vector<int> &a, long long k, long long &rest)
{
    vector<int> cat(a.size(), 0);
    rest = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--)
    {
        rest = rest * 10 + a[i];
        cat[i] = rest / k;
        rest = rest % k;
    }
    while (cat.size() > 1 && cat.back() == 0)
        cat.pop_back();
    return cat;
}

int main()
{
    string s;
    long long k, rest;
    cin >> s >> k;
    vector<int> cat = imparte(citesteNumar(s), k, rest);
    afiseazaNumar(cat);
    cout << rest << '\n';
    return 0;
}
