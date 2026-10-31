/*
 * Titlu: Verificarea parantezelor cu o stivă
 * Clasa: 11
 * Capitol: Alocare dinamică: liste, stive, cozi
 * Descriere: Un șir format din paranteze ( ) [ ] { } este corect dacă fiecare paranteză
 *            deschisă se închide cu una de același tip, în ordinea potrivită. Parcurgem
 *            șirul: o paranteză deschisă se pune pe stivă; la una închisă, vârful stivei
 *            trebuie să fie perechea ei deschisă, pe care o scoatem. La final stiva trebuie
 *            să fie goală. Se afișează DA sau NU.
 * Complexitate: O(n) timp și memorie, unde n este lungimea șirului
 *
 * Exemplu
 * Intrare: {[()()]}
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: ([)]
 * Ieșire: NU
 *
 * Exemplu
 * Intrare: (()
 * Ieșire: NU
 */
#include <iostream>
#include <cstring>
using namespace std;

char s[10005], st[10005];
int vf = 0;

char pereche(char c)
{
    if (c == ')')
    {
        return '(';
    }
    if (c == ']')
    {
        return '[';
    }
    return '{';
}

int main()
{
    cin >> s;
    int n = strlen(s);
    bool corect = true;
    for (int i = 0; i < n && corect; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st[++vf] = s[i];
        }
        else if (vf > 0 && st[vf] == pereche(s[i]))
        {
            vf--;
        }
        else
        {
            corect = false;
        }
    }
    if (vf > 0)
    {
        corect = false;
    }
    cout << (corect ? "DA" : "NU") << '\n';
    return 0;
}
