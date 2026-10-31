/*
 * Titlu: Acoperirea unui segment cu număr minim de intervale
 * Clasa: 11
 * Capitol: Metoda greedy
 * Descriere: Vrem să acoperim segmentul [A, B] folosind cât mai puține dintre cele n
 *            intervale date [s[i], f[i]]. Sortăm intervalele după capătul stâng. Ținem
 *            punctul „acoperit până la” (inițial A). Dintre intervalele care încep cel
 *            târziu în acest punct îl alegem pe cel care ajunge cel mai departe la
 *            dreapta, apoi mutăm punctul la capătul lui. Dacă niciun interval nu ne
 *            duce mai departe, acoperirea e imposibilă. Se afișează numărul de
 *            intervale și numerele lor de ordine, sau „Imposibil”.
 * Complexitate: O(n log n)
 *
 * Exemplu
 * Intrare:
 * 0 10
 * 5
 * 0 4
 * 2 6
 * 3 8
 * 5 10
 * 7 9
 * Ieșire:
 * 3
 * 1 3 4
 *
 * Exemplu
 * Intrare:
 * 0 5
 * 2
 * 1 3
 * 2 5
 * Ieșire: Imposibil
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct interval
{
    int st, dr, nr;
};

interval a[1000];

bool dupaStart(const interval &x, const interval &y)
{
    if (x.st != y.st)
    {
        return x.st < y.st;
    }
    return x.nr < y.nr;
}

int main()
{
    int A, B, n;
    cin >> A >> B >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].st >> a[i].dr;
        a[i].nr = i + 1;
    }
    sort(a, a + n, dupaStart);

    int ales[1000], cate = 0;
    int acoperit = A, i = 0;
    bool posibil = true;
    while (acoperit < B)
    {
        int celMaiDeparte = acoperit, care = -1;
        while (i < n && a[i].st <= acoperit)
        {
            if (a[i].dr > celMaiDeparte)
            {
                celMaiDeparte = a[i].dr;
                care = a[i].nr;
            }
            i++;
        }
        if (care == -1)
        {
            posibil = false;
            break;
        }
        ales[cate++] = care;
        acoperit = celMaiDeparte;
    }

    if (!posibil)
    {
        cout << "Imposibil\n";
        return 0;
    }
    cout << cate << '\n';
    for (int j = 0; j < cate; j++)
    {
        cout << ales[j] << ' ';
    }
    cout << '\n';
    return 0;
}
