# Cum poți contribui

Mulțumesc că vrei să ajuți la colecția **Algoritmi elementari în C++**! Cel mai util lucru pe care îl poți face este
să semnalezi greșelile: un rezultat greșit, o explicație neclară, o complexitate scrisă greșit sau un program care nu
se compilează pe calculatorul tău.

## Raportează o greșeală

1. Verifică în [lista de issues](https://github.com/AndrasBogdanAndrei/Algoritmi-Elementari-CodePrepper/issues) că
   problema nu a fost deja semnalată.
2. Deschide un [issue nou](https://github.com/AndrasBogdanAndrei/Algoritmi-Elementari-CodePrepper/issues/new/choose)
   cu șablonul **„Greșeală într-un algoritm”**.
3. Scrie fișierul (de exemplu `clasa-09/01-cifre/suma-cifrelor.cpp`), datele de intrare, ce a afișat programul și ce
   te așteptai să afișeze. Dacă e o eroare de compilare, copiază mesajul compilatorului și scrie ce compilator
   folosești (`g++ --version`).

## Propune un algoritm nou

Deschide un issue cu șablonul **„Propune un algoritm”**. Spune la ce clasă și la ce capitol s-ar potrivi și de ce
lipsește din colecție. Nu lipi enunțuri copiate de pe alte site-uri sau din culegeri: descrie problema cu cuvintele tale.

## Pull request-uri

Pull request-urile pentru corecturi mici (o greșeală de calcul, o explicație, diacritice) sunt binevenite. Pentru
algoritmi noi sau schimbări mai mari, deschide întâi un issue, ca să stabilim împreună dacă și unde se potrivesc.

Colecția nu este sub o licență open source: toate drepturile sunt rezervate autorului (vezi [LICENSE](LICENSE)).
Trimițând un pull request, ești de acord ca modificarea ta să fie inclusă în colecție și distribuită în aceleași
condiții, și ca autorul să o poată adapta. Trimite doar cod și text scrise de tine.

### Regulile unui fișier `.cpp`

- Fișierul stă în folderul clasei și al capitolului (`clasa-10/05-recursivitate/...`) și are un nume scurt, cu
  litere mici, fără diacritice, cu cratime: `sortare-prin-insertie.cpp`.
- Începe cu un comentariu de antet cu câmpurile `Titlu:`, `Clasa:`, `Capitol:`, `Descriere:`, `Complexitate:` și
  cel puțin un exemplu:

  ```cpp
  /*
   * Titlu: Suma cifrelor unui număr
   * Clasa: 9
   * Capitol: Cifrele unui număr
   * Descriere: Adună cifrele lui n, tăind la fiecare pas ultima cifră.
   * Complexitate: O(k), unde k este numărul de cifre
   *
   * Exemplu
   * Intrare: 1234
   * Ieșire: 10
   */
  ```

- C++17 standard, fără `<bits/stdc++.h>` (nu există pe macOS). Programul trebuie să se compileze fără avertismente
  cu `-Wall -Wextra`.
- Programele care lucrează cu fișiere citesc din `date.in` și scriu în `date.out`.
- Explicațiile sunt în limba română, cu diacritice, pe înțelesul unui elev de liceu.

### Înainte să trimiți

```sh
python scripts/verifica.py clasa-09          # compilează și rulează exemplele (are nevoie de g++ sau clang++)
python scripts/genereaza_readme.py           # regenerează README.md din antetele fișierelor
```

`README.md` se generează automat: nu-l modifica de mână, modifică antetul fișierului sau scriptul
`scripts/genereaza_readme.py`. Verificarea automată de pe GitHub rulează aceleași teste pe Windows, Linux și macOS.

## Comportament

Participarea la proiect respectă [Codul de conduită](CODE_OF_CONDUCT.md).
