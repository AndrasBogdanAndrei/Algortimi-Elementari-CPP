/*
 * Titlu: priority_queue — cele mai mari k valori
 * Clasa: 12
 * Capitol: Structuri de date și STL
 * Descriere: priority_queue este un heap: top() dă elementul „cel mai important”,
 *            iar push și pop costă O(log dimensiune). Implicit vârful este maximul;
 *            cu greater<long long> vârful devine minimul. Ca să aflăm cele mai mari
 *            k valori dintre n fără să sortăm tot, ținem un heap de minim cu cel
 *            mult k elemente: adăugăm fiecare valoare și, dacă heap-ul a depășit k,
 *            scoatem minimul. La final heap-ul conține exact cele mai mari k
 *            valori; le scoatem (crescător) și le afișăm descrescător.
 * Complexitate: O(n log k)
 *
 * Exemplu
 * Intrare:
 * 8 3
 * 5 1 9 3 7 9 2 8
 * Ieșire: 9 9 8
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 4 -2 6
 * Ieșire: 6 4 -2
 */
#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    priority_queue<long long, vector<long long>, greater<long long>> heap;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        heap.push(x);
        if ((int)heap.size() > k)
            heap.pop(); // scoatem cea mai mică valoare păstrată
    }
    vector<long long> rez;
    while (!heap.empty())
    {
        rez.push_back(heap.top());
        heap.pop();
    }
    for (int i = (int)rez.size() - 1; i >= 0; i--)
        cout << rez[i] << (i > 0 ? ' ' : '\n');
    return 0;
}
