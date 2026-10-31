/*
 * Titlu: Suma elementelor prin divide et impera
 * Clasa: 10
 * Capitol: Divide et impera
 * Descriere: Suma porțiunii [st, dr] este suma jumătății stângi [st, m] plus suma
 *            jumătății drepte [m + 1, dr]. O porțiune cu un singur element are suma
 *            egală cu acel element. Afișăm și numărul de apeluri: pentru n elemente
 *            se fac mereu 2n - 1 apeluri (n frunze și n - 1 noduri care împart).
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 2 3 4 5
 * Ieșire: 15 9
 *
 * Exemplu
 * Intrare:
 * 4
 * 10 -20 30 -40
 * Ieșire: -20 7
 */
#include <iostream>
using namespace std;

int v[1000], apeluri;

long long suma(int st, int dr)
{
    apeluri++;
    if (st == dr)
        return v[st];
    int m = (st + dr) / 2;
    return suma(st, m) + suma(m + 1, dr);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    long long s = suma(0, n - 1);
    cout << s << ' ' << apeluri << '\n';
    return 0;
}
