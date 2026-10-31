/*
 * Titlu: Număr palindrom
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Un număr este palindrom dacă se citește la fel de la stânga la
 *            dreapta și de la dreapta la stânga, adică este egal cu oglinditul
 *            său. Lucrăm pe o copie, pentru că bucla distruge numărul.
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 12321
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: 1231
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, copie, ogl = 0;
    cin >> n;
    copie = n;
    while (copie > 0)
    {
        ogl = ogl * 10 + copie % 10;
        copie = copie / 10;
    }
    if (ogl == n)
    {
        cout << "DA" << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
