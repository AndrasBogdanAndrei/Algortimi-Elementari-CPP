/*
 * Titlu: Numărul minim de monede
 * Clasa: 11
 * Capitol: Programare dinamică
 * Descriere: Avem n tipuri de monede (din fiecare oricâte) și vrem să plătim exact suma S
 *            cu cât mai puține monede. Greedy-ul poate greși (pentru monedele 1, 3, 4 și
 *            S = 6 alege 4 + 1 + 1, dar 3 + 3 e mai bun). Programarea dinamică: min[s] este
 *            numărul minim de monede pentru suma s; min[0] = 0 și
 *            min[s] = 1 + min{ min[s - v] : v este o monedă, v ≤ s }. Ținem în ultima[s]
 *            moneda folosită la ultimul pas, ca să refacem plata. Se afișează numărul minim
 *            și monedele, sau „Imposibil”.
 * Complexitate: O(n · S) timp, O(S) memorie
 *
 * Exemplu
 * Intrare:
 * 3 6
 * 1 3 4
 * Ieșire:
 * 2
 * 3 3
 *
 * Exemplu
 * Intrare:
 * 2 7
 * 2 4
 * Ieșire: Imposibil
 */
#include <iostream>
using namespace std;

const int INF = 1000000000;
int v[105], minim[100005], ultima[100005];

int main()
{
    int n, S;
    cin >> n >> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    minim[0] = 0;
    for (int s = 1; s <= S; s++)
    {
        minim[s] = INF;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] <= s && minim[s - v[i]] + 1 < minim[s])
            {
                minim[s] = minim[s - v[i]] + 1;
                ultima[s] = v[i];
            }
        }
    }

    if (minim[S] >= INF)
    {
        cout << "Imposibil\n";
        return 0;
    }
    cout << minim[S] << '\n';
    for (int s = S; s > 0; s -= ultima[s])
    {
        cout << ultima[s] << ' ';
    }
    cout << '\n';
    return 0;
}
