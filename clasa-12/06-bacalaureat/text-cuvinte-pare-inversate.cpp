/*
 * Titlu: Text — inversarea cuvintelor de lungime pară
 * Clasa: 12
 * Capitol: Recapitulare pentru bacalaureat
 * Descriere: Cerința (tip subiectul III.2): se citește un text de cel mult 100 de
 *            caractere, format din cuvinte de litere mici separate prin câte un
 *            spațiu. Afișați textul în care fiecare cuvânt cu număr par de litere
 *            este scris invers; dacă niciun cuvânt nu are lungime pară, afișați
 *            „nu exista”. Lucrăm direct în tabloul de caractere: găsim capetele
 *            fiecărui cuvânt (st, dr) și, dacă lungimea dr - st + 1 este pară,
 *            interschimbăm literele de la capete spre mijloc. Textul se modifică
 *            pe loc, fără un al doilea tablou, iar fiecare caracter este vizitat
 *            de cel mult două ori.
 * Complexitate: O(L), unde L este lungimea textului
 *
 * Exemplu
 * Intrare: ana are doua mere si un pix
 * Ieșire: ana are auod erem is nu pix
 *
 * Exemplu
 * Intrare: x yyy
 * Ieșire: nu exista
 */
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char s[105];
    cin.getline(s, 105);
    int L = strlen(s);
    bool modificat = false;
    int i = 0;
    while (i < L)
    {
        if (s[i] == ' ')
        {
            i++;
            continue;
        }
        int st = i;
        while (i < L && s[i] != ' ')
            i++;
        int dr = i - 1; // ultimul caracter al cuvântului
        if ((dr - st + 1) % 2 == 0)
        {
            modificat = true;
            while (st < dr)
            {
                char aux = s[st];
                s[st] = s[dr];
                s[dr] = aux;
                st++;
                dr--;
            }
        }
    }
    if (modificat)
        cout << s << '\n';
    else
        cout << "nu exista\n";
    return 0;
}
