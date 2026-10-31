/*
 * Titlu: Funcția Ackermann
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Funcția Ackermann are două argumente: A(0, n) = n + 1;
 *            A(m, 0) = A(m - 1, 1); A(m, n) = A(m - 1, A(m, n - 1)). Valorile cresc
 *            extrem de repede (A(4, 2) are aproape 20 000 de cifre), de aceea se
 *            folosește doar cu valori mici (m <= 3, n <= 5). Merită ținut minte:
 *            A(1, n) = n + 2, A(2, n) = 2n + 3, A(3, n) = 2^(n+3) - 3.
 * Complexitate: crește mai repede decât orice funcție exponențială
 *
 * Exemplu
 * Intrare: 2 3
 * Ieșire: 9
 *
 * Exemplu
 * Intrare: 3 3
 * Ieșire: 61
 */
#include <iostream>
using namespace std;

long long ackermann(long long m, long long n)
{
    if (m == 0)
        return n + 1;
    if (n == 0)
        return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main()
{
    long long m, n;
    cin >> m >> n;
    cout << ackermann(m, n) << '\n';
    return 0;
}
