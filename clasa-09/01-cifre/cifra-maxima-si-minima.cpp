/*
 * Titlu: Cifra maximă și cifra minimă
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Pornim cu maximul 0 (cea mai mică cifră posibilă) și minimul 9
 *            (cea mai mare cifră posibilă), apoi comparăm fiecare cifră cu ele.
 *            Folosim do-while pentru ca n = 0 să aibă maximul și minimul 0.
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 52918
 * Ieșire: 9 1
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    int cifraMax = 0, cifraMin = 9;
    cin >> n;
    do
    {
        int cifra = n % 10;
        if (cifra > cifraMax)
        {
            cifraMax = cifra;
        }
        if (cifra < cifraMin)
        {
            cifraMin = cifra;
        }
        n = n / 10;
    }
    while (n > 0);
    cout << cifraMax << ' ' << cifraMin << '\n';
    return 0;
}
