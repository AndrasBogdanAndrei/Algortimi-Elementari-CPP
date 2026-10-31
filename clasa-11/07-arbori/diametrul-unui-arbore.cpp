/*
 * Titlu: Diametrul unui arbore
 * Clasa: 11
 * Capitol: Arbori
 * Descriere: Diametrul unui arbore este lungimea (numărul de muchii) celui mai lung lanț
 *            dintre două noduri. Metoda celor două parcurgeri: facem un BFS din nodul 1 și
 *            găsim nodul a cel mai depărtat de el; a este sigur un capăt al unui lanț de
 *            lungime maximă. Facem apoi un BFS din a; nodul b cel mai depărtat de a este
 *            celălalt capăt, iar distanța de la a la b este diametrul. Lanțul se reface prin
 *            tații din al doilea BFS. La egalitate de distanță se ia nodul cu numărul mai mic.
 *            Datele: n, apoi cele n - 1 muchii ale arborelui.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 8
 * 1 2
 * 2 3
 * 2 4
 * 4 5
 * 5 6
 * 1 7
 * 7 8
 * Ieșire:
 * 6
 * 8 7 1 2 4 5 6
 */
#include <iostream>
#include <vector>
using namespace std;

int n, dist[100005], tata[100005], coada[100005];
vector<int> vecini[100005];

// face BFS din s și întoarce nodul cel mai depărtat (cel mai mic, la egalitate)
int bfs(int s)
{
    for (int i = 1; i <= n; i++)
    {
        dist[i] = -1;
    }
    int inc = 1, sf = 1;
    coada[1] = s;
    dist[s] = 0;
    tata[s] = 0;
    while (inc <= sf)
    {
        int x = coada[inc++];
        for (int y : vecini[x])
        {
            if (dist[y] == -1)
            {
                dist[y] = dist[x] + 1;
                tata[y] = x;
                coada[++sf] = y;
            }
        }
    }
    int departe = s;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > dist[departe])
        {
            departe = i;
        }
    }
    return departe;
}

int main()
{
    cin >> n;
    for (int k = 1; k < n; k++)
    {
        int x, y;
        cin >> x >> y;
        vecini[x].push_back(y);
        vecini[y].push_back(x);
    }
    int a = bfs(1);
    int b = bfs(a);
    cout << dist[b] << '\n';
    for (int x = b; x != 0; x = tata[x])
    {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}
