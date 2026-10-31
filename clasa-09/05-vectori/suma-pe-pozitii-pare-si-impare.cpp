/*
 * Titlu: Suma elementelor de pe pozițiile pare și impare
 * Clasa: 9
 * Capitol: Tablouri unidimensionale (vectori)
 * Descriere: Atenție la diferența dintre poziție (indicele i) și valoare (v[i]).
 *            Paritatea se verifică aici pentru indice: v[2], v[4], ... sunt pe
 *            poziții pare. Se afișează suma pe poziții pare, apoi pe impare.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 6
 * 5 1 8 2 7 3
 * Ieșire: 6 20
 */
#include <iostream>
using namespace std;

int v[1001];

int main()
{
    int n;
    long long sumaPare = 0, sumaImpare = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sumaPare = sumaPare + v[i];
        }
        else
        {
            sumaImpare = sumaImpare + v[i];
        }
    }
    cout << sumaPare << ' ' << sumaImpare << '\n';
    return 0;
}
