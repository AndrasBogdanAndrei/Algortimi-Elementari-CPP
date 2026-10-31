/*
 * Titlu: Fiii, descendenții și ascendenții unui nod
 * Clasa: 11
 * Capitol: Arbori
 * Descriere: Arborele este dat prin vectorul de tați (t[rădăcină] = 0). Fiii lui x sunt
 *            nodurile i cu t[i] = x. Un nod y este descendent al lui x dacă, urcând din y din
 *            tată în tată, ajungem în x. Ascendenții lui x sunt nodurile întâlnite urcând din
 *            x până la rădăcină: tatăl, bunicul etc. Se afișează fiii și descendenții în ordine
 *            crescătoare, iar ascendenții de la tată spre rădăcină („niciunul” dacă nu există).
 * Complexitate: O(n · h), unde h este înălțimea arborelui
 *
 * Exemplu
 * Intrare:
 * 8
 * 3 3 0 1 1 2 4 2
 * 1
 * Ieșire:
 * Fii: 4 5
 * Descendenti: 4 5 7
 * Ascendenti: 3
 *
 * Exemplu
 * Intrare:
 * 8
 * 3 3 0 1 1 2 4 2
 * 7
 * Ieșire:
 * Fii: niciunul
 * Descendenti: niciunul
 * Ascendenti: 4 1 3
 */
#include <iostream>
using namespace std;

int t[100005];

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    cin >> x;

    bool exista = false;
    cout << "Fii:";
    for (int i = 1; i <= n; i++)
    {
        if (t[i] == x)
        {
            cout << ' ' << i;
            exista = true;
        }
    }
    cout << (exista ? "" : " niciunul") << '\n';

    exista = false;
    cout << "Descendenti:";
    for (int i = 1; i <= n; i++)
    {
        if (i == x)
        {
            continue;
        }
        int y = t[i];
        while (y != 0 && y != x)
        {
            y = t[y];
        }
        if (y == x)
        {
            cout << ' ' << i;
            exista = true;
        }
    }
    cout << (exista ? "" : " niciunul") << '\n';

    cout << "Ascendenti:";
    if (t[x] == 0)
    {
        cout << " niciunul";
    }
    for (int y = t[x]; y != 0; y = t[y])
    {
        cout << ' ' << y;
    }
    cout << '\n';
    return 0;
}
