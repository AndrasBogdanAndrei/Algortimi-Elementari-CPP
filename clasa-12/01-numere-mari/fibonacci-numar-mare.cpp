/*
 * Titlu: Termenul n din șirul lui Fibonacci (număr mare)
 * Clasa: 12
 * Capitol: Numere mari
 * Descriere: Șirul este F(1) = F(2) = 1 și F(i) = F(i - 1) + F(i - 2). Termenii
 *            cresc exponențial (F(93) nu mai încape în long long), deci îi ținem
 *            ca numere mari. Păstrăm doar ultimii doi termeni, a și b; la fiecare
 *            pas calculăm c = a + b prin adunare cu transport, apoi a devine b și
 *            b devine c. Termenul F(n) are aproximativ 0,21 * n cifre.
 * Complexitate: O(n * L), unde L este numărul de cifre al lui F(n)
 *
 * Exemplu
 * Intrare: 100
 * Ieșire: 354224848179261915075
 *
 * Exemplu
 * Intrare: 1
 * Ieșire: 1
 *
 * Exemplu
 * Intrare: 10
 * Ieșire: 55
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> aduna(const vector<int> &a, const vector<int> &b)
{
    vector<int> c;
    int transport = 0;
    int k = max(a.size(), b.size());
    for (int i = 0; i < k; i++)
    {
        int s = transport;
        if (i < (int)a.size())
            s += a[i];
        if (i < (int)b.size())
            s += b[i];
        c.push_back(s % 10);
        transport = s / 10;
    }
    if (transport > 0)
        c.push_back(transport);
    return c;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(1, 1), b(1, 1); // F(1) și F(2)
    for (int i = 3; i <= n; i++)
    {
        vector<int> c = aduna(a, b);
        a = b;
        b = c;
    }
    // Pentru n = 1 sau n = 2 rezultatul este b = 1.
    for (int i = (int)b.size() - 1; i >= 0; i--)
        cout << b[i];
    cout << '\n';
    return 0;
}
