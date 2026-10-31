/*
 * Titlu: Numărarea valorilor dintr-un fișier
 * Clasa: 9
 * Capitol: Fișiere text
 * Descriere: Fișierul date.in conține pe prima linie un număr natural k, iar pe
 *            următoarele linii un șir de numere naturale de lungime necunoscută.
 *            Citim până la sfârșitul fișierului și numărăm câte valori sunt în
 *            total, câte sunt divizibile cu k și care este cea mai mare dintre ele.
 *            Rezultatele se scriu în date.out, pe un rând.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 3
 * 9 4 12 7
 * 30 5 6
 * Ieșire: 7 4 30
 */
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("date.in");
    ofstream fout("date.out");
    long long k, x, maxim = -1;
    int total = 0, divizibile = 0;
    fin >> k;
    while (fin >> x)
    {
        total++;
        if (x % k == 0)
        {
            divizibile++;
        }
        if (x > maxim)
        {
            maxim = x;
        }
    }
    fout << total << ' ' << divizibile << ' ' << maxim << '\n';
    fin.close();
    fout.close();
    return 0;
}
