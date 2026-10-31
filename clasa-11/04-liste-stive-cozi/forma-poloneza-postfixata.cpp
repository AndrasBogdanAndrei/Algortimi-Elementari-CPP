/*
 * Titlu: Evaluarea unei expresii în formă poloneză postfixată
 * Clasa: 11
 * Capitol: Alocare dinamică: liste, stive, cozi
 * Descriere: În forma postfixată operatorul se scrie după operanzi: (3 + 4) * 2 devine
 *            3 4 + 2 *, iar parantezele nu mai sunt necesare. Citim elementele pe rând:
 *            un număr se pune pe stivă; la un operator scoatem doi operanzi (întâi pe cel
 *            din dreapta, apoi pe cel din stânga), calculăm și punem rezultatul înapoi.
 *            La final pe stivă rămâne valoarea expresiei. Operatori: + - * / (împărțirea
 *            este întreagă). Elementele sunt despărțite prin spații.
 * Complexitate: O(n), unde n este numărul de elemente ale expresiei
 *
 * Exemplu
 * Intrare: 3 4 + 2 *
 * Ieșire: 14
 *
 * Exemplu
 * Intrare: 5 1 2 + 4 * + 3 -
 * Ieșire: 14
 */
#include <iostream>
#include <string>
using namespace std;

long long st[10005];
int vf = 0;

int main()
{
    string element;
    while (cin >> element)
    {
        bool operatorul = element.size() == 1 &&
                          (element[0] == '+' || element[0] == '-' || element[0] == '*' || element[0] == '/');
        if (!operatorul)
        {
            st[++vf] = stoll(element);
            continue;
        }
        long long dreapta = st[vf--];
        long long stanga = st[vf--];
        long long rezultat;
        if (element[0] == '+')
        {
            rezultat = stanga + dreapta;
        }
        else if (element[0] == '-')
        {
            rezultat = stanga - dreapta;
        }
        else if (element[0] == '*')
        {
            rezultat = stanga * dreapta;
        }
        else
        {
            rezultat = stanga / dreapta;
        }
        st[++vf] = rezultat;
    }
    cout << st[vf] << '\n';
    return 0;
}
