/*
 * Titlu: Transformarea în majuscule și minuscule
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: În tabelul ASCII literele mari 'A'..'Z' și cele mici 'a'..'z' sunt la
 *            distanță constantă: 'a' - 'A' = 32. O literă mică devine mare scăzând
 *            32 (s[i] = s[i] - 'a' + 'A'), iar invers adunând. Funcțiile toupper și
 *            tolower din <cctype> fac același lucru și lasă neschimbate celelalte
 *            caractere. Afișăm șirul cu majuscule, cu minuscule și apoi cu prima
 *            literă a fiecărui cuvânt mare, restul mici.
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare: ana ARE mERe
 * Ieșire:
 * ANA ARE MERE
 * ana are mere
 * Ana Are Mere
 */
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    char s[256], t[256];
    cin.getline(s, 256);
    int n = strlen(s);

    // majuscule, „de mână”
    strcpy(t, s);
    for (int i = 0; i < n; i++)
        if (t[i] >= 'a' && t[i] <= 'z')
            t[i] = t[i] - 'a' + 'A';
    cout << t << '\n';

    // minuscule, cu tolower
    strcpy(t, s);
    for (int i = 0; i < n; i++)
        t[i] = tolower(t[i]);
    cout << t << '\n';

    // prima literă a fiecărui cuvânt mare
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || t[i - 1] == ' ')
            t[i] = toupper(t[i]);
    }
    cout << t << '\n';
    return 0;
}
