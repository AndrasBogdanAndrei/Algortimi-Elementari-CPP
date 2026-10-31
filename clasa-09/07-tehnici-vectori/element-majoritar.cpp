/*
 * Titlu: Elementul majoritar
 * Clasa: 9
 * Capitol: Frecvență, sume parțiale și ciurul lui Eratostene
 * Descriere: Elementul majoritar apare de mai mult de n / 2 ori. Algoritmul prin
 *            vot (Boyer-Moore) păstrează un candidat și un contor: un element egal
 *            cu candidatul crește contorul, unul diferit îl scade, iar la contor 0
 *            elementul curent devine noul candidat. Valorile diferite se „anulează”
 *            în perechi, deci doar majoritarul poate rămâne. La final numărăm
 *            aparițiile candidatului, pentru că s-ar putea să nu existe majoritar.
 * Complexitate: O(n), fără limită pentru mărimea valorilor
 *
 * Exemplu
 * Intrare:
 * 7
 * 2 3 2 2 5 2 2
 * Ieșire: 2
 *
 * Exemplu
 * Intrare:
 * 4
 * 1 2 1 2
 * Ieșire: NU
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
    int candidat = v[1], contor = 0;
    for (int i = 1; i <= n; i++)
    {
        if (contor == 0)
        {
            candidat = v[i];
            contor = 1;
        }
        else if (v[i] == candidat)
        {
            contor++;
        }
        else
        {
            contor--;
        }
    }
    int aparitii = 0;
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == candidat)
        {
            aparitii++;
        }
    }
    if (aparitii > n / 2)
    {
        cout << candidat << '\n';
    }
    else
    {
        cout << "NU" << '\n';
    }
    return 0;
}
