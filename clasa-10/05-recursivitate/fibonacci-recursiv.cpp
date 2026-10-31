/*
 * Titlu: Fibonacci recursiv
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Șirul lui Fibonacci: F(0) = 0, F(1) = 1, F(n) = F(n - 1) + F(n - 2).
 *            Transcrierea directă are două autoapeluri, deci arborele apelurilor se
 *            dublează aproape la fiecare nivel, iar aceleași valori se recalculează
 *            de multe ori (F(3) apare de mai multe ori în arborele lui F(6)).
 *            Numărul de apeluri, afișat lângă rezultat, este 2 * F(n + 1) - 1.
 *            Varianta iterativă sau memorarea valorilor rezolvă problema în O(n).
 * Complexitate: O(φ^n) apeluri, φ ≈ 1.618 (exponențial)
 *
 * Exemplu
 * Intrare: 10
 * Ieșire: 55 177
 *
 * Exemplu
 * Intrare: 1
 * Ieșire: 1 1
 */
#include <iostream>
using namespace std;

long long apeluri;

long long fib(int n)
{
    apeluri++;
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    cin >> n;
    long long f = fib(n);
    cout << f << ' ' << apeluri << '\n';
    return 0;
}
