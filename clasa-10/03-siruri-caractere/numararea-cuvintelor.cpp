/*
 * Titlu: Numărarea cuvintelor
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Fără strtok: un cuvânt începe acolo unde un caracter diferit de spațiu
 *            urmează după un spațiu (sau se află chiar la începutul șirului). Numărăm
 *            aceste „începuturi”, așa că spațiile multiple dintre cuvinte sau de la
 *            capete nu încurcă numărătoarea.
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare: Ana   are    mere   si pere
 * Ieșire: 5
 *
 * Exemplu
 * Intrare: cuvant
 * Ieșire: 1
 */
#include <iostream>
using namespace std;

int main()
{
    char s[256];
    cin.getline(s, 256);
    int cuvinte = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
            cuvinte++;
    }
    cout << cuvinte << '\n';
    return 0;
}
