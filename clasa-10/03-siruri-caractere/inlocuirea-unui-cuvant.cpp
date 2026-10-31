/*
 * Titlu: Înlocuirea unui cuvânt cu altul
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Se citesc un text și două cuvinte, vechi și nou (fiecare pe câte un
 *            rând). Construim rezultatul într-un șir nou: copiem spațiile așa cum
 *            sunt, iar fiecare cuvânt îl extragem întreg și îl comparăm cu vechi
 *            folosind strcmp (întoarce 0 la egalitate). Dacă se potrivește scriem
 *            nou, altfel cuvântul original. Așa înlocuim doar cuvinte întregi:
 *            „ana” nu se înlocuiește în interiorul cuvântului „banana”.
 * Complexitate: O(L)
 *
 * Exemplu
 * Intrare:
 * ana are mere si banana iar ana are pere
 * ana
 * maria
 * Ieșire: maria are mere si banana iar maria are pere
 */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char text[256], vechi[51], nou[51], rezultat[1024];
    cin.getline(text, 256);
    cin.getline(vechi, 51);
    cin.getline(nou, 51);

    int i = 0, k = 0;
    while (text[i] != '\0')
    {
        if (text[i] == ' ')
        {
            rezultat[k++] = text[i++];
        }
        else
        {
            char cuvant[256];
            int lung = 0;
            while (text[i] != '\0' && text[i] != ' ')
                cuvant[lung++] = text[i++];
            cuvant[lung] = '\0';

            const char *deScris = (strcmp(cuvant, vechi) == 0) ? nou : cuvant;
            for (int j = 0; deScris[j] != '\0'; j++)
                rezultat[k++] = deScris[j];
        }
    }
    rezultat[k] = '\0';
    cout << rezultat << '\n';
    return 0;
}
