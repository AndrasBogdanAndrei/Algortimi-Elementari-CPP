/*
 * Titlu: Variabile globale și variabile locale
 * Clasa: 10
 * Capitol: Subprograme (funcții)
 * Descriere: O variabilă globală (declarată în afara funcțiilor) se vede din tot
 *            programul, pornește automat cu 0 și își păstrează valoarea între apeluri.
 *            O variabilă locală (declarată într-o funcție) se creează la fiecare apel
 *            și dispare la ieșire. Dacă o locală are același nume ca o globală, o
 *            ascunde; globala se poate accesa totuși cu ::nume. Funcția pas() este
 *            apelată de n ori: locala x pornește mereu de la 5, globala apeluri crește.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare: 3
 * Ieșire:
 * 6 100
 * 6 100
 * 6 100
 * 100 3
 */
#include <iostream>
using namespace std;

int x = 100;     // variabilă globală
int apeluri;     // globală, inițializată automat cu 0

void pas()
{
    int x = 5;   // variabilă locală: ascunde globala cu același nume
    x++;
    apeluri++;
    cout << x << ' ' << ::x << '\n';   // ::x este variabila globală
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        pas();
    cout << x << ' ' << apeluri << '\n';
    return 0;
}
