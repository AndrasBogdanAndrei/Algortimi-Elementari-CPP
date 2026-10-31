/*
 * Titlu: Element majoritar (Boyer-Moore)
 * Clasa: 12
 * Capitol: Tehnici avansate: doi pointeri, căutare binară pe răspuns, stive monotone
 * Descriere: Elementul majoritar apare de mai mult de n / 2 ori. Algoritmul de
 *            vot ține un candidat și un contor: o valoare egală cu candidatul
 *            crește contorul, una diferită îl scade, iar la contor 0 valoarea
 *            curentă devine candidat. Ideea: dacă „anulăm” perechi de valori
 *            diferite, majoritarul nu poate fi anulat complet. Prima trecere dă
 *            doar un candidat, așa că a doua trecere numără aparițiile lui și
 *            verifică dacă e chiar majoritar. Funcționează pentru valori oricât
 *            de mari (nu are nevoie de vector de frecvență).
 * Complexitate: O(n) timp, O(1) memorie suplimentară
 *
 * Exemplu
 * Intrare:
 * 9
 * 3 1 3 3 2 3 3 1 3
 * Ieșire: 3
 *
 * Exemplu
 * Intrare:
 * 4
 * 1 2 1 2
 * Ieșire: nu exista
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long candidat = 0;
    int contor = 0;
    for (int i = 0; i < n; i++)
    {
        if (contor == 0)
        {
            candidat = a[i];
            contor = 1;
        }
        else if (a[i] == candidat)
            contor++;
        else
            contor--;
    }
    int aparitii = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == candidat)
            aparitii++;
    if (2 * aparitii > n)
        cout << candidat << '\n';
    else
        cout << "nu exista\n";
    return 0;
}
