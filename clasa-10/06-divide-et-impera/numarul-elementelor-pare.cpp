/*
 * Titlu: Numărul elementelor pare prin divide et impera
 * Clasa: 10
 * Capitol: Divide et impera
 * Descriere: Același tipar ca la sumă: rezultatul pentru porțiunea [st, dr] este
 *            suma rezultatelor celor două jumătăți. Diferă doar cazul elementar:
 *            o porțiune cu un singur element contribuie cu 1 dacă elementul este
 *            par și cu 0 altfel. Tiparul se poate adapta la orice numărare (elemente
 *            prime, negative, divizibile cu k etc.).
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 1 2 3 4 6 7
 * Ieșire: 3
 *
 * Exemplu
 * Intrare:
 * 3
 * 1 3 5
 * Ieșire: 0
 */
#include <iostream>
using namespace std;

int v[1000];

int numarPare(int st, int dr)
{
    if (st == dr)
        return v[st] % 2 == 0 ? 1 : 0;
    int m = (st + dr) / 2;
    return numarPare(st, m) + numarPare(m + 1, dr);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << numarPare(0, n - 1) << '\n';
    return 0;
}
