/*
 * Titlu: Cel mai mare termen Fibonacci cel mult egal cu n
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Generăm termenii șirului lui Fibonacci (1, 1, 2, 3, 5, ...) cât
 *            timp următorul termen nu depășește n. Ultimul termen păstrat este
 *            răspunsul. Se presupune n >= 1.
 * Complexitate: O(log n), pentru că termenii cresc exponențial
 *
 * Exemplu
 * Intrare: 100
 * Ieșire: 89
 *
 * Exemplu
 * Intrare: 21
 * Ieșire: 21
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, a = 1, b = 1;
    cin >> n;
    while (a + b <= n)
    {
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << b << '\n';
    return 0;
}
