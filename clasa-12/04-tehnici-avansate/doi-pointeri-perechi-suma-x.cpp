/*
 * Titlu: Doi pointeri — perechi cu suma x într-un vector sortat
 * Clasa: 12
 * Capitol: Tehnici avansate: doi pointeri, căutare binară pe răspuns, stive monotone
 * Descriere: Vectorul are n valori distincte, în ordine strict crescătoare. Vrem
 *            perechile de poziții i < j cu a[i] + a[j] = x. În loc să încercăm
 *            toate cele n * (n-1) / 2 perechi, punem un indice st la început și
 *            unul dr la sfârșit. Dacă a[st] + a[dr] < x, suma trebuie să crească,
 *            deci st++; dacă e mai mare, dr--; dacă e egală, am găsit o pereche
 *            și mutăm ambii indici. Fiecare pas mută cel puțin un indice spre
 *            celălalt, deci sunt cel mult n pași. Afișăm numărul perechilor, apoi
 *            perechile.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 8 10
 * 1 2 3 4 6 7 8 9
 * Ieșire:
 * 4
 * 1 9
 * 2 8
 * 3 7
 * 4 6
 *
 * Exemplu
 * Intrare:
 * 3 100
 * 1 2 3
 * Ieșire: 0
 */
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<long long, long long>> perechi;
    int st = 0, dr = n - 1;
    while (st < dr)
    {
        long long s = a[st] + a[dr];
        if (s < x)
            st++;
        else if (s > x)
            dr--;
        else
        {
            perechi.push_back({a[st], a[dr]});
            st++;
            dr--;
        }
    }
    cout << perechi.size() << '\n';
    for (auto &p : perechi)
        cout << p.first << ' ' << p.second << '\n';
    return 0;
}
