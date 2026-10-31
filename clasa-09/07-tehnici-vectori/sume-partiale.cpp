/*
 * Titlu: Sume parțiale
 * Clasa: 9
 * Capitol: Frecvență, sume parțiale și ciurul lui Eratostene
 * Descriere: s[i] = v[1] + v[2] + ... + v[i], cu s[0] = 0, se calculează într-o
 *            singură trecere: s[i] = s[i - 1] + v[i]. Apoi suma pe orice interval
 *            [st, dr] este s[dr] - s[st - 1], în O(1). Se citesc n, vectorul,
 *            apoi q întrebări (st, dr), iar pentru fiecare se afișează suma.
 * Complexitate: O(n + q), față de O(n · q) dacă am aduna la fiecare întrebare
 *
 * Exemplu
 * Intrare:
 * 5
 * 2 4 1 3 5
 * 3
 * 1 3
 * 2 5
 * 4 4
 * Ieșire:
 * 7
 * 13
 * 3
 */
#include <iostream>
using namespace std;

long long s[100001];

int main()
{
    int n, q, x;
    cin >> n;
    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        s[i] = s[i - 1] + x;
    }
    cin >> q;
    for (int k = 1; k <= q; k++)
    {
        int st, dr;
        cin >> st >> dr;
        cout << s[dr] - s[st - 1] << '\n';
    }
    return 0;
}
