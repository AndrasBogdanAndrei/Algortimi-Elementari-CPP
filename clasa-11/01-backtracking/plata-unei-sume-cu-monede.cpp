/*
 * Titlu: Plata unei sume cu monede date
 * Clasa: 11
 * Capitol: Metoda backtracking
 * Descriere: Avem n tipuri de monede, cu valorile v[1..n], din fiecare câte vrem.
 *            Afișăm toate modurile de a plăti exact suma S. x[k] este numărul de monede
 *            de tipul k și ia valori de la 0 până la cât mai încape în suma rămasă.
 *            Ultimul tip de monedă nu mai are de ales: trebuie să acopere exact restul.
 *            Fiecare soluție se afișează ca sumă de termeni numar*valoare.
 * Complexitate: exponențială în n (numărul de combinații încercate)
 *
 * Exemplu
 * Intrare:
 * 3 5
 * 1 2 5
 * Ieșire:
 * 1*5
 * 1*1 + 2*2
 * 3*1 + 1*2
 * 5*1
 * Moduri: 4
 */
#include <iostream>
using namespace std;

int n, S, v[20], x[20], moduri = 0;

void afiseaza()
{
    bool primul = true;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] > 0)
        {
            if (!primul)
            {
                cout << " + ";
            }
            cout << x[i] << '*' << v[i];
            primul = false;
        }
    }
    cout << '\n';
}

void back(int k, int ramas)
{
    if (k == n)
    {
        // ultimul tip trebuie să acopere exact restul
        if (ramas % v[n] == 0)
        {
            x[n] = ramas / v[n];
            moduri++;
            afiseaza();
        }
        return;
    }
    for (int c = 0; c * v[k] <= ramas; c++)
    {
        x[k] = c;
        back(k + 1, ramas - c * v[k]);
    }
}

int main()
{
    cin >> n >> S;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    back(1, S);
    cout << "Moduri: " << moduri << '\n';
    return 0;
}
