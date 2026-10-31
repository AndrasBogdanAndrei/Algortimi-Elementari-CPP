/*
 * Titlu: stack — verificarea parantezelor
 * Clasa: 12
 * Capitol: Structuri de date și STL
 * Descriere: Un șir cu paranteze (), [] și {} este corect dacă fiecare paranteză
 *            închisă se potrivește cu ultima paranteză deschisă rămasă neînchisă.
 *            „Ultima deschisă, prima închisă” este exact regula stivei: punem în
 *            stack<char> parantezele deschise, iar la una închisă verificăm că
 *            vârful este perechea ei și o scoatem. Șirul e corect dacă nu apare
 *            nicio nepotrivire și stiva rămâne goală la final.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare: {[()()]}
 * Ieșire: corect
 *
 * Exemplu
 * Intrare: ([)]
 * Ieșire: incorect
 *
 * Exemplu
 * Intrare: (()
 * Ieșire: incorect
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

char deschisa(char c)
{
    if (c == ')')
        return '(';
    if (c == ']')
        return '[';
    return '{';
}

bool corect(const string &s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else
        {
            if (st.empty() || st.top() != deschisa(c))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s;
    cin >> s;
    cout << (corect(s) ? "corect" : "incorect") << '\n';
    return 0;
}
