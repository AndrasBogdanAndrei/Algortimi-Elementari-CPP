/*
 * Titlu: Verificarea unui șir palindrom
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Întâi păstrăm doar literele, transformate în minuscule (așa
 *            „Ele fac cafele” devine „elefaccafele”). Apoi folosim doi indici: st
 *            pornește de la început, dr de la sfârșit; cât timp st < dr comparăm
 *            t[st] cu t[dr] și apropiem indicii. La prima pereche diferită șirul
 *            nu este palindrom.
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare: Ele fac cafele
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: Ana are mere
 * Ieșire: NU
 */
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char s[256], t[256];
    cin.getline(s, 256);

    int k = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (isalpha(s[i]))
            t[k++] = tolower(s[i]);
    t[k] = '\0';

    bool palindrom = true;
    int st = 0, dr = k - 1;
    while (st < dr && palindrom)
    {
        if (t[st] != t[dr])
            palindrom = false;
        st++;
        dr--;
    }
    cout << (palindrom ? "DA" : "NU") << '\n';
    return 0;
}
