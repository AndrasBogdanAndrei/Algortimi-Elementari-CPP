/*
 * Titlu: Suma și media aritmetică
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Se citesc n și n numere întregi; se afișează suma și media lor
 *            aritmetică, cu două zecimale. La medie împărțim un număr real la n
 *            (1.0 * suma / n); suma / n ar fi o împărțire întreagă și ar pierde
 *            zecimalele.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 4
 * 1 2 3 5
 * Ieșire: 11 2.75
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    long long x, suma = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        suma = suma + x;
    }
    double media = 1.0 * suma / n;
    cout << suma << ' ' << fixed << setprecision(2) << media << '\n';
    return 0;
}
