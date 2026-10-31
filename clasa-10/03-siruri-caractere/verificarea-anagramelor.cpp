/*
 * Titlu: Verificarea anagramelor
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Două cuvinte sunt anagrame dacă au aceleași litere, de același număr
 *            de ori, în altă ordine (de exemplu „roma” și „amor”). Folosim un
 *            vector de frecvență cu 26 de poziții: pentru fiecare literă din primul
 *            cuvânt creștem fr[c - 'a'], pentru fiecare literă din al doilea o
 *            scădem. Cuvintele sunt anagrame dacă la final toate valorile sunt 0.
 *            Cuvintele sunt formate din litere mici.
 * Complexitate: O(L1 + L2)
 *
 * Exemplu
 * Intrare: roma amor
 * Ieșire: DA
 *
 * Exemplu
 * Intrare: carte traca
 * Ieșire: NU
 */
#include <iostream>
using namespace std;

int main()
{
    char a[101], b[101];
    cin >> a >> b;
    int fr[26] = {0};
    for (int i = 0; a[i] != '\0'; i++)
        fr[a[i] - 'a']++;
    for (int i = 0; b[i] != '\0'; i++)
        fr[b[i] - 'a']--;

    bool anagrame = true;
    for (int c = 0; c < 26; c++)
        if (fr[c] != 0)
            anagrame = false;
    cout << (anagrame ? "DA" : "NU") << '\n';
    return 0;
}
