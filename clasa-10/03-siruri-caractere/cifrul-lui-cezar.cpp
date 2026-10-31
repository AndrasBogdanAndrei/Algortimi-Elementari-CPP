/*
 * Titlu: Cifrul lui Cezar
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Fiecare literă se înlocuiește cu litera aflată la k poziții mai
 *            departe în alfabet, circular (după 'z' urmează 'a'). Transformăm
 *            litera în poziția ei 0..25 (c - 'a'), adunăm k, luăm restul la 26 și
 *            revenim la literă. Literele mari se tratează la fel, cu 'A'; restul
 *            caracterelor rămân neschimbate. Se citesc k, apoi textul pe rândul
 *            următor; cin.get() consumă caracterul '\n' rămas după citirea lui k.
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare:
 * 3
 * Ana are mere, Zoe!
 * Ieșire: Dqd duh phuh, Crh!
 *
 * Exemplu
 * Intrare:
 * 25
 * abc XYZ
 * Ieșire: zab WXY
 */
#include <iostream>
using namespace std;

int main()
{
    int k;
    char s[256];
    cin >> k;
    cin.get();              // sărim peste '\n' de după numărul k
    cin.getline(s, 256);
    k = k % 26;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = 'a' + (s[i] - 'a' + k) % 26;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'A' + (s[i] - 'A' + k) % 26;
    }
    cout << s << '\n';
    return 0;
}
