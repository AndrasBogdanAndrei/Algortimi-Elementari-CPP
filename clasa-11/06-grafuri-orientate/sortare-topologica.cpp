/*
 * Titlu: Sortarea topologică
 * Clasa: 11
 * Capitol: Grafuri orientate și drumuri minime
 * Descriere: Arcul (x, y) înseamnă „x trebuie făcut înaintea lui y”. O sortare topologică
 *            este o ordine a tuturor nodurilor în care fiecare arc merge de la stânga la
 *            dreapta; ea există doar dacă graful nu are circuite. Calculăm gradele interne.
 *            La fiecare pas alegem un nod nefolosit cu grad intern 0 (aici pe cel cu numărul
 *            cel mai mic, ca ordinea să fie unică), îl scriem și „ștergem” arcele care pleacă
 *            din el, scăzând gradele interne ale vecinilor. Dacă la un moment dat nu mai
 *            există niciun nod cu grad intern 0, graful are un circuit.
 * Complexitate: O(n² + m) în această variantă
 *
 * Exemplu
 * Intrare:
 * 6 6
 * 6 3
 * 6 1
 * 5 1
 * 5 2
 * 3 4
 * 4 2
 * Ieșire: 5 6 1 3 4 2
 *
 * Exemplu
 * Intrare:
 * 3 3
 * 1 2
 * 2 3
 * 3 1
 * Ieșire: Graful are circuit
 */
#include <iostream>
using namespace std;

int a[105][105], gradIntern[105], ordine[105];
bool folosit[105];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        if (a[x][y] == 0)
        {
            a[x][y] = 1;
            gradIntern[y]++;
        }
    }

    for (int pas = 1; pas <= n; pas++)
    {
        int x = 0;
        for (int i = 1; i <= n && x == 0; i++)
        {
            if (!folosit[i] && gradIntern[i] == 0)
            {
                x = i;
            }
        }
        if (x == 0)
        {
            cout << "Graful are circuit\n";
            return 0;
        }
        folosit[x] = true;
        ordine[pas] = x;
        for (int y = 1; y <= n; y++)
        {
            if (a[x][y] == 1)
            {
                gradIntern[y]--;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ordine[i] << ' ';
    }
    cout << '\n';
    return 0;
}
