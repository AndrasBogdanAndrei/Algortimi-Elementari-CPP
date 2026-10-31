/*
 * Titlu: Citirea și afișarea unui număr mare
 * Clasa: 12
 * Capitol: Numere mari
 * Descriere: Un număr cu zeci sau sute de cifre nu încape în long long, așa că
 *            îl citim ca șir de caractere și îi păstrăm cifrele într-un vector,
 *            începând cu cifra unităților: a[0] = unități, a[1] = zeci etc.
 *            Așa, cifrele de același rang din două numere au același indice,
 *            iar transportul se propagă spre indici mai mari. Eliminăm zerourile
 *            nesemnificative de la început (păstrăm măcar o cifră) și afișăm
 *            numărul de la ultimul indice spre primul, apoi numărul de cifre.
 * Complexitate: O(k), unde k este numărul de cifre citite
 *
 * Exemplu
 * Intrare: 000098765432109876543210
 * Ieșire:
 * 98765432109876543210
 * 20
 *
 * Exemplu
 * Intrare: 0000
 * Ieșire:
 * 0
 * 1
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Transformă șirul de cifre în vector, de la unități spre cifra cea mai semnificativă.
vector<int> citesteNumar(const string &s)
{
    vector<int> a;
    for (int i = (int)s.size() - 1; i >= 0; i--)
        a.push_back(s[i] - '0');
    // Zerourile de la începutul șirului sunt acum la finalul vectorului.
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

int main()
{
    string s;
    cin >> s;
    vector<int> a = citesteNumar(s);
    afiseazaNumar(a);
    cout << a.size() << '\n';
    return 0;
}
