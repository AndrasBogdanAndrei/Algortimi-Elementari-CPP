/*
 * Titlu: Fișier — cea mai lungă secvență de termeni cu aceeași paritate
 * Clasa: 12
 * Capitol: Recapitulare pentru bacalaureat
 * Descriere: Cerința (tip subiectul III.3): fișierul date.in conține un șir de cel
 *            mult 10^6 numere naturale de cel mult 9 cifre. O secvență paritară
 *            este o secvență de termeni consecutivi care au toți aceeași paritate.
 *            Afișați lungimea maximă a unei secvențe paritare și numărul de
 *            secvențe paritare care au această lungime și nu pot fi prelungite.
 *            Eficiența: citim numerele pe rând și ținem doar paritatea
 *            termenului anterior și lungimea secvenței curente; la schimbarea
 *            parității secvența curentă s-a încheiat și o comparăm cu maximul.
 *            Nu folosim niciun tablou, deci memoria este constantă.
 * Complexitate: O(n) timp, O(1) memorie
 *
 * Exemplu
 * Intrare: 3 5 8 2 4 7 9 11 6
 * Ieșire: 3 2
 *
 * Exemplu
 * Intrare: 10
 * Ieșire: 1 1
 */
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream fin("date.in");
    long long x;
    int paritateAnt = -1, lung = 0, lungMax = 0, cate = 0;
    while (fin >> x)
    {
        int p = x % 2;
        if (p == paritateAnt)
            lung++;
        else
        {
            // s-a încheiat secvența anterioară (dacă exista una)
            if (lung > lungMax)
            {
                lungMax = lung;
                cate = 1;
            }
            else if (lung == lungMax && lung > 0)
                cate++;
            lung = 1;
            paritateAnt = p;
        }
    }
    // ultima secvență se încheie la sfârșitul fișierului
    if (lung > lungMax)
    {
        lungMax = lung;
        cate = 1;
    }
    else if (lung == lungMax && lung > 0)
        cate++;
    cout << lungMax << ' ' << cate << '\n';
    return 0;
}
