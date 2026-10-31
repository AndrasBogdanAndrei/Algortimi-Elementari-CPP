/*
 * Titlu: Eliminarea vocalelor
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Ștergem vocalele chiar în șirul inițial, cu doi indici: i citește
 *            fiecare caracter, k arată unde scriem următorul caracter păstrat.
 *            Consoanele și celelalte caractere se copiază pe poziția k, vocalele se
 *            sar. La final punem '\0' pe poziția k. Metoda face o singură trecere;
 *            varianta strcpy(s + i, s + i + 1) pentru fiecare vocală este mai lentă
 *            și, pentru că sursa și destinația se suprapun, nu este garantată de
 *            standard (folosește memmove dacă vrei să muți bucăți de șir).
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare: Informatica este frumoasa
 * Ieșire: nfrmtc st frms
 */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256];
    cin.getline(s, 256);
    int k = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (strchr("aeiouAEIOU", s[i]) == NULL)
            s[k++] = s[i];
    }
    s[k] = '\0';
    cout << s << '\n';
    return 0;
}
