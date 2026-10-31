/*
 * Titlu: Cel mai lung cuvânt
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Împărțim fraza în cuvinte cu strtok și păstrăm cuvântul cu lungimea
 *            cea mai mare într-un șir separat, copiindu-l cu strcpy (nu putem scrie
 *            celMaiLung = p, pentru că vectorii nu se atribuie). La egalitate rămâne
 *            primul cuvânt găsit. Se afișează cuvântul și lungimea lui.
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare: Programarea in C++ este distractiva
 * Ieșire: Programarea 11
 *
 * Exemplu
 * Intrare: un drum lung, apoi altul
 * Ieșire: altul 5
 */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256], celMaiLung[256] = "";
    cin.getline(s, 256);
    char *p = strtok(s, " ,.!?");
    while (p != NULL)
    {
        if (strlen(p) > strlen(celMaiLung))
            strcpy(celMaiLung, p);
        p = strtok(NULL, " ,.!?");
    }
    cout << celMaiLung << ' ' << strlen(celMaiLung) << '\n';
    return 0;
}
