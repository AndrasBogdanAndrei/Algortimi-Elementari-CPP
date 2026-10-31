/*
 * Titlu: Vectorul de tați: rădăcină, frunze, niveluri, înălțime
 * Clasa: 11
 * Capitol: Arbori
 * Descriere: Un arbore cu rădăcină se poate memora prin vectorul de tați: t[i] este tatăl
 *            nodului i, iar pentru rădăcină t[i] = 0. Rădăcina este nodul cu t = 0. Frunzele
 *            sunt nodurile care nu apar ca tată al nimănui (nu au fii). Nivelul unui nod este
 *            numărul de muchii de pe drumul de la rădăcină la el (rădăcina este pe nivelul 0);
 *            îl aflăm urcând din tată în tată până la rădăcină. Înălțimea arborelui este
 *            nivelul maxim.
 * Complexitate: O(n · h), unde h este înălțimea arborelui
 *
 * Exemplu
 * Intrare:
 * 8
 * 3 3 0 1 1 2 4 2
 * Ieșire:
 * Radacina: 3
 * Frunze: 5 6 7 8
 * Niveluri: 1 1 0 2 2 2 3 2
 * Inaltime: 3
 */
#include <iostream>
using namespace std;

int t[100005], nrFii[100005];

int main()
{
    int n, radacina = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
        if (t[i] == 0)
        {
            radacina = i;
        }
        else
        {
            nrFii[t[i]]++;
        }
    }

    cout << "Radacina: " << radacina << '\n';
    cout << "Frunze:";
    for (int i = 1; i <= n; i++)
    {
        if (nrFii[i] == 0)
        {
            cout << ' ' << i;
        }
    }
    cout << '\n';

    int inaltime = 0;
    cout << "Niveluri:";
    for (int i = 1; i <= n; i++)
    {
        int nivel = 0;
        for (int x = i; t[x] != 0; x = t[x])
        {
            nivel++;
        }
        cout << ' ' << nivel;
        if (nivel > inaltime)
        {
            inaltime = nivel;
        }
    }
    cout << '\n';
    cout << "Inaltime: " << inaltime << '\n';
    return 0;
}
