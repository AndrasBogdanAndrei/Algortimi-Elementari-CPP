/*
 * Titlu: Al n-lea termen al șirului lui Fibonacci
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Șirul lui Fibonacci începe cu 1, 1 și fiecare termen este suma
 *            celor doi dinaintea lui: 1, 1, 2, 3, 5, 8, ... Nu avem nevoie de
 *            vector: păstrăm doar ultimii doi termeni (a și b) și îi „mutăm” la
 *            fiecare pas. Cu long long merge până la n = 92.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare: 10
 * Ieșire: 55
 *
 * Exemplu
 * Intrare: 1
 * Ieșire: 1
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    long long a = 1, b = 1;
    cin >> n;
    for (int i = 3; i <= n; i++)
    {
        long long c = a + b;
        a = b;
        b = c;
    }
    cout << b << '\n';
    return 0;
}
