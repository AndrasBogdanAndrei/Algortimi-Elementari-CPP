/*
 * Titlu: Prelucrarea unui fișier pe linii
 * Clasa: 9
 * Capitol: Fișiere text
 * Descriere: getline(fin, linie) citește un rând întreg, cu tot cu spații, până
 *            la '\n'. Bucla while (getline(fin, linie)) se oprește la sfârșitul
 *            fișierului. Numărăm liniile și reținem linia cea mai lungă (prima,
 *            la egalitate); în date.out scriem numărul de linii și acea linie.
 * Complexitate: O(L), unde L este numărul total de caractere
 *
 * Exemplu
 * Intrare:
 * ana are mere
 * un rand ceva mai lung decat primul
 * scurt
 * Ieșire:
 * 3
 * un rand ceva mai lung decat primul
 */
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream fin("date.in");
    ofstream fout("date.out");
    string linie, ceaMaiLunga = "";
    int nrLinii = 0;
    while (getline(fin, linie))
    {
        nrLinii++;
        if (linie.size() > ceaMaiLunga.size())
        {
            ceaMaiLunga = linie;
        }
    }
    fout << nrLinii << '\n' << ceaMaiLunga << '\n';
    fin.close();
    fout.close();
    return 0;
}
