/*
 * Titlu: Minimizarea timpului mediu de așteptare
 * Clasa: 11
 * Capitol: Metoda greedy
 * Descriere: La un ghișeu așteaptă n clienți; servirea clientului i durează t[i] minute.
 *            Timpul de așteptare al unui client este suma duratelor clienților serviți
 *            înaintea lui. Ca media să fie minimă, servim clienții în ordinea crescătoare
 *            a duratelor: o durată scurtă pusă la început se adună la așteptarea celor
 *            mulți care urmează, una lungă se adună doar la puțini. La egalitate păstrăm
 *            ordinea de sosire. Se afișează ordinea servirii și timpul mediu (2 zecimale).
 * Complexitate: O(n log n)
 *
 * Exemplu
 * Intrare:
 * 4
 * 5 2 8 1
 * Ieșire:
 * 4 2 1 3
 * 3.00
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct client
{
    int durata, nr;
};

client a[1000];

bool maiScurt(const client &x, const client &y)
{
    if (x.durata != y.durata)
    {
        return x.durata < y.durata;
    }
    return x.nr < y.nr;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].durata;
        a[i].nr = i + 1;
    }
    sort(a, a + n, maiScurt);

    long long asteptare = 0, scurs = 0;
    for (int i = 0; i < n; i++)
    {
        cout << a[i].nr << ' ';
        asteptare += scurs;
        scurs += a[i].durata;
    }
    cout << '\n';
    cout << fixed << setprecision(2) << (double)asteptare / n << '\n';
    return 0;
}
