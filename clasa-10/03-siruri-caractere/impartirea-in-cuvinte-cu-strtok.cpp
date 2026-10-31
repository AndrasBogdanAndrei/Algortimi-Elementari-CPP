/*
 * Titlu: Împărțirea în cuvinte cu strtok
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: strtok(s, separatori) întoarce primul cuvânt din s; apelurile
 *            următoare se fac cu NULL în loc de s și întorc pe rând celelalte
 *            cuvinte, până când rezultatul este NULL. Atenție: strtok scrie '\0'
 *            peste separatori, deci strică șirul inițial; dacă mai ai nevoie de el,
 *            lucrează pe o copie. Afișăm fiecare cuvânt pe un rând, cu lungimea lui.
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare: Azi, la ora de informatica, lucram cu siruri.
 * Ieșire:
 * Azi 3
 * la 2
 * ora 3
 * de 2
 * informatica 11
 * lucram 6
 * cu 2
 * siruri 6
 */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256];
    cin.getline(s, 256);
    char separatori[] = " ,.;:!?";
    char *p = strtok(s, separatori);
    while (p != NULL)
    {
        cout << p << ' ' << strlen(p) << '\n';
        p = strtok(NULL, separatori);
    }
    return 0;
}
