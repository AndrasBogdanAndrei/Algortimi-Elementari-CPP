/*
 * Titlu: Frecvența literelor
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Numărăm de câte ori apare fiecare literă, fără să facem diferența între
 *            literele mari și cele mici: tolower(c) - 'a' dă poziția literei în
 *            vectorul de frecvență (0 pentru a, 25 pentru z). Afișăm, în ordine
 *            alfabetică, doar literele care apar, fiecare cu numărul de apariții.
 * Complexitate: O(L + 26)
 *
 * Exemplu
 * Intrare: Ana are mere
 * Ieșire:
 * a 3
 * e 3
 * m 1
 * n 1
 * r 2
 */
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char s[256];
    cin.getline(s, 256);
    int fr[26] = {0};
    for (int i = 0; s[i] != '\0'; i++)
        if (isalpha(s[i]))
            fr[tolower(s[i]) - 'a']++;

    for (int c = 0; c < 26; c++)
        if (fr[c] > 0)
            cout << char('a' + c) << ' ' << fr[c] << '\n';
    return 0;
}
