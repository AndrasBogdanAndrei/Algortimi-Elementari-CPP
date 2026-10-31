/*
 * Titlu: Cmmdc prin scăderi repetate
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Scădem numărul mai mic din cel mai mare până când devin egale;
 *            valoarea comună este cmmdc-ul. Merge doar pentru a, b > 0 (cu un 0
 *            bucla nu s-ar opri). Este mai lent decât varianta cu împărțiri:
 *            pentru 1000000 și 1 face aproape un milion de pași.
 * Complexitate: O(max(a, b)) în cazul cel mai rău
 *
 * Exemplu
 * Intrare: 48 18
 * Ieșire: 6
 */
#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    cout << a << '\n';
    return 0;
}
