/*
 * Titlu: Stiva monotonă — următorul element mai mare
 * Clasa: 12
 * Capitol: Tehnici avansate: doi pointeri, căutare binară pe răspuns, stive monotone
 * Descriere: Pentru fiecare a[i] căutăm prima valoare strict mai mare aflată în
 *            dreapta lui (sau -1). Ținem o stivă cu pozițiile care încă „așteaptă”
 *            un element mai mare; valorile lor sunt descrescătoare de la bază spre
 *            vârf. Când vine a[i], toate pozițiile din vârf cu valoare mai mică
 *            și-au găsit răspunsul: îl notăm și le scoatem. Apoi punem i în stivă.
 *            Pozițiile rămase la final nu au un element mai mare. Fiecare poziție
 *            intră și iese din stivă cel mult o dată.
 * Complexitate: O(n)
 *
 * Exemplu
 * Intrare:
 * 8
 * 4 5 2 25 7 8 1 9
 * Ieșire: 5 25 25 -1 8 9 9 -1
 *
 * Exemplu
 * Intrare:
 * 4
 * 5 5 3 1
 * Ieșire: -1 -1 -1 -1
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n), rasp(n, -1);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    stack<int> st; // poziții, cu valori descrescătoare spre vârf
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            rasp[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << rasp[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
