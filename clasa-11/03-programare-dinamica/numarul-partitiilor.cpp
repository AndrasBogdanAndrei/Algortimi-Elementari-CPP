/*
 * Titlu: Numărul partițiilor unui număr
 * Clasa: 11
 * Capitol: Programare dinamică
 * Descriere: În câte moduri se poate scrie n ca sumă de numere naturale nenule, fără să
 *            conteze ordinea termenilor? (4 = 4 = 3+1 = 2+2 = 2+1+1 = 1+1+1+1, deci 5.)
 *            Backtracking-ul le-ar enumera pe toate; aici doar le numărăm. Introducem
 *            pe rând termenii posibili t = 1, 2, ..., n. nr[s] este numărul de moduri de a
 *            scrie s folosind doar termenii introduși până acum; când adăugăm termenul t,
 *            nr[s] += nr[s - t] (pentru s crescător, ca t să poată fi folosit de mai multe
 *            ori). Inițial nr[0] = 1.
 * Complexitate: O(n²) timp, O(n) memorie
 *
 * Exemplu
 * Intrare: 5
 * Ieșire: 7
 *
 * Exemplu
 * Intrare: 10
 * Ieșire: 42
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    long long nr[205] = {0};
    cin >> n;
    nr[0] = 1;
    for (int t = 1; t <= n; t++)
    {
        for (int s = t; s <= n; s++)
        {
            nr[s] += nr[s - t];
        }
    }
    cout << nr[n] << '\n';
    return 0;
}
