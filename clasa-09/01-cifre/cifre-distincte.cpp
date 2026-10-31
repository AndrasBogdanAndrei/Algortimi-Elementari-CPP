/*
 * Titlu: Verificarea cifrelor distincte
 * Clasa: 9
 * Capitol: Cifrele unui număr
 * Descriere: Verifică dacă toate cifrele lui n sunt diferite. Ținem minte ce
 *            cifre am văzut deja (vazut[c] devine true la prima apariție a lui c);
 *            dacă dăm peste o cifră deja văzută, răspunsul este NU.
 * Complexitate: O(k), unde k este numărul de cifre ale lui n
 *
 * Exemplu
 * Intrare: 9071
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: 1231
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int main()
{
    long long n;
    bool vazut[10] = {false};
    bool distincte = true;
    cin >> n;
    do
    {
        int cifra = n % 10;
        if (vazut[cifra])
        {
            distincte = false;
        }
        vazut[cifra] = true;
        n = n / 10;
    }
    while (n > 0);
    if (distincte)
    {
        cout << "DA" << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
