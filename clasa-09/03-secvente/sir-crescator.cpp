/*
 * Titlu: Verificarea unui șir crescător
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Șirul este crescător dacă fiecare număr este cel puțin egal cu
 *            cel dinaintea lui. Păstrăm numărul anterior în variabila ant și
 *            comparăm fiecare număr nou cu el. Citim totuși tot șirul, chiar
 *            dacă am găsit deja o pereche greșită. Pentru „strict crescător”
 *            condiția devine x <= ant.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 3 3 7 9
 * Ieșire: DA
 *
 * Exemplu
 * Intrare:
 * 4
 * 2 5 4 8
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    long long ant, x;
    bool crescator = true;
    cin >> n >> ant;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        if (x < ant)
        {
            crescator = false;
        }
        ant = x;
    }
    if (crescator)
    {
        cout << "DA" << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
