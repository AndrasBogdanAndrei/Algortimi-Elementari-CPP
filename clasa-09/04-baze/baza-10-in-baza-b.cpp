/*
 * Titlu: Conversia din baza 10 în baza b
 * Clasa: 9
 * Capitol: Baze de numerație
 * Descriere: Împărțim repetat n la b; resturile sunt cifrele în baza b, dar
 *            obținute de la ultima spre prima. De aceea fiecare cifră nouă se
 *            lipește în fața rezultatului. Pentru b > 10 cifrele 10..15 se scriu
 *            A..F, așa că rezultatul se păstrează ca text (string).
 *            Se citesc n și b (2 <= b <= 16).
 * Complexitate: O(log_b n), adică numărul de cifre în baza b
 *
 * Exemplu
 * Intrare: 13 2
 * Ieșire: 1101
 *
 * Exemplu
 * Intrare: 255 16
 * Ieșire: FF
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    long long n;
    int b;
    const string CIFRE = "0123456789ABCDEF";
    string rez = "";
    cin >> n >> b;
    do
    {
        rez = CIFRE[n % b] + rez;
        n = n / b;
    }
    while (n > 0);
    cout << rez << '\n';
    return 0;
}
