/*
 * Titlu: Cmmdc-ul mai multor numere
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: cmmdc(a, b, c) = cmmdc(cmmdc(a, b), c). Păstrăm în rez cmmdc-ul
 *            numerelor citite până acum și îl combinăm, cu algoritmul lui Euclid,
 *            cu fiecare număr nou. Pornim cu rez = 0, pentru că cmmdc(0, x) = x.
 * Complexitate: O(n · log M), unde M este valoarea maximă
 *
 * Exemplu
 * Intrare:
 * 4
 * 12 18 30 42
 * Ieșire: 6
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    long long x, rez = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        long long a = rez, b = x;
        while (b != 0)
        {
            long long r = a % b;
            a = b;
            b = r;
        }
        rez = a;
    }
    cout << rez << '\n';
    return 0;
}
