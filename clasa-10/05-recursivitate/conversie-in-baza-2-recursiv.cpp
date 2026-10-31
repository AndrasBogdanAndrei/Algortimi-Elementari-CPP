/*
 * Titlu: Conversia în baza 2, recursiv
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: La conversia prin împărțiri repetate la 2, resturile se obțin în
 *            ordine inversă față de cum trebuie scrise. Recursivitatea rezolvă asta
 *            singură: întâi ne autoapelăm pentru n / 2 (care scrie cifrele din față)
 *            și abia apoi afișăm restul n % 2. Oprire: n < 2, când n este chiar
 *            singura cifră binară. Funcția baza(n, b) face același lucru pentru o
 *            bază oarecare b între 2 și 10.
 * Complexitate: O(log n)
 *
 * Exemplu
 * Intrare: 13
 * Ieșire:
 * 1101
 * 111
 *
 * Exemplu
 * Intrare: 0
 * Ieșire:
 * 0
 * 0
 */
#include <iostream>
using namespace std;

void baza2(int n)
{
    if (n >= 2)
        baza2(n / 2);
    cout << n % 2;
}

void baza(int n, int b)
{
    if (n >= b)
        baza(n / b, b);
    cout << n % b;
}

int main()
{
    int n;
    cin >> n;
    baza2(n);
    cout << '\n';
    baza(n, 3);      // aceeași idee, în baza 3
    cout << '\n';
    return 0;
}
