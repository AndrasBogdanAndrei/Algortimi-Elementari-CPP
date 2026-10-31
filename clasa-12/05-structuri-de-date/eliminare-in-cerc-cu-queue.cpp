/*
 * Titlu: queue — eliminarea din cerc
 * Clasa: 12
 * Capitol: Structuri de date și STL
 * Descriere: n copii, numerotați de la 1 la n, stau în cerc. Se numără din k în k,
 *            iar copilul la care se oprește numărătoarea iese din joc; numărarea
 *            continuă cu următorul. Simulăm cercul cu o coadă queue<int>: primii
 *            k - 1 copii din față sunt mutați la final (au fost „numărați”), iar
 *            al k-lea este scos definitiv și afișat. Repetăm până se golește
 *            coada. Afișăm ordinea în care ies copiii.
 * Complexitate: O(n * k)
 *
 * Exemplu
 * Intrare: 7 3
 * Ieșire: 3 6 2 7 5 1 4
 *
 * Exemplu
 * Intrare: 5 1
 * Ieșire: 1 2 3 4 5
 */
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    bool primul = true;
    while (!q.empty())
    {
        for (int pas = 1; pas < k; pas++)
        {
            q.push(q.front());
            q.pop();
        }
        if (!primul)
            cout << ' ';
        cout << q.front();
        primul = false;
        q.pop();
    }
    cout << '\n';
    return 0;
}
