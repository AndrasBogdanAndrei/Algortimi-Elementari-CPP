/*
 * Titlu: pair — reuniunea intervalelor
 * Clasa: 12
 * Capitol: Structuri de date și STL
 * Descriere: pair<int, int> grupează două valori (first, second) și se compară
 *            lexicografic: întâi după first, apoi după second. Așadar sort pe un
 *            vector de perechi ordonează intervalele după capătul stâng. Apoi le
 *            parcurgem o dată: dacă intervalul curent începe înainte de sfârșitul
 *            celui în construcție (sau chiar acolo), îl lipim, prelungind
 *            sfârșitul; altfel închidem intervalul construit și începem altul.
 *            Programul afișează intervalele reuniunii, de la stânga la dreapta.
 * Complexitate: O(n log n)
 *
 * Exemplu
 * Intrare:
 * 5
 * 1 3
 * 8 10
 * 2 6
 * 15 18
 * 10 12
 * Ieșire:
 * 1 6
 * 8 12
 * 15 18
 */
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    vector<pair<int, int>> reuniune;
    pair<int, int> curent = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i].first <= curent.second)
            curent.second = max(curent.second, v[i].second);
        else
        {
            reuniune.push_back(curent);
            curent = v[i];
        }
    }
    reuniune.push_back(curent);
    for (auto &p : reuniune)
        cout << p.first << ' ' << p.second << '\n';
    return 0;
}
