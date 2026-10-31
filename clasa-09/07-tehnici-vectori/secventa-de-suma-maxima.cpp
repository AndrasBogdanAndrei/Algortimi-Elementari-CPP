/*
 * Titlu: Secvența de sumă maximă (algoritmul lui Kadane)
 * Clasa: 9
 * Capitol: Frecvență, sume parțiale și ciurul lui Eratostene
 * Descriere: Parcurgem vectorul și păstrăm suma secvenței curente, care se
 *            termină la poziția i. Dacă suma de până acum a devenit negativă, nu
 *            ne mai ajută: începem o secvență nouă chiar de la i. După fiecare
 *            pas comparăm suma curentă cu cea mai bună de până acum. Se afișează
 *            suma maximă, apoi pozițiile de început și de sfârșit (prima găsită).
 *            Funcționează și când toate numerele sunt negative.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 8
 * -2 1 -3 4 -1 2 1 -5
 * Ieșire:
 * 6
 * 4 7
 *
 * Exemplu
 * Intrare:
 * 3
 * -5 -2 -8
 * Ieșire:
 * -2
 * 2 2
 */
#include <iostream>
using namespace std;

int v[100001];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    long long suma = 0, sumaMax = v[1];
    int inceput = 1, stMax = 1, drMax = 1;
    for (int i = 1; i <= n; i++)
    {
        if (suma < 0)
        {
            suma = 0;
            inceput = i;
        }
        suma = suma + v[i];
        if (suma > sumaMax)
        {
            sumaMax = suma;
            stMax = inceput;
            drMax = i;
        }
    }
    cout << sumaMax << '\n' << stMax << ' ' << drMax << '\n';
    return 0;
}
