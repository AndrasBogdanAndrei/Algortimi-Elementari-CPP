/*
 * Titlu: Cel mai mic multiplu comun
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: Se folosește relația cmmdc(a, b) * cmmmc(a, b) = a * b. Calculăm
 *            cmmdc-ul cu algoritmul lui Euclid, pe copii ale lui a și b, apoi
 *            cmmmc = a / cmmdc * b (împărțim întâi, ca să nu depășim tipul).
 * Complexitate: O(log(min(a, b)))
 *
 * Exemplu
 * Intrare: 12 18
 * Ieșire: 36
 *
 * Exemplu
 * Intrare: 7 5
 * Ieșire: 35
 */
#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;
    long long x = a, y = b;
    while (y != 0)
    {
        long long r = x % y;
        x = y;
        y = r;
    }
    cout << a / x * b << '\n';
    return 0;
}
