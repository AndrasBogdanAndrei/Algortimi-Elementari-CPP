/*
 * Titlu: Verificarea unei puteri a lui 2
 * Clasa: 9
 * Capitol: Baze de numerație
 * Descriere: O putere a lui 2 are în baza 2 un singur bit de 1 (de exemplu
 *            64 = 1000000). Scăzând 1, acel bit devine 0 și toți biții din dreapta
 *            lui devin 1 (63 = 0111111), deci n & (n - 1) este 0 exact pentru
 *            puterile lui 2. Operatorul & face „și” bit cu bit.
 * Complexitate: O(1)
 *
 * Exemplu
 * Intrare: 64
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: 48
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n > 0 && (n & (n - 1)) == 0)
    {
        cout << "DA" << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
