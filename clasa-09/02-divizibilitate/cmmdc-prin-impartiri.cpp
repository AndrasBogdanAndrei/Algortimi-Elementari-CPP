/*
 * Titlu: Cmmdc prin împărțiri repetate (algoritmul lui Euclid)
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Cel mai mare divizor comun nu se schimbă dacă înlocuim perechea
 *            (a, b) cu (b, a % b). Repetăm până când b devine 0; atunci
 *            cmmdc-ul este a. Funcționează și când unul dintre numere este 0.
 * Complexitate: O(log(min(a, b)))
 *
 * Exemplu
 * Intrare: 48 18
 * Ieșire: 6
 *
 * Exemplu
 * Intrare: 7 0
 * Ieșire: 7
 */
#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    while (b != 0)
    {
        long long r = a % b;
        a = b;
        b = r;
    }
    cout << a << '\n';
    return 0;
}
