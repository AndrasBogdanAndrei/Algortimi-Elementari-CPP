/*
 * Titlu: Numărarea vocalelor
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Pentru fiecare caracter verificăm dacă apare în șirul "aeiouAEIOU" cu
 *            funcția strchr: strchr(vocale, c) întoarce adresa primei apariții a
 *            lui c în vocale sau NULL dacă c nu apare. Așa evităm un if cu zece
 *            comparații. Se afișează numărul de vocale și numărul de consoane
 *            (literele care nu sunt vocale; spațiile și semnele nu se numără).
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare: Informatica este frumoasa
 * Ieșire: 11 12
 *
 * Exemplu
 * Intrare: Cxx, 2026!
 * Ieșire: 0 3
 */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    char s[256];
    cin.getline(s, 256);
    char vocale[] = "aeiouAEIOU";
    int nrVocale = 0, nrConsoane = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (strchr(vocale, s[i]) != NULL)
            nrVocale++;
        else if (isalpha(s[i]))
            nrConsoane++;
    }
    cout << nrVocale << ' ' << nrConsoane << '\n';
    return 0;
}
