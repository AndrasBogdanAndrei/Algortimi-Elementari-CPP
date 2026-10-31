/*
 * Titlu: Citirea până la sfârșitul fișierului
 * Clasa: 9
 * Capitol: Fișiere text
 * Descriere: Fișierul date.in conține numere întregi, dar nu știm câte. Expresia
 *            fin >> x întoarce „adevărat” cât timp citirea reușește și „fals” la
 *            sfârșitul fișierului, deci poate fi chiar condiția buclei.
 *            În date.out se scriu câte numere au fost și suma lor.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 3 8 -1
 * 10
 * Ieșire: 4 20
 */
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("date.in");
    ofstream fout("date.out");
    long long x, suma = 0;
    int numar = 0;
    while (fin >> x)
    {
        numar++;
        suma = suma + x;
    }
    fout << numar << ' ' << suma << '\n';
    fin.close();
    fout.close();
    return 0;
}
