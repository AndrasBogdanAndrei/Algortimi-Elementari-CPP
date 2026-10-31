/*
 * Titlu: Adunarea duratelor (ore, minute, secunde)
 * Clasa: 10
 * Capitol: Tipul struct
 * Descriere: O durată se ține într-o structură cu trei câmpuri. Ca să adunăm
 *            ușor, transformăm durata în secunde (h * 3600 + m * 60 + s), adunăm
 *            numerele și apoi refacem structura: orele sunt total / 3600, minutele
 *            (total % 3600) / 60, iar secundele total % 60. Se citesc n durate și
 *            se afișează durata totală.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 3
 * 1 45 30
 * 0 20 45
 * 2 0 50
 * Ieșire: 4 7 5
 */
#include <iostream>
using namespace std;

struct Durata
{
    int ore, minute, secunde;
};

long long inSecunde(Durata d)
{
    return d.ore * 3600LL + d.minute * 60 + d.secunde;
}

Durata dinSecunde(long long total)
{
    Durata d;
    d.ore = total / 3600;
    d.minute = total % 3600 / 60;
    d.secunde = total % 60;
    return d;
}

int main()
{
    int n;
    cin >> n;
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        Durata d;
        cin >> d.ore >> d.minute >> d.secunde;
        total += inSecunde(d);
    }
    Durata rez = dinSecunde(total);
    cout << rez.ore << ' ' << rez.minute << ' ' << rez.secunde << '\n';
    return 0;
}
