/*
 * Titlu: Sortarea alfabetică a cuvintelor
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Separăm fraza în cuvinte cu strtok și le copiem într-o matrice de
 *            caractere cuv[100][31] (fiecare linie este un șir). Sortăm cu metoda
 *            bulelor; două cuvinte se compară cu strcmp(x, y), care întoarce o valoare
 *            pozitivă dacă x este după y în ordinea din tabelul ASCII. Interschimbarea
 *            se face prin trei apeluri strcpy, cu un șir auxiliar. Cuvintele sunt
 *            scrise cu litere mici (literele mari ar fi puse înaintea tuturor celor mici).
 * Complexitate: O(k * k * L), k cuvinte de lungime cel mult L
 *
 * Exemplu
 * Intrare: pere mere ana banane caise
 * Ieșire: ana banane caise mere pere
 *
 * Exemplu
 * Intrare: mare mar marar ma
 * Ieșire: ma mar marar mare
 */
#include <iostream>
#include <cstring>
using namespace std;

char cuv[100][31];

int main()
{
    char s[256];
    cin.getline(s, 256);
    int k = 0;
    char *p = strtok(s, " ");
    while (p != NULL)
    {
        strcpy(cuv[k++], p);
        p = strtok(NULL, " ");
    }

    bool schimbat = true;
    while (schimbat)
    {
        schimbat = false;
        for (int i = 0; i + 1 < k; i++)
        {
            if (strcmp(cuv[i], cuv[i + 1]) > 0)
            {
                char aux[31];
                strcpy(aux, cuv[i]);
                strcpy(cuv[i], cuv[i + 1]);
                strcpy(cuv[i + 1], aux);
                schimbat = true;
            }
        }
    }

    for (int i = 0; i < k; i++)
        cout << cuv[i] << ' ';
    cout << '\n';
    return 0;
}
