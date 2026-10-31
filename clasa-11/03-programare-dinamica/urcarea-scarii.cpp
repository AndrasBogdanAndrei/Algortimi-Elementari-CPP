/*
 * Titlu: Numărul de moduri de a urca o scară
 * Clasa: 11
 * Capitol: Programare dinamică
 * Descriere: O scară are n trepte; la fiecare pas urcăm fie o treaptă, fie două. În câte
 *            moduri putem ajunge sus? Pe treapta i ajungem fie de pe treapta i - 1, fie de
 *            pe treapta i - 2, deci nr[i] = nr[i - 1] + nr[i - 2], cu nr[0] = nr[1] = 1.
 *            Calculăm valorile de jos în sus și fiecare subproblemă se rezolvă o singură
 *            dată (varianta recursivă directă ar recalcula aceleași valori de foarte multe
 *            ori). Rezultatul este un termen din șirul lui Fibonacci.
 * Complexitate: O(n) timp, O(n) memorie
 *
 * Exemplu
 * Intrare: 4
 * Ieșire: 5
 *
 * Exemplu
 * Intrare: 10
 * Ieșire: 89
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    long long nr[100];
    cin >> n;
    nr[0] = 1;
    nr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        nr[i] = nr[i - 1] + nr[i - 2];
    }
    cout << nr[n] << '\n';
    return 0;
}
