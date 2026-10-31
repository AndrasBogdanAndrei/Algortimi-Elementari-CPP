/*
 * Titlu: Conversia din baza b în baza 10
 * Clasa: 9
 * Capitol: Baze de numerație
 * Descriere: Numărul în baza b se citește ca text (poate conține A..F), apoi
 *            se aplică schema lui Horner: parcurgem cifrele de la stânga la
 *            dreapta și facem rez = rez * b + cifra. Astfel, pentru 1101 în baza 2:
 *            1, 1·2+1 = 3, 3·2+0 = 6, 6·2+1 = 13.
 * Complexitate: O(k), unde k este numărul de cifre
 *
 * Exemplu
 * Intrare: 1101 2
 * Ieșire: 13
 *
 * Exemplu
 * Intrare: FF 16
 * Ieșire: 255
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int b;
    long long rez = 0;
    cin >> s >> b;
    for (int i = 0; i < (int)s.size(); i++)
    {
        int cifra;
        if (s[i] >= '0' && s[i] <= '9')
        {
            cifra = s[i] - '0';
        }
        else
        {
            cifra = s[i] - 'A' + 10;
        }
        rez = rez * b + cifra;
    }
    cout << rez << '\n';
    return 0;
}
