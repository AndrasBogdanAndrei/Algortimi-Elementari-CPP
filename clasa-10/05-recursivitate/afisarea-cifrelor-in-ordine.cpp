/*
 * Titlu: Afișarea cifrelor în ordine, recursiv
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Contează unde punem afișarea față de autoapel. În inOrdine afișăm
 *            DUPĂ autoapel: întâi se termină apelul pentru n / 10 (care afișează
 *            cifrele din față), abia apoi afișăm ultima cifră, deci cifrele ies de
 *            la stânga la dreapta. În invers afișăm ÎNAINTE de autoapel, deci ultima
 *            cifră apare prima. Fără niciun vector, stiva de apeluri „ține minte”
 *            cifrele pentru noi.
 * Complexitate: O(k), unde k este numărul de cifre
 *
 * Exemplu
 * Intrare: 4096
 * Ieșire:
 * 4 0 9 6
 * 6 9 0 4
 */
#include <iostream>
using namespace std;

void inOrdine(int n)
{
    if (n > 9)
        inOrdine(n / 10);
    cout << n % 10 << ' ';     // după autoapel
}

void invers(int n)
{
    cout << n % 10 << ' ';     // înainte de autoapel
    if (n > 9)
        invers(n / 10);
}

int main()
{
    int n;
    cin >> n;
    inOrdine(n);
    cout << '\n';
    invers(n);
    cout << '\n';
    return 0;
}
