/*
 * Titlu: Numărarea elementelor cu o proprietate
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Se citesc n și n numere naturale. Numărăm câte dintre ele sunt
 *            pare și câte au ultima cifră egală cu prima. Fiecare proprietate
 *            are contorul ei, pornit de la 0 și mărit când proprietatea are loc.
 * Complexitate: O(n · k), unde k este numărul maxim de cifre
 *
 * Exemplu
 * Intrare:
 * 6
 * 4 717 10 3 828 15
 * Ieșire: 3 4
 */
#include <iostream>
using namespace std;

int main()
{
    int n, pare = 0, capete = 0;
    long long x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x % 2 == 0)
        {
            pare++;
        }
        long long prima = x;
        while (prima >= 10)
        {
            prima = prima / 10;
        }
        if (prima == x % 10)
        {
            capete++;
        }
    }
    cout << pare << ' ' << capete << '\n';
    return 0;
}
