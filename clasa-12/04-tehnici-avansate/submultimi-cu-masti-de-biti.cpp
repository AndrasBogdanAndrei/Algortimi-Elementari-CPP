/*
 * Titlu: Generarea submulțimilor cu măști de biți
 * Clasa: 12
 * Capitol: Tehnici avansate: doi pointeri, căutare binară pe răspuns, stive monotone
 * Descriere: O submulțime a lui {a[0], ..., a[n-1]} se poate codifica printr-un
 *            număr masca între 0 și 2^n - 1: bitul i al măștii este 1 dacă a[i]
 *            face parte din submulțime. Bitul i se testează cu (masca >> i) & 1,
 *            iar 2^n se scrie 1 << n. Parcurgând toate măștile obținem toate cele
 *            2^n submulțimi, fără recursivitate. Programul afișează fiecare
 *            submulțime între acolade, apoi numărul submulțimilor cu suma s.
 *            Este potrivit pentru n mic (cel mult 20).
 * Complexitate: O(2^n * n)
 *
 * Exemplu
 * Intrare:
 * 3 12
 * 1 5 7
 * Ieșire:
 * {}
 * {1}
 * {5}
 * {1 5}
 * {7}
 * {1 7}
 * {5 7}
 * {1 5 7}
 * 1
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long s;
    cin >> n >> s;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cuSumaS = 0;
    for (int masca = 0; masca < (1 << n); masca++)
    {
        long long suma = 0;
        bool primul = true;
        cout << '{';
        for (int i = 0; i < n; i++)
            if ((masca >> i) & 1)
            {
                if (!primul)
                    cout << ' ';
                cout << a[i];
                primul = false;
                suma += a[i];
            }
        cout << "}\n";
        if (suma == s)
            cuSumaS++;
    }
    cout << cuSumaS << '\n';
    return 0;
}
