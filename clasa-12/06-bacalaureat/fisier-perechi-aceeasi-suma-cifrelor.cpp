/*
 * Titlu: Fișier — perechi de numere cu aceeași sumă a cifrelor
 * Clasa: 12
 * Capitol: Recapitulare pentru bacalaureat
 * Descriere: Cerința (tip subiectul III.3): fișierul date.in conține pe prima
 *            linie n (2 ≤ n ≤ 10^6), apoi n numere naturale de cel mult 9 cifre.
 *            Afișați câte perechi de poziții i < j au termeni cu aceeași sumă a
 *            cifrelor. Varianta cu două bucle verifică n * (n-1) / 2 perechi (la
 *            n = 10^6, aproape 5 * 10^11). Varianta eficientă: suma cifrelor unui
 *            număr de cel mult 9 cifre este între 0 și 81, deci numărăm în f[s]
 *            câte numere au suma s. Din f[s] numere se pot forma
 *            f[s] * (f[s] - 1) / 2 perechi; adunăm pentru toate s. Rezultatul
 *            poate depăși int, de aceea folosim long long.
 * Complexitate: O(n * 9 + 82) timp, O(82) memorie
 *
 * Exemplu
 * Intrare:
 * 6
 * 12 21 7 30 106 999
 * Ieșire: 4
 *
 * Exemplu
 * Intrare:
 * 3
 * 1 2 3
 * Ieșire: 0
 */
#include <fstream>
#include <iostream>
using namespace std;

int sumaCifre(int x)
{
    int s = 0;
    while (x > 0)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main()
{
    ifstream fin("date.in");
    int n;
    long long f[82] = {0};
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        fin >> x;
        f[sumaCifre(x)]++;
    }
    long long perechi = 0;
    for (int s = 0; s <= 81; s++)
        perechi += f[s] * (f[s] - 1) / 2;
    cout << perechi << '\n';
    return 0;
}
