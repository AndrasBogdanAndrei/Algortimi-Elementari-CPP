/*
 * Titlu: Fereastra glisantă — cea mai lungă secvență cu suma ≤ S
 * Clasa: 12
 * Capitol: Tehnici avansate: doi pointeri, căutare binară pe răspuns, stive monotone
 * Descriere: Toate numerele sunt strict pozitive. Ținem o fereastră [st, dr] și
 *            suma ei. Extindem mereu capătul drept cu un element; cât timp suma
 *            depășește S, scoatem elemente din stânga (st++). Pentru că valorile
 *            sunt pozitive, scoaterea din stânga doar scade suma, deci fereastra
 *            rămasă este cea mai lungă bună care se termină în dr. Fiecare element
 *            intră o dată și iese cel mult o dată. Afișăm lungimea maximă și
 *            poziția de început (prima, dacă sunt mai multe), numerotând de la 1;
 *            dacă nicio valoare nu este ≤ S, afișăm 0 0.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 10 15
 * 2 7 3 1 5 4 8 1 1 3
 * Ieșire: 4 1
 *
 * Exemplu
 * Intrare:
 * 6 6
 * 9 1 2 3 10 4
 * Ieșire: 3 2
 *
 * Exemplu
 * Intrare:
 * 2 1
 * 5 7
 * Ieșire: 0 0
 */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    long long S;
    cin >> n >> S;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    long long suma = 0;
    int st = 1, lungMax = 0, inceput = 0;
    for (int dr = 1; dr <= n; dr++)
    {
        suma += a[dr];
        while (suma > S)
        {
            suma -= a[st];
            st++;
        }
        // Fereastra [st, dr] poate fi și vidă (st = dr + 1).
        if (dr - st + 1 > lungMax)
        {
            lungMax = dr - st + 1;
            inceput = st;
        }
    }
    cout << lungMax << ' ' << inceput << '\n';
    return 0;
}
