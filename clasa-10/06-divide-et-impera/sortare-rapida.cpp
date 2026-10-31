/*
 * Titlu: Sortarea rapidă (Quick Sort)
 * Clasa: 10
 * Capitol: Divide et impera
 * Descriere: Alegem un pivot (aici elementul din mijloc) și rearanjăm porțiunea
 *            astfel încât în stânga să ajungă valori <= pivot, iar în dreapta valori
 *            >= pivot: indicele i înaintează cât timp v[i] < pivot, j coboară cât
 *            timp v[j] > pivot, apoi v[i] și v[j] se interschimbă. Când i și j se
 *            încrucișează, sortăm recursiv cele două bucăți. Spre deosebire de
 *            interclasare, munca se face ÎNAINTE de autoapeluri și nu e nevoie de
 *            vector auxiliar.
 * Complexitate: O(n log n) în medie, O(n * n) în cazul cel mai nefavorabil
 *
 * Exemplu
 * Intrare:
 * 8
 * 5 2 9 1 5 6 3 8
 * Ieșire: 1 2 3 5 5 6 8 9
 *
 * Exemplu
 * Intrare:
 * 5
 * 7 7 7 1 7
 * Ieșire: 1 7 7 7 7
 */
#include <iostream>
using namespace std;

int v[100000];

void sortareRapida(int st, int dr)
{
    if (st >= dr)
        return;
    int pivot = v[(st + dr) / 2];
    int i = st, j = dr;
    while (i <= j)
    {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i <= j)
        {
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
            i++;
            j--;
        }
    }
    sortareRapida(st, j);
    sortareRapida(i, dr);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sortareRapida(0, n - 1);
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
    cout << '\n';
    return 0;
}
