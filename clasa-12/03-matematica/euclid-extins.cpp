/*
 * Titlu: Algoritmul lui Euclid extins
 * Clasa: 12
 * Capitol: Matematică pentru programare
 * Descriere: Pe lângă d = cmmdc(a, b), găsim numere întregi x și y cu
 *            a * x + b * y = d. Dacă b = 0, atunci d = a, x = 1, y = 0. Altfel
 *            rezolvăm recursiv pentru (b, a % b) și obținem x1, y1 cu
 *            b * x1 + (a % b) * y1 = d. Cum a % b = a - (a / b) * b, rezultă
 *            x = y1 și y = x1 - (a / b) * y1. Dacă d = 1, x (adus în [0, b)) este
 *            inversul lui a modulo b. Programul afișează d, x, y, apoi inversul
 *            sau mesajul „nu exista”.
 * Complexitate: O(log min(a, b))
 *
 * Exemplu
 * Intrare: 30 18
 * Ieșire:
 * 6 -1 2
 * nu exista
 *
 * Exemplu
 * Intrare: 3 11
 * Ieșire:
 * 1 4 -1
 * 4
 */
#include <iostream>
using namespace std;

long long euclidExtins(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = euclidExtins(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main()
{
    long long a, b, x, y;
    cin >> a >> b;
    long long d = euclidExtins(a, b, x, y);
    cout << d << ' ' << x << ' ' << y << '\n';
    if (d == 1)
        cout << ((x % b) + b) % b << '\n';
    else
        cout << "nu exista\n";
    return 0;
}
