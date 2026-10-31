/*
 * Titlu: Citirea unui șir terminat cu 0
 * Clasa: 9
 * Capitol: Șiruri de numere citite pe rând
 * Descriere: Nu știm dinainte câte numere urmează: citim până la primul 0,
 *            care doar marchează sfârșitul și nu face parte din șir. Se afișează
 *            câte numere s-au citit și suma lor. Citirea se face o dată înainte
 *            de buclă și apoi la finalul fiecărui pas.
 * Complexitate: O(n), unde n este numărul de valori de dinainte de 0
 *
 * Exemplu
 * Intrare: 4 7 -2 5 0
 * Ieșire: 4 14
 *
 * Exemplu
 * Intrare: 0
 * Ieșire: 0 0
 */
#include <iostream>
using namespace std;

int main()
{
    long long x, suma = 0;
    int numar = 0;
    cin >> x;
    while (x != 0)
    {
        numar++;
        suma = suma + x;
        cin >> x;
    }
    cout << numar << ' ' << suma << '\n';
    return 0;
}
