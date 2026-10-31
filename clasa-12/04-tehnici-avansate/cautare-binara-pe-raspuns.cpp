/*
 * Titlu: Căutare binară pe răspuns
 * Clasa: 12
 * Capitol: Tehnici avansate: doi pointeri, căutare binară pe răspuns, stive monotone
 * Descriere: Avem n capitole cu a[i] pagini, în ordine, și k corectori. Fiecare
 *            corector primește o secvență de capitole consecutive. Vrem ca cel mai
 *            încărcat corector să aibă cât mai puține pagini. În loc să căutăm
 *            împărțirea, căutăm direct răspunsul L: întrebarea „ajung k corectori
 *            dacă nimeni nu primește mai mult de L pagini?” se rezolvă greedy,
 *            umplând fiecare corector cât se poate. Dacă răspunsul e da pentru L,
 *            e da și pentru orice valoare mai mare (proprietate monotonă), deci
 *            căutăm binar cel mai mic L bun între max(a) și suma tuturor.
 * Complexitate: O(n * log(suma)), cu o verificare O(n) la fiecare pas
 *
 * Exemplu
 * Intrare:
 * 7 3
 * 10 20 30 40 50 60 70
 * Ieșire: 110
 *
 * Exemplu
 * Intrare:
 * 5 2
 * 7 2 5 10 8
 * Ieșire: 18
 *
 * Exemplu
 * Intrare:
 * 3 5
 * 4 9 2
 * Ieșire: 9
 */
#include <iostream>
#include <vector>
using namespace std;

// Întoarce true dacă se pot împărți capitolele la cel mult k corectori,
// fiecare cu cel mult L pagini (presupunem L >= cel mai mare a[i]).
bool ajung(const vector<long long> &a, int k, long long L)
{
    int corectori = 1;
    long long curent = 0;
    for (long long x : a)
    {
        if (curent + x > L)
        {
            corectori++;
            curent = 0;
        }
        curent += x;
    }
    return corectori <= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long st = 0, dr = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        st = max(st, a[i]);
        dr += a[i];
    }
    // Căutăm cea mai mică valoare L din [st, dr] pentru care ajung(L) este adevărat.
    while (st < dr)
    {
        long long mij = st + (dr - st) / 2;
        if (ajung(a, k, mij))
            dr = mij;
        else
            st = mij + 1;
    }
    cout << st << '\n';
    return 0;
}
