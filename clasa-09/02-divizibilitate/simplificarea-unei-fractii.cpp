/*
 * Titlu: Simplificarea unei fracții
 * Clasa: 9
 * Capitol: Divizibilitate și numere prime
 * Descriere: O fracție a / b devine ireductibilă dacă împărțim numărătorul și
 *            numitorul la cmmdc(a, b). Calculăm cmmdc-ul pe copii, ca să
 *            păstrăm valorile inițiale.
 * Complexitate: O(log(min(a, b)))
 *
 * Exemplu
 * Intrare: 84 36
 * Ieșire: 7 3
 *
 * Exemplu
 * Intrare: 5 9
 * Ieșire: 5 9
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
    cout << a / x << ' ' << b / x << '\n';
    return 0;
}
