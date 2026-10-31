/*
 * Titlu: Factorialul unui număr mare
 * Clasa: 12
 * Capitol: Numere mari
 * Descriere: Deja 21! depășește long long, dar n! = 1 * 2 * ... * n se poate
 *            construi înmulțind repetat un număr mare cu un număr mic. Pornim de
 *            la vectorul cu o singură cifră, 1, și pentru i = 2, ..., n aplicăm
 *            înmulțirea cu i, cifră cu cifră, cu transport. Pentru n ≤ 1000
 *            rezultatul are sub 2600 de cifre.
 * Complexitate: O(n * L), unde L este numărul de cifre al lui n!
 *
 * Exemplu
 * Intrare: 25
 * Ieșire: 15511210043330985984000000
 *
 * Exemplu
 * Intrare: 30
 * Ieșire: 265252859812191058636308480000000
 *
 * Exemplu
 * Intrare: 0
 * Ieșire: 1
 */
#include <iostream>
#include <vector>
using namespace std;

void inmultesteMic(vector<int> &a, int k)
{
    long long transport = 0;
    for (int i = 0; i < (int)a.size(); i++)
    {
        long long t = (long long)a[i] * k + transport;
        a[i] = t % 10;
        transport = t / 10;
    }
    while (transport > 0)
    {
        a.push_back(transport % 10);
        transport /= 10;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> f(1, 1);
    for (int i = 2; i <= n; i++)
        inmultesteMic(f, i);
    for (int i = (int)f.size() - 1; i >= 0; i--)
        cout << f[i];
    cout << '\n';
    return 0;
}
