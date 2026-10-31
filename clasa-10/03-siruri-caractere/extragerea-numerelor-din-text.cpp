/*
 * Titlu: Extragerea numerelor dintr-un text
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Parcurgem textul; când întâlnim o cifră, construim numărul ca la
 *            clasa a IX-a (nr = nr * 10 + (s[i] - '0')) cât timp urmează cifre.
 *            Expresia s[i] - '0' transformă caracterul cifră în valoarea lui
 *            ('7' - '0' = 7). Afișăm numerele găsite pe primul rând și suma lor pe
 *            al doilea.
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare: Am 3 mere, 12 pere si 105 prune.
 * Ieșire:
 * 3 12 105
 * 120
 *
 * Exemplu
 * Intrare: cod2026abc7
 * Ieșire:
 * 2026 7
 * 2033
 */
#include <iostream>
using namespace std;

int main()
{
    char s[256];
    cin.getline(s, 256);
    long long suma = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            long long nr = 0;
            while (s[i] >= '0' && s[i] <= '9')
            {
                nr = nr * 10 + (s[i] - '0');
                i++;
            }
            cout << nr << ' ';
            suma += nr;
        }
        else
            i++;
    }
    cout << '\n' << suma << '\n';
    return 0;
}
