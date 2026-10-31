/*
 * Titlu: deque — minimul pe ferestre de lungime k
 * Clasa: 12
 * Capitol: Structuri de date și STL
 * Descriere: Pentru fiecare secvență de k elemente consecutive vrem minimul.
 *            Ținem într-un deque pozițiile „candidate”, cu valori crescătoare de
 *            la față spre spate. Când vine a[i], scoatem din spate pozițiile cu
 *            valoare ≥ a[i] (nu vor mai fi niciodată minim, pentru că a[i] e mai
 *            mic și rămâne mai mult în fereastră), apoi adăugăm i. Din față
 *            scoatem poziția care a ieșit din fereastră (i - k). Minimul ferestrei
 *            care se termină în i este mereu a[front]. Fiecare poziție intră și
 *            iese o singură dată.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 8 3
 * 4 2 12 3 8 1 7 5
 * Ieșire: 2 2 3 1 1 1
 *
 * Exemplu
 * Intrare:
 * 4 1
 * 9 8 7 6
 * Ieșire: 9 8 7 6
 */
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    deque<int> dq;
    bool primul = true;
    for (int i = 0; i < n; i++)
    {
        while (!dq.empty() && a[dq.back()] >= a[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k)
            dq.pop_front();
        if (i >= k - 1) // fereastra [i - k + 1, i] este completă
        {
            if (!primul)
                cout << ' ';
            cout << a[dq.front()];
            primul = false;
        }
    }
    cout << '\n';
    return 0;
}
