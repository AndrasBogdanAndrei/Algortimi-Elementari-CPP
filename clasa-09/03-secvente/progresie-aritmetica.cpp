/*
 * Titlu: Verificarea unei progresii aritmetice
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Un șir este progresie aritmetică dacă diferența dintre doi termeni
 *            consecutivi este mereu aceeași (rația). Rația se află din primii doi
 *            termeni, apoi fiecare termen nou trebuie să fie ant + ratie.
 *            Se citesc n >= 2 numere.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 3 7 11 15 19
 * Ieșire: DA
 *
 * Exemplu
 * Intrare:
 * 4
 * 1 2 4 5
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    long long a, b, x;
    bool progresie = true;
    cin >> n >> a >> b;
    long long ratie = b - a;
    long long ant = b;
    for (int i = 3; i <= n; i++)
    {
        cin >> x;
        if (x - ant != ratie)
        {
            progresie = false;
        }
        ant = x;
    }
    if (progresie)
    {
        cout << "DA" << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
