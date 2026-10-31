/*
 * Titlu: Sortarea prin interclasare (Merge Sort)
 * Clasa: 10
 * Capitol: Divide et impera
 * Descriere: Împărțim vectorul în două jumătăți, sortăm recursiv fiecare jumătate,
 *            apoi le interclasăm: comparăm mereu primele elemente rămase din cele
 *            două jumătăți și îl mutăm pe cel mai mic într-un vector auxiliar.
 *            La final copiem rezultatul înapoi. O porțiune cu un element este deja
 *            sortată. Folosim <= la comparare, deci sortarea este stabilă
 *            (elementele egale își păstrează ordinea).
 * Complexitate: O(n log n) în orice caz, cu memorie suplimentară O(n)
 *
 * Exemplu
 * Intrare:
 * 8
 * 5 2 9 1 5 6 3 8
 * Ieșire: 1 2 3 5 5 6 8 9
 *
 * Exemplu
 * Intrare:
 * 3
 * 3 2 1
 * Ieșire: 1 2 3
 */
#include <iostream>
using namespace std;

int v[100000], aux[100000];

void interclaseaza(int st, int m, int dr)
{
    int i = st, j = m + 1, k = 0;
    while (i <= m && j <= dr)
    {
        if (v[i] <= v[j])
            aux[k++] = v[i++];
        else
            aux[k++] = v[j++];
    }
    while (i <= m)
        aux[k++] = v[i++];
    while (j <= dr)
        aux[k++] = v[j++];
    for (int t = 0; t < k; t++)
        v[st + t] = aux[t];
}

void sorteaza(int st, int dr)
{
    if (st >= dr)
        return;
    int m = (st + dr) / 2;
    sorteaza(st, m);
    sorteaza(m + 1, dr);
    interclaseaza(st, m, dr);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sorteaza(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << '\n';
    return 0;
}
