/*
 * Titlu: Colorarea hărților
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: O hartă are n țări numerotate de la 1, iar m perechi (a, b) spun că țările
 *            a și b sunt vecine. Colorăm fiecare țară cu una dintre culorile 1..4 astfel
 *            încât două țări vecine să aibă culori diferite. x[k] este culoarea țării k;
 *            ea e validă dacă diferă de culorile vecinilor deja colorați (cei cu indice
 *            mai mic). Se afișează prima colorare găsită (cea mai mică lexicografic).
 * Complexitate: O(4^n · n) în cel mai rău caz, de obicei mult mai puțin
 *
 * Exemplu
 * Intrare:
 * 5 7
 * 1 2
 * 1 3
 * 2 3
 * 2 4
 * 3 4
 * 4 5
 * 3 5
 * Ieșire: 1 2 3 1 2
 */
#include <iostream>
using namespace std;

int n, m, x[50];
bool vecin[50][50], gasit = false;

bool valid(int k)
{
    for (int i = 1; i < k; i++)
    {
        if (vecin[i][k] && x[i] == x[k])
        {
            return false;
        }
    }
    return true;
}

void back(int k)
{
    for (int c = 1; c <= 4 && !gasit; c++)
    {
        x[k] = c;
        if (valid(k))
        {
            if (k == n)
            {
                gasit = true;
                for (int i = 1; i <= n; i++)
                {
                    cout << x[i] << ' ';
                }
                cout << '\n';
            }
            else
            {
                back(k + 1);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        vecin[a][b] = vecin[b][a] = true;
    }
    back(1);
    if (!gasit)
    {
        cout << "Nu exista colorare cu 4 culori\n";
    }
    return 0;
}
