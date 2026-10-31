/*
 * Titlu: Fill — numărul de zone
 * Clasa: 12
 * Capitol: Algoritmi pe grile: Lee și fill
 * Descriere: Matricea are n linii și m coloane, cu 1 pentru teren și 0 pentru apă.
 *            O zonă este un grup maxim de celule 1 legate prin laturi (sus, jos,
 *            stânga, dreapta). Parcurgem matricea; la prima celulă 1 nevizitată
 *            dintr-o zonă numărăm o zonă nouă și pornim „umplerea”: funcția
 *            recursivă fill marchează celula cu 0 și se apelează pentru cei 4
 *            vecini. Bordăm matricea cu 0, ca să nu ieșim din ea. Fiecare celulă
 *            este marcată o singură dată.
 * Complexitate: O(n * m)
 *
 * Exemplu
 * Intrare:
 * 4 5
 * 1 1 0 0 1
 * 1 0 0 1 1
 * 0 0 1 0 0
 * 1 0 1 1 0
 * Ieșire: 4
 *
 * Exemplu
 * Intrare:
 * 2 2
 * 0 0
 * 0 0
 * Ieșire: 0
 */
#include <iostream>
using namespace std;

const int DIM = 102;          // n, m <= 100, plus bordura
int a[DIM][DIM];
int dl[4] = {-1, 0, 1, 0};    // deplasările pe linie: sus, dreapta, jos, stânga
int dc[4] = {0, 1, 0, -1};    // deplasările pe coloană

void fill(int i, int j)
{
    a[i][j] = 0; // marcăm celula ca vizitată
    for (int d = 0; d < 4; d++)
    {
        int iv = i + dl[d], jv = j + dc[d];
        if (a[iv][jv] == 1)
            fill(iv, jv);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    // Liniile 0 și n + 1, coloanele 0 și m + 1 rămân 0 (variabilă globală): bordura.
    int zone = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)
            {
                zone++;
                fill(i, j);
            }
    cout << zone << '\n';
    return 0;
}
