/*
 * Titlu: Problema celor n dame
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Așezăm n dame pe o tablă n × n astfel încât să nu se atace (nicio pereche
 *            pe aceeași linie, coloană sau diagonală). Punem câte o damă pe fiecare linie,
 *            iar x[k] este coloana damei de pe linia k. Dama k e validă dacă pentru orice
 *            linie i < k: x[i] ≠ x[k] (altă coloană) și |x[i] - x[k]| ≠ k - i (altă
 *            diagonală). Se afișează toate soluțiile și numărul lor.
 * Complexitate: exponențială; mult sub n^n datorită condițiilor de continuare
 *
 * Exemplu
 * Intrare: 4
 * Ieșire:
 * 2 4 1 3
 * 3 1 4 2
 * Total: 2
 *
 * Exemplu
 * Intrare: 3
 * Ieșire: Total: 0
 */
#include <iostream>
using namespace std;

int n, x[20], total = 0;

bool valid(int k)
{
    for (int i = 1; i < k; i++)
    {
        int dif = x[i] - x[k];
        if (dif < 0)
        {
            dif = -dif;
        }
        if (dif == 0 || dif == k - i)
        {
            return false;
        }
    }
    return true;
}

void back(int k)
{
    for (int c = 1; c <= n; c++)
    {
        x[k] = c;
        if (valid(k))
        {
            if (k == n)
            {
                total++;
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
    cin >> n;
    back(1);
    cout << "Total: " << total << '\n';
    return 0;
}
