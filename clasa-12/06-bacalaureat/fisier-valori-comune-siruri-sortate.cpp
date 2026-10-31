/*
 * Titlu: Fișier — valorile comune a două șiruri ordonate
 * Clasa: 12
 * Capitol: Recapitulare pentru bacalaureat
 * Descriere: Cerința (tip subiectul III.3): fișierul date.in conține pe prima
 *            linie n și m (1 ≤ n, m ≤ 10^5), pe a doua linie n numere naturale
 *            ordonate crescător, iar pe a treia m numere naturale ordonate
 *            crescător (valori de cel mult 9 cifre, se pot repeta). Afișați
 *            valorile care apar în ambele șiruri, fiecare o singură dată, în ordine
 *            crescătoare, sau „nu exista”. Eficiența: nu căutăm fiecare element al
 *            primului șir în al doilea (n * m pași), ci folosim ideea interclasării:
 *            doi indici, câte unul în fiecare șir; îl avansăm pe cel cu valoarea
 *            mai mică, iar la egalitate afișăm valoarea și o sărim în ambele șiruri.
 * Complexitate: O(n + m)
 *
 * Exemplu
 * Intrare:
 * 6 5
 * 1 3 3 5 8 10
 * 2 3 3 8 11
 * Ieșire: 3 8
 *
 * Exemplu
 * Intrare:
 * 2 2
 * 1 2
 * 3 4
 * Ieșire: nu exista
 */
#include <fstream>
#include <iostream>
using namespace std;

int a[100000], b[100000];

int main()
{
    ifstream fin("date.in");
    int n, m;
    fin >> n >> m;
    for (int i = 0; i < n; i++)
        fin >> a[i];
    for (int j = 0; j < m; j++)
        fin >> b[j];

    int i = 0, j = 0;
    bool gasit = false;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else
        {
            int v = a[i];
            cout << v << ' ';
            gasit = true;
            while (i < n && a[i] == v)
                i++;
            while (j < m && b[j] == v)
                j++;
        }
    }
    if (!gasit)
        cout << "nu exista";
    cout << '\n';
    return 0;
}
