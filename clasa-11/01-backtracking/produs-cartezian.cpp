/*
 * Titlu: Produsul cartezian
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Se dau n mulțimi; mulțimea i este {1, 2, ..., a[i]}. Se afișează toate
 *            elementele produsului cartezian, adică toate șirurile (x1, ..., xn) cu
 *            1 ≤ xi ≤ a[i]. Orice valoare este validă pe orice poziție, deci nu există
 *            condiții de continuare: backtracking-ul doar enumeră. Numărul de soluții
 *            este a[1] · a[2] · ... · a[n].
 * Complexitate: O(a[1] · ... · a[n] · n) timp, O(n) memorie
 *
 * Exemplu
 * Intrare:
 * 2
 * 2 3
 * Ieșire:
 * 1 1
 * 1 2
 * 1 3
 * 2 1
 * 2 2
 * 2 3
 */
#include <iostream>
using namespace std;

int n, a[20], x[20];

void afiseaza()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i] << ' ';
    }
    cout << '\n';
}

void back(int k)
{
    for (int v = 1; v <= a[k]; v++)
    {
        x[k] = v;
        if (k == n)
        {
            afiseaza();
        }
        else
        {
            back(k + 1);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    back(1);
    return 0;
}
