/*
 * Titlu: Numărul lipsă dintr-o permutare
 * Clasa: 9
 * Capitol: Frecvență, sume parțiale și ciurul lui Eratostene
 * Descriere: Se dau n și n - 1 numere distincte din mulțimea {1, 2, ..., n};
 *            unul singur lipsește. Suma tuturor numerelor de la 1 la n este
 *            n · (n + 1) / 2 (formula lui Gauss), așa că numărul lipsă este
 *            diferența dintre această sumă și suma numerelor citite. Nu e nevoie
 *            nici de vector, nici de sortare.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 3 1 5 2
 * Ieșire: 4
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, x, suma = 0;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x;
        suma = suma + x;
    }
    cout << n * (n + 1) / 2 - suma << '\n';
    return 0;
}
