/*
 * Titlu: Generarea parantezărilor corecte
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Afișează, în ordine lexicografică ('(' înaintea lui ')'), toate șirurile
 *            corecte formate din n perechi de paranteze rotunde. Ținem numărul de paranteze
 *            deschise și închise până acum: putem pune '(' dacă deschise < n și putem
 *            pune ')' doar dacă inchise < deschise (altfel am închide ceva ce nu e deschis).
 *            Numărul soluțiilor este numărul lui Catalan: 1, 2, 5, 14, 42, ...
 * Complexitate: O(Catalan(n) · n) timp, O(n) memorie
 *
 * Exemplu
 * Intrare: 3
 * Ieșire:
 * ((()))
 * (()())
 * (())()
 * ()(())
 * ()()()
 */
#include <iostream>
using namespace std;

int n;
char x[50];

void back(int k, int deschise, int inchise)
{
    if (k == 2 * n)
    {
        x[k] = 0;
        cout << x << '\n';
        return;
    }
    if (deschise < n)
    {
        x[k] = '(';
        back(k + 1, deschise + 1, inchise);
    }
    if (inchise < deschise)
    {
        x[k] = ')';
        back(k + 1, deschise, inchise + 1);
    }
}

int main()
{
    cin >> n;
    back(0, 0, 0);
    return 0;
}
