/*
 * Titlu: Suma numerelor de pe fiecare linie
 * Clasa: 9
 * Capitol: Fișiere text
 * Descriere: Fiecare linie din date.in conține câteva numere întregi, în număr
 *            necunoscut. Citim linia cu getline, apoi o „recitim” ca pe un flux
 *            de numere cu istringstream (din <sstream>). Pentru fiecare linie
 *            scriem suma ei în date.out, pe câte un rând.
 * Complexitate: O(L), unde L este numărul total de caractere
 *
 * Exemplu
 * Intrare:
 * 1 2 3
 * 10 -4
 * 7
 * Ieșire:
 * 6
 * 6
 * 7
 */
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("date.in");
    ofstream fout("date.out");
    string linie;
    while (getline(fin, linie))
    {
        istringstream sirLinie(linie);
        long long x, suma = 0;
        while (sirLinie >> x)
        {
            suma = suma + x;
        }
        fout << suma << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
