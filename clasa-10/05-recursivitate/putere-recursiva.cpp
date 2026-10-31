/*
 * Titlu: Puterea unui număr, recursiv
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Varianta directă folosește a^n = a * a^(n - 1) și face n apeluri.
 *            Varianta rapidă înjumătățește exponentul: dacă n este par,
 *            a^n = (a^(n/2))^2, altfel a^n = a * a^(n - 1). Rezultatul lui
 *            a^(n/2) se calculează o singură dată și se păstrează într-o variabilă,
 *            altfel câștigul se pierde. Se afișează rezultatul și numărul de apeluri
 *            făcute de fiecare variantă.
 * Complexitate: O(n) pentru varianta directă, O(log n) pentru cea rapidă
 *
 * Exemplu
 * Intrare: 2 10
 * Ieșire:
 * 1024 11
 * 1024 6
 *
 * Exemplu
 * Intrare: 3 0
 * Ieșire:
 * 1 1
 * 1 1
 */
#include <iostream>
using namespace std;

int apeluriDirect, apeluriRapid;

long long putere(long long a, int n)
{
    apeluriDirect++;
    if (n == 0)
        return 1;
    return a * putere(a, n - 1);
}

long long putereRapida(long long a, int n)
{
    apeluriRapid++;
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        long long jumatate = putereRapida(a, n / 2);
        return jumatate * jumatate;
    }
    return a * putereRapida(a, n - 1);
}

int main()
{
    long long a;
    int n;
    cin >> a >> n;
    long long r1 = putere(a, n);
    cout << r1 << ' ' << apeluriDirect << '\n';
    long long r2 = putereRapida(a, n);
    cout << r2 << ' ' << apeluriRapid << '\n';
    return 0;
}
