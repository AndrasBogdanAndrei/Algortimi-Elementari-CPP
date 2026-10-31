/*
 * Titlu: Ciur cu cel mai mic divizor prim și factorizare rapidă
 * Clasa: 12
 * Capitol: Matematică pentru programare
 * Descriere: O variantă a ciurului lui Eratostene: în loc să marcăm doar „compus”,
 *            reținem în dp[x] cel mai mic divizor prim al lui x. Pentru fiecare
 *            prim p (dp[p] rămas 0) completăm dp[p], dp[2p], dp[3p], ... acolo unde
 *            încă e 0. Apoi orice x ≤ MAX se descompune foarte repede: împărțim
 *            repetat x la dp[x] și numărăm de câte ori apare fiecare prim. Pentru
 *            q întrebări, costul este un singur ciur plus câțiva pași pe întrebare.
 * Complexitate: O(MAX log log MAX) pentru ciur, O(log x) pentru fiecare factorizare
 *
 * Exemplu
 * Intrare:
 * 4
 * 360 97 1 1000000
 * Ieșire:
 * 360 = 2^3 * 3^2 * 5
 * 97 = 97
 * 1 = 1
 * 1000000 = 2^6 * 5^6
 */
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;

int main()
{
    vector<int> dp(MAX + 1, 0); // dp[x] = cel mai mic divizor prim al lui x
    for (int i = 2; i <= MAX; i++)
        if (dp[i] == 0) // i este prim
            for (int j = i; j <= MAX; j += i)
                if (dp[j] == 0)
                    dp[j] = i;

    int q;
    cin >> q;
    for (int t = 0; t < q; t++)
    {
        int x;
        cin >> x;
        cout << x << " = ";
        if (x == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        bool primul = true;
        while (x > 1)
        {
            int p = dp[x], e = 0;
            while (x % p == 0)
            {
                x /= p;
                e++;
            }
            if (!primul)
                cout << " * ";
            primul = false;
            cout << p;
            if (e > 1)
                cout << '^' << e;
        }
        cout << '\n';
    }
    return 0;
}
