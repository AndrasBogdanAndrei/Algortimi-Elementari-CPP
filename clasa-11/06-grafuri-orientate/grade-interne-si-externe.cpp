/*
 * Titlu: Gradele interne și externe
 * Clasa: 11
 * Capitol: Grafuri orientate și drumuri minime
 * Descriere: Într-un graf orientat muchiile au sens și se numesc arce: arcul (x, y) pleacă
 *            din x și intră în y. Gradul extern d+(x) este numărul de arce care pleacă din x,
 *            iar gradul intern d-(x) numărul de arce care intră în x. Fiecare arc adaugă 1
 *            la un grad extern și 1 la un grad intern, deci suma gradelor externe = suma
 *            gradelor interne = m. Se afișează cele două șiruri de grade și nodurile
 *            „sursă” (grad intern 0) și „destinație” (grad extern 0).
 * Complexitate: O(n + m)
 *
 * Exemplu
 * Intrare:
 * 5 6
 * 1 2
 * 1 3
 * 2 3
 * 3 1
 * 4 3
 * 2 5
 * Ieșire:
 * Grade externe: 2 2 1 1 0
 * Grade interne: 1 1 3 0 1
 * Surse: 4
 * Destinatii: 5
 */
#include <iostream>
using namespace std;

int dplus[100005], dminus[100005];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int k = 1; k <= m; k++)
    {
        int x, y;
        cin >> x >> y;
        dplus[x]++;
        dminus[y]++;
    }

    cout << "Grade externe:";
    for (int i = 1; i <= n; i++)
    {
        cout << ' ' << dplus[i];
    }
    cout << "\nGrade interne:";
    for (int i = 1; i <= n; i++)
    {
        cout << ' ' << dminus[i];
    }
    cout << "\nSurse:";
    for (int i = 1; i <= n; i++)
    {
        if (dminus[i] == 0)
        {
            cout << ' ' << i;
        }
    }
    cout << "\nDestinatii:";
    for (int i = 1; i <= n; i++)
    {
        if (dplus[i] == 0)
        {
            cout << ' ' << i;
        }
    }
    cout << '\n';
    return 0;
}
