/*
 * Titlu: Perechi de termeni consecutivi cu o proprietate
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Numărăm perechile de termeni aflați unul după altul care au
 *            aceeași paritate. Un șir de n termeni are n - 1 perechi
 *            consecutive; pentru fiecare termen nou x, perechea este (ant, x).
 *            Doi termeni au aceeași paritate exact când suma lor este pară.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 2 4 7 9 10 3
 * Ieșire: 2
 */
#include <iostream>
using namespace std;

int main()
{
    int n, perechi = 0;
    long long ant, x;
    cin >> n >> ant;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        if ((ant + x) % 2 == 0)
        {
            perechi++;
        }
        ant = x;
    }
    cout << perechi << '\n';
    return 0;
}
