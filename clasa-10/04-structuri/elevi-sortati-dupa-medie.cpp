/*
 * Titlu: Elevi sortați după medie și nume
 * Clasa: 10
 * Capitol: Tipul struct
 * Descriere: Tipul struct grupează sub un singur nume date de tipuri diferite:
 *            struct Elev { char nume[31]; double medie; }. Un câmp se accesează cu
 *            punct (e.medie), iar două variabile struct se pot atribui direct cu =
 *            (se copiază toate câmpurile, inclusiv vectorul nume). Sortăm elevii
 *            descrescător după medie, iar la medii egale alfabetic după nume
 *            (strcmp). Regula de ordine stă într-o funcție separată, inainte(x, y).
 * Complexitate: O(n * n * L) cu sortarea prin selecție
 *
 * Exemplu
 * Intrare:
 * 5
 * Popescu 9.50
 * Ionescu 8.75
 * Albu 9.50
 * Marin 10
 * Dobre 8.75
 * Ieșire:
 * Marin 10.00
 * Albu 9.50
 * Popescu 9.50
 * Dobre 8.75
 * Ionescu 8.75
 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Elev
{
    char nume[31];
    double medie;
};

Elev e[100];

// true dacă elevul x trebuie să apară înaintea lui y
bool inainte(Elev x, Elev y)
{
    if (x.medie != y.medie)
        return x.medie > y.medie;
    return strcmp(x.nume, y.nume) < 0;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> e[i].nume >> e[i].medie;

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (inainte(e[j], e[i]))
            {
                Elev aux = e[i];
                e[i] = e[j];
                e[j] = aux;
            }

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++)
        cout << e[i].nume << ' ' << e[i].medie << '\n';
    return 0;
}
