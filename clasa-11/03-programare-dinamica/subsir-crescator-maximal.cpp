/*
 * Titlu: Subșirul strict crescător de lungime maximă
 * Clasa: 11
 * Capitol: Programare dinamică
 * Descriere: Dintr-un șir de n numere alegem un subșir (elemente în ordinea din șir, nu
 *            neapărat alăturate) strict crescător și cât mai lung. L[i] este lungimea
 *            celui mai lung subșir crescător care începe cu a[i]. Calculăm de la dreapta
 *            la stânga: L[i] = 1 + max{ L[j] : j > i, a[j] > a[i] } (sau 1 dacă nu există
 *            un astfel de j). Răspunsul este cel mai mare L[i]. Pentru reconstituire pornim
 *            de la acel i și căutăm mereu primul j de după el cu a[j] > a[i] și
 *            L[j] = L[i] - 1. Se afișează lungimea și un subșir maximal.
 * Complexitate: O(n²) timp, O(n) memorie
 *
 * Exemplu
 * Intrare:
 * 8
 * 5 1 7 3 4 9 2 8
 * Ieșire:
 * 4
 * 1 3 4 9
 */
#include <iostream>
using namespace std;

int a[1005], L[1005];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = n; i >= 1; i--)
    {
        L[i] = 1;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] > a[i] && L[j] + 1 > L[i])
            {
                L[i] = L[j] + 1;
            }
        }
    }

    int start = 1;
    for (int i = 2; i <= n; i++)
    {
        if (L[i] > L[start])
        {
            start = i;
        }
    }
    cout << L[start] << '\n';

    int i = start;
    cout << a[i] << ' ';
    for (int j = i + 1; j <= n; j++)
    {
        if (a[j] > a[i] && L[j] == L[i] - 1)
        {
            cout << a[j] << ' ';
            i = j;
        }
    }
    cout << '\n';
    return 0;
}
