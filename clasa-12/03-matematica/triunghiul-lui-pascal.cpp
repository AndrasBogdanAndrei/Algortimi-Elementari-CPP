/*
 * Titlu: Triunghiul lui Pascal (combinări)
 * Clasa: 12
 * Capitol: Matematică pentru programare
 * Descriere: Combinările C(i, j) — numărul de submulțimi cu j elemente ale unei
 *            mulțimi cu i elemente — respectă relația C(i, j) = C(i-1, j-1) +
 *            C(i-1, j): fie alegem elementul i, fie nu. Cu C(i, 0) = C(i, i) = 1
 *            construim tabelul linie cu linie, folosind doar adunări (fără
 *            factoriale care ar depăși). Programul afișează liniile 0, 1, ..., n
 *            ale triunghiului, apoi valoarea C(n, k). Pentru n ≤ 66 toate valorile
 *            încap în long long.
 * Complexitate: O(n^2)
 *
 * Exemplu
 * Intrare: 5 2
 * Ieșire:
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
 * 1 5 10 10 5 1
 * 10
 *
 * Exemplu
 * Intrare: 2 3
 * Ieșire:
 * 1
 * 1 1
 * 1 2 1
 * 0
 */
#include <iostream>
using namespace std;

long long c[67][67];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << c[i][j] << (j < i ? ' ' : '\n');
    }
    // Dacă k > n nu există submulțimi cu k elemente.
    cout << (k <= n ? c[n][k] : 0) << '\n';
    return 0;
}
