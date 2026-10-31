/*
 * Titlu: Subprogram — eliminarea elementelor cu k cifre dintr-un tablou
 * Clasa: 12
 * Capitol: Recapitulare pentru bacalaureat
 * Descriere: Cerința (tip subiectul III.1): subprogramul elimina are parametrii v
 *            (un tablou cu n numere naturale), n și k; șterge din v toate
 *            elementele care au exact k cifre, păstrând ordinea celorlalte, și
 *            actualizează n. Ștergerea „clasică”, cu mutarea spre stânga a tuturor
 *            elementelor de după cel șters, poate face n^2 mutări. Varianta
 *            eficientă folosește un indice de scriere j: parcurgem tabloul o dată
 *            și copiem pe poziția j doar elementele care rămân. n se transmite
 *            prin referință (int &n), ca modificarea să se vadă în main.
 * Complexitate: O(n * c), unde c este numărul maxim de cifre al unui element
 *
 * Exemplu
 * Intrare:
 * 7 1
 * 12 5 340 7 99 1000 8
 * Ieșire: 12 340 99 1000
 *
 * Exemplu
 * Intrare:
 * 3 2
 * 10 20 30
 * Ieșire: vid
 */
#include <iostream>
using namespace std;

int nrCifre(int x)
{
    int c = 0;
    do
    {
        c++;
        x /= 10;
    } while (x != 0);
    return c;
}

void elimina(int v[], int &n, int k)
{
    int j = 0;
    for (int i = 0; i < n; i++)
        if (nrCifre(v[i]) != k)
        {
            v[j] = v[i];
            j++;
        }
    n = j;
}

int main()
{
    int n, k, v[1000];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    elimina(v, n, k);
    if (n == 0)
        cout << "vid";
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << '\n';
    return 0;
}
