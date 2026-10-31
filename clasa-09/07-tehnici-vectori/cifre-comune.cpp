/*
 * Titlu: Cifrele comune a două numere
 * Clasa: 9
 * Capitol: Frecvență, sume parțiale și ciurul lui Eratostene
 * Descriere: Marcăm în doi vectori de 10 poziții ce cifre apar în fiecare
 *            număr (aparA[c], aparB[c]). Cifrele comune sunt cele marcate în
 *            ambii vectori; le afișăm crescător sau NU dacă nu există.
 * Complexitate: O(ka + kb), unde ka, kb sunt numerele de cifre
 *
 * Exemplu
 * Intrare: 72413 3017
 * Ieșire: 1 3 7
 *
 * Exemplu
 * Intrare: 222 135
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int main()
{
    long long a, b;
    bool aparA[10] = {false}, aparB[10] = {false};
    cin >> a >> b;
    do
    {
        aparA[a % 10] = true;
        a = a / 10;
    }
    while (a > 0);
    do
    {
        aparB[b % 10] = true;
        b = b / 10;
    }
    while (b > 0);
    bool exista = false;
    for (int c = 0; c <= 9; c++)
    {
        if (aparA[c] && aparB[c])
        {
            cout << c << ' ';
            exista = true;
        }
    }
    if (!exista)
    {
        cout << "NU";
    }
    cout << '\n';
    return 0;
}
