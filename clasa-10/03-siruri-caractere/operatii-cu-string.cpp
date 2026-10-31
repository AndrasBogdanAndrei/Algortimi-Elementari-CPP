/*
 * Titlu: Operații cu std::string
 * Clasa: 10
 * Capitol: Șiruri de caractere
 * Descriere: Clasa string din <string> își gestionează singură memoria: se atribuie
 *            cu =, se lipește cu +, se compară cu == și <. getline(cin, s) citește
 *            tot rândul. Metode folosite: size() (lungimea), find(t) (poziția primei
 *            apariții a lui t sau string::npos dacă nu apare), substr(poz, lung)
 *            (o bucată), erase(poz, lung) (șterge), insert(poz, t) (inserează) și
 *            replace(poz, lung, t) (înlocuiește). Se citesc o frază și un cuvânt.
 * Complexitate: fiecare operație este O(L)
 *
 * Exemplu
 * Intrare:
 * ana are mere
 * are
 * Ieșire:
 * 12
 * 4
 * are
 * ana  mere
 * ana are mere
 * ana ARE mere
 * ana are mere!
 *
 * Exemplu
 * Intrare:
 * vine vara
 * iarna
 * Ieșire:
 * 9
 * nu apare
 * vine vara!
 */
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string s, cuvant;
    getline(cin, s);
    getline(cin, cuvant);

    cout << s.size() << '\n';
    size_t poz = s.find(cuvant);
    if (poz == string::npos)
    {
        cout << "nu apare\n";
    }
    else
    {
        cout << poz << '\n';
        cout << s.substr(poz, cuvant.size()) << '\n';

        string t = s;
        t.erase(poz, cuvant.size());          // ștergem cuvântul
        cout << t << '\n';
        t.insert(poz, cuvant);                // îl punem la loc
        cout << t << '\n';

        string mare = cuvant;
        for (size_t i = 0; i < mare.size(); i++)
            mare[i] = toupper(mare[i]);
        t.replace(poz, cuvant.size(), mare);  // înlocuim cu varianta cu majuscule
        cout << t << '\n';
    }
    cout << s + "!" << '\n';
    return 0;
}
