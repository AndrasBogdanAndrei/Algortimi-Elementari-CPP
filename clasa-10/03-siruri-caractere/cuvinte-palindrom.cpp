/*
 * Titlu: Cuvintele palindrom dintr-o frază
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Combinăm două lucruri învățate: strtok împarte fraza în cuvinte, iar
 *            funcția estePalindrom(p) verifică un cuvânt cu doi indici care se
 *            apropie dinspre capete. Se afișează cuvintele palindrom în ordinea în
 *            care apar sau NU EXISTA dacă nu este niciunul.
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare: ana are un capac si o cojoc rosu
 * Ieșire: ana capac o cojoc
 *
 * Exemplu
 * Intrare: ploua de azi
 * Ieșire: NU EXISTA
 */
#include <iostream>
#include <cstring>
using namespace std;

bool estePalindrom(char p[])
{
    int st = 0, dr = strlen(p) - 1;
    while (st < dr)
    {
        if (p[st] != p[dr])
            return false;
        st++;
        dr--;
    }
    return true;
}

int main()
{
    char s[256];
    cin.getline(s, 256);
    bool gasit = false;
    char *p = strtok(s, " ,.!?");
    while (p != NULL)
    {
        if (estePalindrom(p))
        {
            cout << p << ' ';
            gasit = true;
        }
        p = strtok(NULL, " ,.!?");
    }
    if (!gasit)
        cout << "NU EXISTA";
    cout << '\n';
    return 0;
}
