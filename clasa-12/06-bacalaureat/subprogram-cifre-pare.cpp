/*
 * Titlu: Subprogram — numărul format din cifrele pare
 * Clasa: 12
 * Capitol: Recapitulare pentru bacalaureat
 * Descriere: Cerința (tip subiectul III.1): subprogramul pare are un parametru n
 *            (0 ≤ n ≤ 10^9) și întoarce numărul format din cifrele pare ale lui n,
 *            în ordinea în care apar în n, sau -1 dacă n nu are cifre pare.
 *            Extragem cifrele de la unități; o cifră pară trebuie pusă în fața
 *            celor găsite deja, deci o înmulțim cu p (1, 10, 100, ...) și o
 *            adunăm. Folosim do-while ca n = 0 să aibă o cifră (0, care e pară).
 *            Eficiență: un singur pas pe cifră, fără tablouri și fără șiruri de
 *            caractere. main citește k numere și afișează rezultatul pentru
 *            fiecare, ca test.
 * Complexitate: O(numărul de cifre ale lui n)
 *
 * Exemplu
 * Intrare:
 * 4
 * 2753846 1357 2008 0
 * Ieșire:
 * 2846
 * -1
 * 2008
 * 0
 */
#include <iostream>
using namespace std;

int pare(int n)
{
    int rez = 0, p = 1;
    bool gasit = false;
    do
    {
        int c = n % 10;
        if (c % 2 == 0)
        {
            rez = rez + c * p;
            p = p * 10;
            gasit = true;
        }
        n = n / 10;
    } while (n != 0);
    if (!gasit)
        return -1;
    return rez;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        cout << pare(n) << '\n';
    }
    return 0;
}
