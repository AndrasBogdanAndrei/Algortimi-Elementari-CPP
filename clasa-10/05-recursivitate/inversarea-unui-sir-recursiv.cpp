/*
 * Titlu: Inversarea unui șir de caractere, recursiv
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Funcția inverseaza(s, i) se ocupă de caracterele de la poziția i până la
 *            final. Dacă s[i] nu este '\0', întâi se autoapelează pentru restul
 *            șirului (i + 1) și abia la întoarcere afișează s[i]. Așa ultimul
 *            caracter este afișat primul. Condiția de oprire este s[i] == '\0'.
 * Complexitate: O(L) timp și O(L) memorie pe stivă
 *
 * Exemplu
 * Intrare: recursiv
 * Ieșire: visrucer
 *
 * Exemplu
 * Intrare: a
 * Ieșire: a
 */
#include <iostream>
using namespace std;

void inverseaza(char s[], int i)
{
    if (s[i] != '\0')
    {
        inverseaza(s, i + 1);
        cout << s[i];
    }
}

int main()
{
    char s[256];
    cin >> s;
    inverseaza(s, 0);
    cout << '\n';
    return 0;
}
