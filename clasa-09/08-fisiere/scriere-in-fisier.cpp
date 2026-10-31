/*
 * Titlu: Scrierea formatată într-un fișier
 * Clasa: 9
 * Capitol: Fișiere text
 * Descriere: Se citește n din date.in și se scriu în date.out numerele de la 1
 *            la n, câte cinci pe un rând. ofstream se folosește exact ca cout;
 *            un rând nou se scrie cu '\n' după fiecare al cincilea număr.
 *            Fișierul de ieșire este creat (sau golit) la deschidere.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare: 12
 * Ieșire:
 * 1 2 3 4 5
 * 6 7 8 9 10
 * 11 12
 */
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("date.in");
    ofstream fout("date.out");
    int n;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fout << i;
        if (i % 5 == 0 || i == n)
        {
            fout << '\n';
        }
        else
        {
            fout << ' ';
        }
    }
    fin.close();
    fout.close();
    return 0;
}
