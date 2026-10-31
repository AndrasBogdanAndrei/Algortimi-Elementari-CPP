/*
 * Titlu: Turnurile din Hanoi
 * Clasa: 10
 * Capitol: Divide et impera
 * Descriere: Avem n discuri pe tija A, în ordine descrescătoare a mărimii, și vrem
 *            să le mutăm pe tija C, folosind tija B, fără să punem vreodată un disc
 *            mare peste unul mic. Ca să mutăm n discuri de pe A pe C: mutăm întâi
 *            n - 1 discuri de pe A pe B (folosind C), apoi discul cel mare de pe A pe
 *            C, apoi cele n - 1 discuri de pe B pe C (folosind A). Numărul de mutări
 *            este 2^n - 1. Se afișează numărul de mutări, apoi mutările.
 * Complexitate: O(2^n)
 *
 * Exemplu
 * Intrare: 2
 * Ieșire:
 * 3
 * A -> B
 * A -> C
 * B -> C
 *
 * Exemplu
 * Intrare: 3
 * Ieșire:
 * 7
 * A -> C
 * A -> B
 * C -> B
 * A -> C
 * B -> A
 * B -> C
 * A -> C
 */
#include <iostream>
using namespace std;

void hanoi(int n, char sursa, char destinatie, char auxiliar)
{
    if (n == 0)
        return;
    hanoi(n - 1, sursa, auxiliar, destinatie);
    cout << sursa << " -> " << destinatie << '\n';
    hanoi(n - 1, auxiliar, destinatie, sursa);
}

int main()
{
    int n;
    cin >> n;
    cout << (1LL << n) - 1 << '\n';
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
