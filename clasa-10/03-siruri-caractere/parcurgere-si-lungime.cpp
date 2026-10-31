/*
 * Titlu: Parcurgerea unui șir și lungimea lui
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Un șir de caractere în stil C este un vector de char terminat cu
 *            caracterul nul '\0'. cin.getline(s, 256) citește tot rândul, cu tot
 *            cu spații (cin >> s s-ar opri la primul spațiu). Lungimea se poate
 *            număra de mână, mergând până la '\0', sau cu funcția strlen din
 *            <cstring>; cele două valori afișate trebuie să coincidă. Pe al doilea
 *            rând afișăm caracterele separate prin cratimă, ca să se vadă și spațiile.
 * Complexitate: O(L), unde L este lungimea șirului
 *
 * Exemplu
 * Intrare: Ana are mere
 * Ieșire:
 * 12 12
 * A-n-a- -a-r-e- -m-e-r-e
 */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[256];
    cin.getline(s, 256);

    int lungime = 0;
    while (s[lungime] != '\0')
        lungime++;
    cout << lungime << ' ' << strlen(s) << '\n';

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (i > 0)
            cout << '-';
        cout << s[i];
    }
    cout << '\n';
    return 0;
}
