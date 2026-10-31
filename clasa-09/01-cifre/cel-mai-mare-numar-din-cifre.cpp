/*
 * Titlu: Cel mai mare număr format cu cifrele lui n
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Numărăm de câte ori apare fiecare cifră, într-un vector de
 *            frecvență cu 10 poziții (frecv[c] = de câte ori apare cifra c).
 *            Cel mai mare număr se obține scriind cifrele de la 9 spre 0,
 *            fiecare de câte ori apare.
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 31415
 * Ieșire: 54311
 *
 * Exemplu
 * Intrare: 1020
 * Ieșire: 2100
 */
#include <iostream>
using namespace std;

int main()
{
    long long n, rez = 0;
    int frecv[10] = {0};
    cin >> n;
    do
    {
        frecv[n % 10]++;
        n = n / 10;
    }
    while (n > 0);
    for (int c = 9; c >= 0; c--)
    {
        for (int i = 1; i <= frecv[c]; i++)
        {
            rez = rez * 10 + c;
        }
    }
    cout << rez << '\n';
    return 0;
}
