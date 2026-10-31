/*
 * Titlu: Factorial recursiv
 * Clasa: 10
 * Capitol: Recursivitate
 * Descriere: Definiția matematică este deja recursivă: 0! = 1 și n! = n * (n - 1)!.
 *            Funcția are o condiție de oprire (n == 0) și un autoapel pe o problemă
 *            mai mică (n - 1). Apelurile se pun pe stivă: fact(4) așteaptă fact(3),
 *            care așteaptă fact(2) și așa mai departe până la fact(0); la întoarcere
 *            se fac înmulțirile, în ordine inversă.
 * Complexitate: O(n) timp și O(n) memorie pe stivă
 *
 * Exemplu
 * Intrare: 5
 * Ieșire: 120
 *
 * Exemplu
 * Intrare: 0
 * Ieșire: 1
 */
#include <iostream>
using namespace std;

long long fact(int n)
{
    if (n == 0)
        return 1;              // condiția de oprire
    return n * fact(n - 1);    // autoapel pe o problemă mai mică
}

int main()
{
    int n;
    cin >> n;
    cout << fact(n) << '\n';
    return 0;
}
