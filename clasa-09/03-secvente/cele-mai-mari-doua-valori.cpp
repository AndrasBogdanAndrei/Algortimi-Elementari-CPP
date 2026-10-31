/*
 * Titlu: Cele mai mari două valori
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Ținem minte cea mai mare valoare (max1) și a doua (max2). Dacă
 *            numărul nou depășește max1, vechiul max1 coboară pe locul doi; altfel,
 *            dacă depășește max2, îl înlocuiește doar pe max2. O valoare care
 *            apare de două ori ocupă ambele locuri. Se citesc n >= 2 numere.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 5 9 2 9 7 1
 * Ieșire: 9 9
 *
 * Exemplu
 * Intrare:
 * 4
 * 3 8 6 1
 * Ieșire: 8 6
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    long long x, max1, max2;
    cin >> n >> max1 >> max2;
    if (max2 > max1)
    {
        long long aux = max1;
        max1 = max2;
        max2 = aux;
    }
    for (int i = 3; i <= n; i++)
    {
        cin >> x;
        if (x > max1)
        {
            max2 = max1;
            max1 = x;
        }
        else if (x > max2)
        {
            max2 = x;
        }
    }
    cout << max1 << ' ' << max2 << '\n';
    return 0;
}
