# Algoritmi elementari în C++

Colecție completă de algoritmi pentru informatica de liceu (clasele IX–XII, profil matematică-informatică),
scrisă în C++ și organizată după programa școlară. Fiecare program are la început o explicație a ideii,
complexitatea și un exemplu de intrare și ieșire, și este verificat automat: se compilează și dă rezultatul
din exemplu.

**266 algoritmi** în 27 capitole.

> Vrei să-i vezi animați pas cu pas, să rezolvi probleme cu evaluare automată și să dai teste grilă?
> Încearcă aplicația [CodePrepper](https://github.com/AndrasBogdanAndrei/CodePrepper).

## Cum folosești algoritmii

1. Deschide fișierul `.cpp` care te interesează și citește explicația din antet.
2. Compilează-l (Code::Blocks, sau din terminal: `g++ -std=c++17 -O2 fisier.cpp -o program`).
3. Rulează-l și introdu datele din exemplul din antet.

Verificarea automată a întregii colecții: `python scripts/verifica.py` (are nevoie de g++ sau clang++).

## Cuprins

- [Clasa a IX-a](#clasa-a-ix-a)
- [Clasa a X-a](#clasa-a-x-a)
- [Clasa a XI-a](#clasa-a-xi-a)
- [Clasa a XII-a](#clasa-a-xii-a)

## Clasa a IX-a

### Cifrele unui număr

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Numărul de apariții ale cifrei k](clasa-09/01-cifre/aparitiile-unei-cifre.cpp) | Parcurgem cifrele lui n și numărăm câte sunt egale cu k. | O(c) |
| [Cel mai mare număr format cu cifrele lui n](clasa-09/01-cifre/cel-mai-mare-numar-din-cifre.cpp) | Numărăm de câte ori apare fiecare cifră, într-un vector de | O(k) |
| [Cifra de control](clasa-09/01-cifre/cifra-de-control.cpp) | Cifra de control se obține înlocuind numărul cu suma cifrelor lui, | O(k) |
| [Cifra maximă și cifra minimă](clasa-09/01-cifre/cifra-maxima-si-minima.cpp) | Pornim cu maximul 0 (cea mai mică cifră posibilă) și minimul 9 | O(k) |
| [Verificarea cifrelor distincte](clasa-09/01-cifre/cifre-distincte.cpp) | Verifică dacă toate cifrele lui n sunt diferite. Ținem minte ce | O(k) |
| [Afișarea cifrelor în ordinea din număr](clasa-09/01-cifre/cifrele-in-ordinea-din-numar.cpp) | Cu n % 10 cifrele ies de la dreapta la stânga. Ca să le afișăm de | O(k) |
| [Dublarea cifrelor impare](clasa-09/01-cifre/dublarea-cifrelor-impare.cpp) | Fiecare cifră impară a lui n apare de două ori în rezultat. | O(k) |
| [Eliminarea cifrelor pare](clasa-09/01-cifre/eliminarea-cifrelor-pare.cpp) | Construim un număr nou din cifrele impare ale lui n, păstrând | O(k) |
| [Înlocuirea unei cifre cu alta](clasa-09/01-cifre/inlocuirea-unei-cifre.cpp) | Înlocuiește în n fiecare apariție a cifrei x cu cifra y. | O(k) |
| [Număr palindrom](clasa-09/01-cifre/numar-palindrom.cpp) | Un număr este palindrom dacă se citește la fel de la stânga la | O(k) |
| [Numărul de cifre ale unui număr](clasa-09/01-cifre/numarul-de-cifre.cpp) | Numără cifrele lui n tăind la fiecare pas ultima cifră (n / 10) | O(k) |
| [Oglinditul unui număr](clasa-09/01-cifre/oglinditul-unui-numar.cpp) | Construiește numărul format din cifrele lui n scrise în ordine inversă. | O(k) |
| [Prima cifră a unui număr](clasa-09/01-cifre/prima-cifra.cpp) | Prima cifră (cea din stânga) rămâne după ce tăiem toate celelalte | O(k) |
| [Produsul cifrelor unui număr](clasa-09/01-cifre/produsul-cifrelor.cpp) | Înmulțește cifrele lui n. Produsul pornește de la 1 (elementul | O(k) |
| [Suma cifrelor unui număr](clasa-09/01-cifre/suma-cifrelor.cpp) | Adună cifrele lui n. Ultima cifră se obține cu n % 10, apoi este | O(k) |

### Divizibilitate și numere prime

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Cmmdc prin împărțiri repetate (algoritmul lui Euclid)](clasa-09/02-divizibilitate/cmmdc-prin-impartiri.cpp) | Cel mai mare divizor comun nu se schimbă dacă înlocuim perechea | O(log(min(a |
| [Cmmdc prin scăderi repetate](clasa-09/02-divizibilitate/cmmdc-prin-scaderi.cpp) | Scădem numărul mai mic din cel mai mare până când devin egale; | O(max(a |
| [Cel mai mic multiplu comun](clasa-09/02-divizibilitate/cmmmc.cpp) | Se folosește relația cmmdc(a, b) * cmmmc(a, b) = a * b. Calculăm | O(log(min(a |
| [Descompunerea în factori primi](clasa-09/02-divizibilitate/descompunerea-in-factori-primi.cpp) | Încercăm factorii d = 2, 3, 4, ... și împărțim n la d de câte ori | O(√n) |
| [Divizorii primi ai unui număr](clasa-09/02-divizibilitate/divizorii-primi.cpp) | Este descompunerea în factori primi, din care afișăm doar factorii, | O(√n) |
| [Divizorii proprii ai unui număr](clasa-09/02-divizibilitate/divizorii-proprii.cpp) | Divizorii proprii sunt divizorii diferiți de 1 și de n. Folosim | O(√n) |
| [Divizorii unui număr](clasa-09/02-divizibilitate/divizorii-unui-numar.cpp) | Divizorii vin în perechi: dacă d divide n, atunci și n / d divide n, | O(√n) |
| [Indicatorul lui Euler](clasa-09/02-divizibilitate/indicatorul-lui-euler.cpp) | φ(n) este numărul valorilor din 1..n prime cu n. Dacă p1, p2, ... | O(√n) |
| [Număr perfect](clasa-09/02-divizibilitate/numar-perfect.cpp) | Un număr este perfect dacă este egal cu suma divizorilor săi mai | O(√n) |
| [Numărul divizorilor](clasa-09/02-divizibilitate/numarul-divizorilor.cpp) | Pentru fiecare d cu d * d <= n care divide n numărăm doi divizori, | O(√n) |
| [Perechi de numere prime gemene](clasa-09/02-divizibilitate/numere-prime-gemene.cpp) | Două numere prime sunt gemene dacă diferența lor este 2 | O(n · √n) |
| [Numere prime între ele](clasa-09/02-divizibilitate/numere-prime-intre-ele.cpp) | Două numere sunt prime între ele dacă singurul lor divizor comun | O(log(min(a |
| [Primele n numere prime](clasa-09/02-divizibilitate/primele-n-numere-prime.cpp) | Luăm pe rând candidații 2, 3, 4, ... și îi testăm cu testul de | aproximativ O(n · √P) |
| [Simplificarea unei fracții](clasa-09/02-divizibilitate/simplificarea-unei-fractii.cpp) | O fracție a / b devine ireductibilă dacă împărțim numărătorul și | O(log(min(a |
| [Suma divizorilor](clasa-09/02-divizibilitate/suma-divizorilor.cpp) | Adunăm divizorii în perechi (d și n / d) pentru d * d <= n; când | O(√n) |
| [Test de primalitate](clasa-09/02-divizibilitate/test-de-primalitate.cpp) | Un număr este prim dacă are exact doi divizori: 1 și el însuși | O(√n) |
| [Ultima cifră a lui x la puterea y](clasa-09/02-divizibilitate/ultima-cifra-a-puterii.cpp) | Ultima cifră a unui produs depinde doar de ultimele cifre ale | O(1) |

### Șiruri de numere citite pe rând

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Cea mai lungă secvență de elemente egale](clasa-09/03-secvente/cea-mai-lunga-secventa-de-egale.cpp) | O secvență înseamnă elemente aflate pe poziții consecutive. | O(n) |
| [Cel mai mare termen Fibonacci cel mult egal cu n](clasa-09/03-secvente/cel-mai-mare-termen-fibonacci.cpp) | Generăm termenii șirului lui Fibonacci (1, 1, 2, 3, 5, ...) cât | O(log n) |
| [Cele mai mari două valori](clasa-09/03-secvente/cele-mai-mari-doua-valori.cpp) | Ținem minte cea mai mare valoare (max1) și a doua (max2). Dacă | O(n) |
| [Citirea unui șir terminat cu 0](clasa-09/03-secvente/citire-pana-la-zero.cpp) | Nu știm dinainte câte numere urmează: citim până la primul 0, | O(n) |
| [Cmmdc-ul mai multor numere](clasa-09/03-secvente/cmmdc-al-mai-multor-numere.cpp) | cmmdc(a, b, c) = cmmdc(cmmdc(a, b), c). Păstrăm în rez cmmdc-ul | O(n · log M) |
| [Al n-lea termen al șirului lui Fibonacci](clasa-09/03-secvente/fibonacci-al-n-lea-termen.cpp) | Șirul lui Fibonacci începe cu 1, 1 și fiecare termen este suma | O(n) |
| [Maximul și minimul unui șir](clasa-09/03-secvente/maxim-si-minim.cpp) | Se citesc n și apoi n numere întregi. Maximul și minimul pornesc | O(n) |
| [Numărarea elementelor cu o proprietate](clasa-09/03-secvente/numarare-cu-proprietate.cpp) | Se citesc n și n numere naturale. Numărăm câte dintre ele sunt | O(n · k) |
| [Numărul de schimbări de semn](clasa-09/03-secvente/numarul-de-schimbari-de-semn.cpp) | Se citesc n numere nenule. O schimbare de semn are loc între doi | O(n) |
| [Perechi de termeni consecutivi cu o proprietate](clasa-09/03-secvente/perechi-consecutive.cpp) | Numărăm perechile de termeni aflați unul după altul care au | O(n) |
| [Verificarea unei progresii aritmetice](clasa-09/03-secvente/progresie-aritmetica.cpp) | Un șir este progresie aritmetică dacă diferența dintre doi termeni | O(n) |
| [Verificarea unui șir crescător](clasa-09/03-secvente/sir-crescator.cpp) | Șirul este crescător dacă fiecare număr este cel puțin egal cu | O(n) |
| [Suma și media aritmetică](clasa-09/03-secvente/suma-si-media-aritmetica.cpp) | Se citesc n și n numere întregi; se afișează suma și media lor | O(n) |

### Baze de numerație

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Conversia din baza 10 în baza b](clasa-09/04-baze/baza-10-in-baza-b.cpp) | Împărțim repetat n la b; resturile sunt cifrele în baza b, dar | O(log_b n) |
| [Conversia în baza 10 cu puterile bazei](clasa-09/04-baze/baza-b-in-baza-10-cu-puteri.cpp) | Varianta pentru b <= 10, când numărul se poate citi ca întreg: | O(k) |
| [Conversia din baza b în baza 10](clasa-09/04-baze/baza-b-in-baza-10.cpp) | Numărul în baza b se citește ca text (poate conține A..F), apoi | O(k) |
| [Conversia între două baze oarecare](clasa-09/04-baze/conversie-intre-doua-baze.cpp) | Trecem prin baza 10: întâi transformăm numărul din baza b1 în | O(k1 + k2) |
| [Numărul de biți 1 din scrierea în baza 2](clasa-09/04-baze/numarul-bitilor-de-1.cpp) | Cifrele în baza 2 se obțin la fel ca cifrele în baza 10, doar că | O(log n) |
| [Verificarea unei puteri a lui 2](clasa-09/04-baze/putere-a-lui-2.cpp) | O putere a lui 2 are în baza 2 un singur bit de 1 (de exemplu | O(1) |

### Tablouri unidimensionale (vectori)

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Citirea și afișarea unui vector](clasa-09/05-vectori/citire-si-afisare.cpp) | Un vector păstrează mai multe valori de același tip, accesate prin | O(n) |
| [Eliminarea elementelor pare](clasa-09/05-vectori/eliminarea-elementelor-pare.cpp) | În loc să ștergem elementele pare unul câte unul (fiecare ștergere | O(n) |
| [Inserarea unei valori după fiecare element par](clasa-09/05-vectori/inserare-dupa-elementele-pare.cpp) | Parcurgem vectorul de la sfârșit spre început. Când v[i] este par, | O(n²) în cazul cel mai rău (multe inserări) |
| [Inserarea unui element pe o poziție](clasa-09/05-vectori/inserarea-pe-o-pozitie.cpp) | Ca să punem val pe poziția poz, facem loc: mutăm elementele | O(n) |
| [Inversarea unui vector](clasa-09/05-vectori/inversarea-vectorului.cpp) | Interschimbăm primul element cu ultimul, al doilea cu penultimul | O(n) |
| [Maximul și pozițiile pe care apare](clasa-09/05-vectori/maximul-si-pozitiile-lui.cpp) | Spre deosebire de un șir citit pe rând, un vector poate fi | O(n) |
| [Permutarea circulară la dreapta](clasa-09/05-vectori/permutare-circulara-la-dreapta.cpp) | Fiecare element se mută cu o poziție la dreapta, iar ultimul | O(n) |
| [Permutarea circulară la stânga](clasa-09/05-vectori/permutare-circulara-la-stanga.cpp) | Fiecare element se mută cu o poziție la stânga, iar primul ajunge | O(n) |
| [Ștergerea elementului de pe o poziție](clasa-09/05-vectori/stergerea-unui-element.cpp) | Ca să ștergem elementul de pe poziția poz, mutăm elementele de | O(n) |
| [Suma elementelor de pe pozițiile pare și impare](clasa-09/05-vectori/suma-pe-pozitii-pare-si-impare.cpp) | Atenție la diferența dintre poziție (indicele i) și valoare (v[i]). | O(n) |
| [Verificarea unui vector simetric](clasa-09/05-vectori/vector-simetric.cpp) | Un vector este simetric (palindrom) dacă v[i] = v[n - i + 1] | O(n) |

### Sortare și căutare

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Căutarea binară](clasa-09/06-sortare-cautare/cautare-binara.cpp) | Funcționează doar pe un vector sortat crescător. Comparăm x cu | O(log n) |
| [Căutarea secvențială](clasa-09/06-sortare-cautare/cautare-secventiala.cpp) | Verificăm elementele pe rând, de la primul, până găsim valoarea x | O(n) |
| [Interclasarea a doi vectori sortați](clasa-09/06-sortare-cautare/interclasare.cpp) | Din doi vectori sortați crescător construim un al treilea, tot | O(n + m) |
| [Prima poziție cu valoare mai mare sau egală cu x](clasa-09/06-sortare-cautare/prima-pozitie-mai-mare-sau-egala.cpp) | Varianta de căutare binară care nu se oprește la prima potrivire: | O(log n) |
| [Sortarea cu std::sort](clasa-09/06-sortare-cautare/sortare-cu-std-sort.cpp) | Biblioteca <algorithm> are funcția sort, care ordonează în | O(n log n) |
| [Sortarea după două criterii](clasa-09/06-sortare-cautare/sortare-dupa-doua-criterii.cpp) | Ordonăm numerele crescător după ultima cifră, iar numerele cu | O(n²) |
| [Sortarea prin inserție](clasa-09/06-sortare-cautare/sortare-prin-insertie.cpp) | Ca la aranjarea cărților de joc în mână: primele i - 1 elemente | O(n²) în cazul cel mai rău |
| [Sortarea prin metoda bulelor](clasa-09/06-sortare-cautare/sortare-prin-metoda-bulelor.cpp) | Parcurgem vectorul și interschimbăm oricare două elemente vecine | O(n²) în cazul cel mai rău |
| [Sortarea prin numărare](clasa-09/06-sortare-cautare/sortare-prin-numarare.cpp) | Când valorile sunt numere naturale mici (aici 0..10000), nu | O(n + V) |
| [Sortarea prin selecție](clasa-09/06-sortare-cautare/sortare-prin-selectie.cpp) | Pentru fiecare poziție i, de la 1 la n - 1, căutăm minimul din | O(n²) |

### Frecvență, sume parțiale și ciurul lui Eratostene

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Cifrele comune a două numere](clasa-09/07-tehnici-vectori/cifre-comune.cpp) | Marcăm în doi vectori de 10 poziții ce cifre apar în fiecare | O(ka + kb) |
| [Ciurul lui Eratostene](clasa-09/07-tehnici-vectori/ciurul-lui-eratostene.cpp) | Găsește toate numerele prime până la n. Pornim cu toate numerele | O(n log log n) |
| [Elementul majoritar](clasa-09/07-tehnici-vectori/element-majoritar.cpp) | Elementul majoritar apare de mai mult de n / 2 ori. Algoritmul prin | O(n) |
| [Numărul lipsă dintr-o permutare](clasa-09/07-tehnici-vectori/numarul-lipsa.cpp) | Se dau n și n - 1 numere distincte din mulțimea {1, 2, ..., n}; | O(n) |
| [Secvența de lungime k cu suma maximă](clasa-09/07-tehnici-vectori/secventa-de-lungime-k.cpp) | Fereastra glisantă: calculăm suma primelor k elemente, apoi | O(n) |
| [Secvența de sumă maximă (algoritmul lui Kadane)](clasa-09/07-tehnici-vectori/secventa-de-suma-maxima.cpp) | Parcurgem vectorul și păstrăm suma secvenței curente, care se | O(n) |
| [Sume parțiale](clasa-09/07-tehnici-vectori/sume-partiale.cpp) | s[i] = v[1] + v[2] + ... + v[i], cu s[0] = 0, se calculează într-o | O(n + q) |
| [Valorile distincte și frecvențele lor](clasa-09/07-tehnici-vectori/valori-distincte-si-frecvente.cpp) | După ce am construit vectorul de frecvență, valorile distincte | O(n + V) |
| [Marcarea intervalelor cu vectorul de diferențe](clasa-09/07-tehnici-vectori/vector-de-diferente.cpp) | Avem n poziții, inițial 0, și m operații „adună 1 pe pozițiile | O(n + m) |
| [Vectorul de frecvență](clasa-09/07-tehnici-vectori/vector-de-frecventa.cpp) | Pentru valori naturale mici (aici 0..1000), frecv[x] reține de câte | O(n + V) |

### Fișiere text

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Citirea până la sfârșitul fișierului](clasa-09/08-fisiere/citire-pana-la-sfarsitul-fisierului.cpp) | Fișierul date.in conține numere întregi, dar nu știm câte. Expresia | O(n) |
| [Numărarea valorilor dintr-un fișier](clasa-09/08-fisiere/numararea-valorilor.cpp) | Fișierul date.in conține pe prima linie un număr natural k, iar pe | O(n) |
| [Prelucrarea unui fișier pe linii](clasa-09/08-fisiere/prelucrare-pe-linii.cpp) | getline(fin, linie) citește un rând întreg, cu tot cu spații, până | O(L) |
| [Scrierea formatată într-un fișier](clasa-09/08-fisiere/scriere-in-fisier.cpp) | Se citește n din date.in și se scriu în date.out numerele de la 1 | O(n) |
| [Suma numerelor de pe fiecare linie](clasa-09/08-fisiere/suma-pe-fiecare-linie.cpp) | Fiecare linie din date.in conține câteva numere întregi, în număr | O(L) |

## Clasa a X-a

### Subprograme (funcții)

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Funcție cmmdc și cmmmc](clasa-10/01-subprograme/functie-cmmdc.cpp) | Funcția cmmdc(a, b) aplică algoritmul lui Euclid prin împărțiri: | O(log(min(a |
| [Funcție de primalitate](clasa-10/01-subprograme/functie-de-primalitate.cpp) | Scriem o singură dată funcția estePrim(x), care întoarce true dacă | O(n * sqrt(M)) |
| [Funcție cu vector ca parametru (maximul)](clasa-10/01-subprograme/functie-maxim-vector.cpp) | Un vector se transmite unei funcții împreună cu numărul de elemente: | O(n) |
| [Funcție care întoarce oglinditul](clasa-10/01-subprograme/functie-oglindit.cpp) | Funcția oglindit(x) construiește numărul cu cifrele lui x în ordine | O(k) |
| [Funcție pentru suma cifrelor](clasa-10/01-subprograme/functie-suma-cifrelor.cpp) | Funcția sumaCifre(x) primește numărul prin valoare (lucrează pe o | O(n * k) |
| [Interschimbare prin referință](clasa-10/01-subprograme/interschimbare-prin-referinta.cpp) | Comparăm două funcții care încearcă să schimbe între ele valorile a | O(1) |
| [Minim și maxim întoarse prin referință](clasa-10/01-subprograme/minim-si-maxim-prin-referinta.cpp) | O funcție poate întoarce cu return o singură valoare. Când avem nevoie | O(n) |
| [Numere prietene](clasa-10/01-subprograme/numere-prietene.cpp) | Două numere a și b sunt prietene dacă suma divizorilor proprii ai lui a | O(sqrt(a) + sqrt(b)) |
| [Numere superprime](clasa-10/01-subprograme/numere-superprime.cpp) | Un număr este superprim dacă toate prefixele lui sunt numere prime. | O(n * k * sqrt(n)) |
| [Palindroame dintr-un interval](clasa-10/01-subprograme/palindroame-dintr-un-interval.cpp) | Problemă rezolvată prin descompunere în funcții mici: oglindit(x) | O((b - a) * k) |
| [Variabile globale și variabile locale](clasa-10/01-subprograme/variabile-globale-si-locale.cpp) | O variabilă globală (declarată în afara funcțiilor) se vede din tot | O(n) |

### Tablouri bidimensionale (matrice)

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Bordarea matricei](clasa-10/02-matrice/bordarea-matricei.cpp) | A borda o matrice înseamnă a-i adăuga o linie și/sau o coloană nouă | O(n * m) |
| [Citirea și afișarea unei matrice](clasa-10/02-matrice/citire-si-afisare.cpp) | O matrice cu n linii și m coloane se declară ca int a[101][101] și se | O(n * m) |
| [Diagonala principală și diagonala secundară](clasa-10/02-matrice/diagonale.cpp) | Într-o matrice pătratică n x n, indexată de la 1, elementele de pe | O(n) pentru parcurgere (citirea este O(n * n)) |
| [Linia cu suma maximă](clasa-10/02-matrice/linia-cu-suma-maxima.cpp) | Calculăm suma fiecărei linii și o comparăm cu cea mai mare sumă găsită | O(n * m) |
| [Generarea matricei în serpentină](clasa-10/02-matrice/matrice-in-serpentina.cpp) | Completăm matricea cu numerele 1, 2, ..., n * m „în zigzag”: liniile | O(n * m) |
| [Verificarea matricei simetrice](clasa-10/02-matrice/matrice-simetrica.cpp) | O matrice pătratică este simetrică față de diagonala principală dacă | O(n * n) în cel mai rău caz |
| [Parcurgerea în spirală](clasa-10/02-matrice/parcurgere-in-spirala.cpp) | Ținem patru margini: sus, jos, stanga, dreapta. La fiecare tură | O(n * m) |
| [Produsul a două matrice](clasa-10/02-matrice/produsul-a-doua-matrice.cpp) | Produsul se poate face doar dacă numărul de coloane al lui A este egal | O(n * m * p) |
| [Punct șa](clasa-10/02-matrice/punct-sa.cpp) | Un punct șa este un element care este minim pe linia lui și maxim pe | O(n * m * (n + m)) |
| [Rotirea unei matrice cu 90 de grade](clasa-10/02-matrice/rotire-cu-90-de-grade.cpp) | La rotirea în sensul acelor de ceasornic, prima coloană citită de jos | O(n * m) |
| [Ștergerea unei linii și a unei coloane](clasa-10/02-matrice/stergerea-unei-linii-si-coloane.cpp) | Ca la vectori, ștergerea înseamnă mutarea elementelor peste cel șters. | O(n * m) |
| [Suma pe linii și pe coloane](clasa-10/02-matrice/suma-pe-linii-si-coloane.cpp) | Pentru suma liniei i ținem i fix și plimbăm j de la 1 la m. Pentru | O(n * m) |
| [Generarea tablei de șah](clasa-10/02-matrice/tabla-de-sah.cpp) | Pe o tablă de șah, culoarea pătratului depinde doar de paritatea | O(n * n) |
| [Transpusa unei matrice](clasa-10/02-matrice/transpusa.cpp) | Transpusa matricei a (n linii, m coloane) are m linii și n coloane: | O(n * m) |
| [Cele patru zone ale matricei pătratice](clasa-10/02-matrice/zonele-matricei-patratice.cpp) | Cele două diagonale împart o matrice pătratică în patru zone (fără | O(n * n) |

### Șiruri de caractere

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Cel mai lung cuvânt](clasa-10/03-siruri-caractere/cel-mai-lung-cuvant.cpp) | Împărțim fraza în cuvinte cu strtok și păstrăm cuvântul cu lungimea | O(L) |
| [Cifrul lui Cezar](clasa-10/03-siruri-caractere/cifrul-lui-cezar.cpp) | Fiecare literă se înlocuiește cu litera aflată la k poziții mai | O(L) |
| [Cuvintele palindrom dintr-o frază](clasa-10/03-siruri-caractere/cuvinte-palindrom.cpp) | Combinăm două lucruri învățate: strtok împarte fraza în cuvinte, iar | O(L) |
| [Eliminarea vocalelor](clasa-10/03-siruri-caractere/eliminarea-vocalelor.cpp) | Ștergem vocalele chiar în șirul inițial, cu doi indici: i citește | O(L) |
| [Extragerea numerelor dintr-un text](clasa-10/03-siruri-caractere/extragerea-numerelor-din-text.cpp) | Parcurgem textul; când întâlnim o cifră, construim numărul ca la | O(L) |
| [Frecvența literelor](clasa-10/03-siruri-caractere/frecventa-literelor.cpp) | Numărăm de câte ori apare fiecare literă, fără să facem diferența între | O(L + 26) |
| [Împărțirea în cuvinte cu strtok](clasa-10/03-siruri-caractere/impartirea-in-cuvinte-cu-strtok.cpp) | strtok(s, separatori) întoarce primul cuvânt din s; apelurile | O(L) |
| [Înlocuirea unui cuvânt cu altul](clasa-10/03-siruri-caractere/inlocuirea-unui-cuvant.cpp) | Se citesc un text și două cuvinte, vechi și nou (fiecare pe câte un | O(L) |
| [Transformarea în majuscule și minuscule](clasa-10/03-siruri-caractere/majuscule-si-minuscule.cpp) | În tabelul ASCII literele mari 'A'..'Z' și cele mici 'a'..'z' sunt la | O(L) |
| [Numărarea cuvintelor](clasa-10/03-siruri-caractere/numararea-cuvintelor.cpp) | Fără strtok: un cuvânt începe acolo unde un caracter diferit de spațiu | O(L) |
| [Numărarea vocalelor](clasa-10/03-siruri-caractere/numararea-vocalelor.cpp) | Pentru fiecare caracter verificăm dacă apare în șirul "aeiouAEIOU" cu | O(L) |
| [Operații cu std::string](clasa-10/03-siruri-caractere/operatii-cu-string.cpp) | Clasa string din <string> își gestionează singură memoria: se atribuie | fiecare operație este O(L) |
| [Parcurgerea unui șir și lungimea lui](clasa-10/03-siruri-caractere/parcurgere-si-lungime.cpp) | Un șir de caractere în stil C este un vector de char terminat cu | O(L) |
| [Sortarea alfabetică a cuvintelor](clasa-10/03-siruri-caractere/sortarea-alfabetica-a-cuvintelor.cpp) | Separăm fraza în cuvinte cu strtok și le copiem într-o matrice de | O(k * k * L) |
| [Verificarea unui șir palindrom](clasa-10/03-siruri-caractere/verificare-palindrom.cpp) | Întâi păstrăm doar literele, transformate în minuscule (așa | O(L) |
| [Verificarea anagramelor](clasa-10/03-siruri-caractere/verificarea-anagramelor.cpp) | Două cuvinte sunt anagrame dacă au aceleași litere, de același număr | O(L1 + L2) |

### Tipul struct

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Compararea datelor calendaristice](clasa-10/04-structuri/date-calendaristice.cpp) | O dată calendaristică are trei câmpuri: zi, luna, an. Două date se | O(n * n) cu sortarea prin selecție |
| [Adunarea duratelor (ore, minute, secunde)](clasa-10/04-structuri/durate-ore-minute-secunde.cpp) | O durată se ține într-o structură cu trei câmpuri. Ca să adunăm | O(n) |
| [Elevi sortați după medie și nume](clasa-10/04-structuri/elevi-sortati-dupa-medie.cpp) | Tipul struct grupează sub un singur nume date de tipuri diferite: | O(n * n * L) cu sortarea prin selecție |
| [Operații cu fracții](clasa-10/04-structuri/operatii-cu-fractii.cpp) | O fracție are două câmpuri, numărătorul a și numitorul b, deci o | O(log(numitor)) pentru simplificare |
| [Puncte în plan](clasa-10/04-structuri/puncte-in-plan.cpp) | Un punct are coordonatele x și y: struct Punct { int x, y; }. Distanța | O(n * n) pentru distanța maximă |

### Recursivitate

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Afișarea cifrelor în ordine, recursiv](clasa-10/05-recursivitate/afisarea-cifrelor-in-ordine.cpp) | Contează unde punem afișarea față de autoapel. În inOrdine afișăm | O(k) |
| [Cmmdc recursiv](clasa-10/05-recursivitate/cmmdc-recursiv.cpp) | Algoritmul lui Euclid scris recursiv: cmmdc(a, 0) = a, iar | O(log(min(a |
| [Conversia în baza 2, recursiv](clasa-10/05-recursivitate/conversie-in-baza-2-recursiv.cpp) | La conversia prin împărțiri repetate la 2, resturile se obțin în | O(log n) |
| [Factorial recursiv](clasa-10/05-recursivitate/factorial-recursiv.cpp) | Definiția matematică este deja recursivă: 0! = 1 și n! = n * (n - 1)!. | O(n) timp și O(n) memorie pe stivă |
| [Fibonacci recursiv](clasa-10/05-recursivitate/fibonacci-recursiv.cpp) | Șirul lui Fibonacci: F(0) = 0, F(1) = 1, F(n) = F(n - 1) + F(n - 2). | O(φ^n) apeluri |
| [Funcția Ackermann](clasa-10/05-recursivitate/functia-ackermann.cpp) | Funcția Ackermann are două argumente: A(0, n) = n + 1; | crește mai repede decât orice funcție exponențială |
| [Funcția Manna-Pnueli](clasa-10/05-recursivitate/functia-manna-pnueli.cpp) | Funcția este definită astfel: f(x) = x - 1 dacă x >= 12, altfel | O(12 - x) apeluri pentru x < 12 |
| [Inversarea unui șir de caractere, recursiv](clasa-10/05-recursivitate/inversarea-unui-sir-recursiv.cpp) | Funcția inverseaza(s, i) se ocupă de caracterele de la poziția i până la | O(L) timp și O(L) memorie pe stivă |
| [Numărul de apariții într-un vector, recursiv](clasa-10/05-recursivitate/numarul-de-aparitii-recursiv.cpp) | Numărul aparițiilor lui x printre primele n elemente este numărul | O(n) |
| [Palindrom recursiv](clasa-10/05-recursivitate/palindrom-recursiv.cpp) | Un cuvânt este palindrom dacă primul și ultimul caracter sunt egale și | O(L) |
| [Puterea unui număr, recursiv](clasa-10/05-recursivitate/putere-recursiva.cpp) | Varianta directă folosește a^n = a * a^(n - 1) și face n apeluri. | O(n) pentru varianta directă |
| [Suma cifrelor, recursiv](clasa-10/05-recursivitate/suma-cifrelor-recursiva.cpp) | Suma cifrelor lui n este ultima cifră (n % 10) plus suma cifrelor | O(k) |

### Divide et impera

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Căutare binară recursivă](clasa-10/06-divide-et-impera/cautare-binara-recursiva.cpp) | Vectorul este sortat crescător. Comparăm x cu elementul din mijloc: | O(log n) |
| [Cmmdc-ul elementelor unui vector prin divide et impera](clasa-10/06-divide-et-impera/cmmdc-elementelor-unui-vector.cpp) | Cmmdc-ul unei porțiuni este cmmdc-ul dintre cmmdc-ul jumătății stângi | O(n log M) |
| [Maximul unui vector prin divide et impera](clasa-10/06-divide-et-impera/maximul-unui-vector.cpp) | Cele trei etape ale metodei: împărțim porțiunea [st, dr] în două | O(n) |
| [Numărul elementelor pare prin divide et impera](clasa-10/06-divide-et-impera/numarul-elementelor-pare.cpp) | Același tipar ca la sumă: rezultatul pentru porțiunea [st, dr] este | O(n) |
| [Sortarea prin interclasare (Merge Sort)](clasa-10/06-divide-et-impera/sortare-prin-interclasare.cpp) | Împărțim vectorul în două jumătăți, sortăm recursiv fiecare jumătate, | O(n log n) în orice caz |
| [Sortarea rapidă (Quick Sort)](clasa-10/06-divide-et-impera/sortare-rapida.cpp) | Alegem un pivot (aici elementul din mijloc) și rearanjăm porțiunea | O(n log n) în medie |
| [Suma elementelor prin divide et impera](clasa-10/06-divide-et-impera/suma-elementelor.cpp) | Suma porțiunii [st, dr] este suma jumătății stângi [st, m] plus suma | O(n) |
| [Turnurile din Hanoi](clasa-10/06-divide-et-impera/turnurile-din-hanoi.cpp) | Avem n discuri pe tija A, în ordine descrescătoare a mărimii, și vrem | O(2^n) |

## Clasa a XI-a

### Metoda backtracking

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Generarea aranjamentelor](clasa-11/01-backtracking/aranjamente.cpp) | Afișează, în ordine lexicografică, toate aranjamentele de n elemente luate | O(A(n |
| [Colorarea hărților](clasa-11/01-backtracking/colorarea-hartilor.cpp) | O hartă are n țări numerotate de la 1, iar m perechi (a, b) spun că țările | O(4^n · n) în cel mai rău caz |
| [Generarea combinărilor](clasa-11/01-backtracking/combinari.cpp) | Afișează toate submulțimile cu k elemente ale mulțimii {1, ..., n} | O(C(n |
| [Drumuri într-un labirint](clasa-11/01-backtracking/drumuri-in-labirint.cpp) | Labirintul este o matrice n × m cu 0 (liber) și 1 (zid). Pornim din colțul | exponențială (numărul de drumuri poate fi foarte mare) |
| [Problema celor n dame](clasa-11/01-backtracking/n-dame.cpp) | Așezăm n dame pe o tablă n × n astfel încât să nu se atace (nicio pereche | exponențială; mult sub n^n datorită condițiilor de continuare |
| [Generarea parantezărilor corecte](clasa-11/01-backtracking/paranteze-corecte.cpp) | Afișează, în ordine lexicografică ('(' înaintea lui ')'), toate șirurile | O(Catalan(n) · n) timp |
| [Partițiile unui număr natural](clasa-11/01-backtracking/partitiile-unui-numar.cpp) | Afișează toate modurile de a scrie n ca sumă de numere naturale nenule, | proporțională cu numărul de partiții (crește exponențial cu n) |
| [Permutări cu vecini de parități diferite](clasa-11/01-backtracking/permutari-paritati-alternante.cpp) | Afișează permutările mulțimii {1, ..., n} în care oricare două elemente | O(n! · n) în cel mai rău caz |
| [Generarea permutărilor](clasa-11/01-backtracking/permutari.cpp) | Afișează, în ordine lexicografică, toate permutările mulțimii {1, 2, ..., n}. | O(n! · n) timp |
| [Plata unei sume cu monede date](clasa-11/01-backtracking/plata-unei-sume-cu-monede.cpp) | Avem n tipuri de monede, cu valorile v[1..n], din fiecare câte vrem. | exponențială în n (numărul de combinații încercate) |
| [Produsul cartezian](clasa-11/01-backtracking/produs-cartezian.cpp) | Se dau n mulțimi; mulțimea i este {1, 2, ..., a[i]}. Se afișează toate | O(a[1] · ... · a[n] · n) timp |
| [Generarea submulțimilor](clasa-11/01-backtracking/submultimi.cpp) | Afișează toate submulțimile nevide ale mulțimii {1, ..., n}, în ordine | O(2^n · n) timp |

### Metoda greedy

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Acoperirea unui segment cu număr minim de intervale](clasa-11/02-greedy/acoperirea-unui-segment.cpp) | Vrem să acoperim segmentul [A, B] folosind cât mai puține dintre cele n | O(n log n) |
| [Planificarea spectacolelor](clasa-11/02-greedy/planificarea-spectacolelor.cpp) | Într-o sală se pot ține n spectacole; spectacolul i începe la ora s[i] și se | O(n log n) pentru sortare |
| [Plata unei sume cu număr minim de bancnote](clasa-11/02-greedy/plata-cu-numar-minim-de-bancnote.cpp) | Se dau n valori de bancnote (din fiecare avem oricâte) și o sumă S. | O(n log n) pentru sortare |
| [Problema rucsacului (varianta fracționară)](clasa-11/02-greedy/rucsacul-fractionar.cpp) | Un rucsac suportă cel mult G kilograme. Avem n obiecte; obiectul i are | O(n log n) |
| [Suma maximă cu k elemente](clasa-11/02-greedy/suma-maxima-cu-k-elemente.cpp) | Dintr-un șir de n numere întregi alegem exact k elemente (pe poziții | O(n log n) |
| [Minimizarea timpului mediu de așteptare](clasa-11/02-greedy/timp-mediu-de-asteptare.cpp) | La un ghișeu așteaptă n clienți; servirea clientului i durează t[i] minute. | O(n log n) |

### Programare dinamică

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Cel mai lung subșir comun](clasa-11/03-programare-dinamica/cel-mai-lung-subsir-comun.cpp) | Se dau două cuvinte a și b. Căutăm cel mai lung șir de litere care apare ca | O(n · m) timp și memorie |
| [Distanța de editare](clasa-11/03-programare-dinamica/distanta-de-editare.cpp) | Câte operații sunt necesare, minim, ca să transformăm cuvântul a în cuvântul b? | O(n · m) timp și memorie |
| [Drum de sumă maximă în matrice](clasa-11/03-programare-dinamica/drum-de-suma-maxima-in-matrice.cpp) | Într-o matrice n × m pornim din colțul (1, 1) și ajungem în (n, m) mergând | O(n · m) timp și memorie |
| [Numărul de drumuri într-o grilă cu obstacole](clasa-11/03-programare-dinamica/drumuri-in-grila-cu-obstacole.cpp) | O grilă n × m are celule libere (0) și obstacole (1). Câte drumuri duc din | O(n · m) timp și memorie |
| [Numărul minim de monede](clasa-11/03-programare-dinamica/numarul-minim-de-monede.cpp) | Avem n tipuri de monede (din fiecare oricâte) și vrem să plătim exact suma S | O(n · S) timp |
| [Numărul partițiilor unui număr](clasa-11/03-programare-dinamica/numarul-partitiilor.cpp) | În câte moduri se poate scrie n ca sumă de numere naturale nenule, fără să | O(n²) timp |
| [Problema rucsacului (varianta discretă)](clasa-11/03-programare-dinamica/rucsacul-discret.cpp) | Un rucsac suportă cel mult G kilograme; avem n obiecte cu greutățile g[i] și | O(n · G) timp și memorie |
| [Subșirul strict crescător de lungime maximă](clasa-11/03-programare-dinamica/subsir-crescator-maximal.cpp) | Dintr-un șir de n numere alegem un subșir (elemente în ordinea din șir, nu | O(n²) timp |
| [Suma maximă în triunghiul de numere](clasa-11/03-programare-dinamica/triunghiul-de-numere.cpp) | Un triunghi are n linii; linia i conține i numere. Pornim din vârf și la | O(n²) timp și memorie |
| [Numărul de moduri de a urca o scară](clasa-11/03-programare-dinamica/urcarea-scarii.cpp) | O scară are n trepte; la fiecare pas urcăm fie o treaptă, fie două. În câte | O(n) timp |

### Alocare dinamică: liste, stive, cozi

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Coada implementată cu o listă înlănțuită](clasa-11/04-liste-stive-cozi/coada-cu-lista.cpp) | Coada se ține ca o listă simplu înlănțuită cu doi pointeri: prim (de unde se | O(1) pentru fiecare operație |
| [Coada implementată cu un vector](clasa-11/04-liste-stive-cozi/coada-cu-vector.cpp) | Coada este o structură de tip FIFO (primul intrat, primul ieșit): se adaugă | O(1) pentru fiecare operație |
| [Evaluarea unei expresii în formă poloneză postfixată](clasa-11/04-liste-stive-cozi/forma-poloneza-postfixata.cpp) | În forma postfixată operatorul se scrie după operanzi: (3 + 4) * 2 devine | O(n) |
| [Inserarea într-o listă ordonată](clasa-11/04-liste-stive-cozi/inserarea-in-lista-ordonata.cpp) | Citim n numere și le inserăm pe rând într-o listă simplu înlănțuită păstrată | O(n) pentru o inserare |
| [Lista dublu înlănțuită](clasa-11/04-liste-stive-cozi/lista-dublu-inlantuita.cpp) | Într-o listă dublu înlănțuită fiecare nod reține atât adresa nodului următor | O(1) pentru adăugare la capete |
| [Lista simplu înlănțuită: creare, afișare, adăugare](clasa-11/04-liste-stive-cozi/lista-simplu-inlantuita.cpp) | Fiecare element al listei este un nod alocat dinamic (cu new), care reține | O(1) pentru fiecare adăugare |
| [Ștergerea nodurilor dintr-o listă simplu înlănțuită](clasa-11/04-liste-stive-cozi/stergerea-unui-nod.cpp) | Se creează o listă din n valori, apoi se șterg toate nodurile care conțin | O(n) |
| [Stiva implementată cu o listă înlănțuită](clasa-11/04-liste-stive-cozi/stiva-cu-lista.cpp) | Vârful stivei este primul nod al unei liste simplu înlănțuite. push creează | O(1) pentru fiecare operație |
| [Stiva implementată cu un vector](clasa-11/04-liste-stive-cozi/stiva-cu-vector.cpp) | Stiva este o structură de tip LIFO (ultimul intrat, primul ieșit): se adaugă | O(1) pentru fiecare operație |
| [Verificarea parantezelor cu o stivă](clasa-11/04-liste-stive-cozi/verificarea-parantezelor.cpp) | Un șir format din paranteze ( ) [ ] { } este corect dacă fiecare paranteză | O(n) timp și memorie |

### Grafuri neorientate

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Componentele conexe](clasa-11/05-grafuri-neorientate/componente-conexe.cpp) | Un graf este conex dacă între oricare două noduri există un lanț. O componentă | O(n²) cu matricea de adiacență |
| [Detectarea unui ciclu](clasa-11/05-grafuri-neorientate/detectarea-unui-ciclu.cpp) | Un ciclu este un lanț simplu în care primul nod coincide cu ultimul. Facem o | O(n²) cu matricea de adiacență |
| [Lanțul de lungime minimă între două noduri (BFS)](clasa-11/05-grafuri-neorientate/drum-minim-cu-bfs.cpp) | Lungimea unui lanț este numărul de muchii. Parcurgerea în lățime pornită din x | O(n²) cu matricea de adiacență |
| [Verificarea unui graf bipartit](clasa-11/05-grafuri-neorientate/graf-bipartit.cpp) | Un graf este bipartit dacă nodurile lui se pot împărți în două mulțimi A și B | O(n²) cu matricea de adiacență |
| [Listele de adiacență](clasa-11/05-grafuri-neorientate/liste-de-adiacenta.cpp) | Pentru fiecare nod reținem doar lista vecinilor lui. Muchia [x, y] se adaugă | O(n + m log m) |
| [Matricea de adiacență și gradele nodurilor](clasa-11/05-grafuri-neorientate/matricea-de-adiacenta-si-gradele.cpp) | Un graf neorientat cu n noduri și m muchii se poate memora într-o matrice | O(n² + m) |
| [Noduri izolate și graful complet](clasa-11/05-grafuri-neorientate/noduri-izolate-si-graf-complet.cpp) | Un nod izolat are gradul 0. Un graf este complet dacă oricare două noduri | O(n + m) |
| [Parcurgerea în adâncime (DFS)](clasa-11/05-grafuri-neorientate/parcurgerea-in-adancime-dfs.cpp) | Parcurgerea în adâncime merge cât de departe se poate: din nodul curent trece | O(n²) cu matricea de adiacență (O(n + m) cu liste de adiacență) |
| [Parcurgerea în lățime (BFS)](clasa-11/05-grafuri-neorientate/parcurgerea-in-latime-bfs.cpp) | Parcurgerea în lățime vizitează nodurile „pe straturi”: întâi nodul de start, | O(n²) cu matricea de adiacență (O(n + m) cu liste de adiacență) |
| [Verificarea unui lanț](clasa-11/05-grafuri-neorientate/verificarea-unui-lant.cpp) | O succesiune de noduri x1, x2, ..., xk este lanț dacă oricare două noduri | O(n² + k) |

### Grafuri orientate și drumuri minime

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Componentele tare conexe](clasa-11/06-grafuri-orientate/componente-tare-conexe.cpp) | Un graf orientat este tare conex dacă pentru oricare două noduri x și y există | O(n³) cu matricea de adiacență (n parcurgeri de cost O(n²)) |
| [Drumuri minime de la un nod (algoritmul lui Dijkstra)](clasa-11/06-grafuri-orientate/dijkstra.cpp) | Se cere costul minim al drumului de la nodul s la fiecare alt nod, când toate | O(n²) în această variantă (cu matrice și căutarea minimului) |
| [Gradele interne și externe](clasa-11/06-grafuri-orientate/grade-interne-si-externe.cpp) | Într-un graf orientat muchiile au sens și se numesc arce: arcul (x, y) pleacă | O(n + m) |
| [Matricea drumurilor (algoritmul Roy-Warshall)](clasa-11/06-grafuri-orientate/matricea-drumurilor-roy-warshall.cpp) | Matricea drumurilor are d[i][j] = 1 dacă există un drum (de lungime cel puțin 1) | O(n³) |
| [Drumuri minime între toate perechile de noduri (Roy-Floyd)](clasa-11/06-grafuri-orientate/roy-floyd.cpp) | Fiecare arc (x, y) are un cost c ≥ 0. Matricea costurilor d pornește cu | O(n³) |
| [Sortarea topologică](clasa-11/06-grafuri-orientate/sortare-topologica.cpp) | Arcul (x, y) înseamnă „x trebuie făcut înaintea lui y”. O sortare topologică | O(n² + m) în această variantă |

### Arbori

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Arborele parțial de cost minim (algoritmul lui Kruskal)](clasa-11/07-arbori/apm-kruskal.cpp) | Kruskal construiește arborele parțial de cost minim pornind de la n arbori cu | O(m log m + n²) în această variantă |
| [Arborele parțial de cost minim (algoritmul lui Prim)](clasa-11/07-arbori/apm-prim.cpp) | Într-un graf neorientat conex cu costuri pe muchii căutăm un arbore parțial | O(n²) |
| [Arbore binar de căutare: inserare, căutare, afișare sortată](clasa-11/07-arbori/arbore-binar-de-cautare.cpp) | Într-un arbore binar de căutare, pentru fiecare nod, toate valorile din | O(h) pentru inserare și căutare (h = înălțimea) |
| [Fiii, descendenții și ascendenții unui nod](clasa-11/07-arbori/descendentii-unui-nod.cpp) | Arborele este dat prin vectorul de tați (t[rădăcină] = 0). Fiii lui x sunt | O(n · h) |
| [Diametrul unui arbore](clasa-11/07-arbori/diametrul-unui-arbore.cpp) | Diametrul unui arbore este lungimea (numărul de muchii) celui mai lung lanț | O(n) |
| [Parcurgerile unui arbore binar](clasa-11/07-arbori/parcurgerile-arborelui-binar.cpp) | Într-un arbore binar fiecare nod are cel mult doi fii: unul stâng și unul drept. | O(n) pentru fiecare parcurgere |
| [Vectorul de tați: rădăcină, frunze, niveluri, înălțime](clasa-11/07-arbori/vectorul-de-tati.cpp) | Un arbore cu rădăcină se poate memora prin vectorul de tați: t[i] este tatăl | O(n · h) |
| [Verificarea că un graf este arbore](clasa-11/07-arbori/verificarea-unui-arbore.cpp) | Un arbore este un graf neorientat conex și fără cicluri. Pentru un graf cu n | O(n²) cu matricea de adiacență |

## Clasa a XII-a

### Numere mari

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Adunarea a două numere mari](clasa-12/01-numere-mari/adunarea-a-doua-numere-mari.cpp) | Adunăm ca pe hârtie, de la unități spre stânga. La rangul i | O(max(k1 |
| [Citirea și afișarea unui număr mare](clasa-12/01-numere-mari/citirea-si-afisarea-unui-numar-mare.cpp) | Un număr cu zeci sau sute de cifre nu încape în long long, așa că | O(k) |
| [Compararea a două numere mari](clasa-12/01-numere-mari/compararea-a-doua-numere-mari.cpp) | Fără zerouri nesemnificative, numărul cu mai multe cifre este mai | O(k) |
| [Factorialul unui număr mare](clasa-12/01-numere-mari/factorialul-unui-numar-mare.cpp) | Deja 21! depășește long long, dar n! = 1 * 2 * ... * n se poate | O(n * L) |
| [Termenul n din șirul lui Fibonacci (număr mare)](clasa-12/01-numere-mari/fibonacci-numar-mare.cpp) | Șirul este F(1) = F(2) = 1 și F(i) = F(i - 1) + F(i - 2). Termenii | O(n * L) |
| [Împărțirea unui număr mare la un număr mic](clasa-12/01-numere-mari/impartirea-la-un-numar-mic.cpp) | Spre deosebire de adunare, împărțirea începe de la cifra cea mai | O(k1) |
| [Înmulțirea a două numere mari](clasa-12/01-numere-mari/inmultirea-a-doua-numere-mari.cpp) | Cifra a[i] (rangul 10^i) înmulțită cu cifra b[j] (rangul 10^j) | O(k1 * k2) |
| [Înmulțirea unui număr mare cu un număr mic](clasa-12/01-numere-mari/inmultirea-cu-un-numar-mic.cpp) | Numărul mic k (cel mult 10^9) încape într-un int, deci nu trebuie | O(k1 + c) |
| [Scăderea a două numere mari](clasa-12/01-numere-mari/scaderea-a-doua-numere-mari.cpp) | Calculăm A - B. Dacă A < B, calculăm B - A și punem semnul minus | O(k) |

### Algoritmi pe grile: Lee și fill

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Fill — cea mai mare zonă](clasa-12/02-lee-fill/fill-cea-mai-mare-zona.cpp) | Aceeași matrice de 0 și 1, dar acum vrem numărul de celule al celei | O(n * m) |
| [Fill — numărul de zone](clasa-12/02-lee-fill/fill-numarul-de-zone.cpp) | Matricea are n linii și m coloane, cu 1 pentru teren și 0 pentru apă. | O(n * m) |
| [Insule în 8 direcții](clasa-12/02-lee-fill/insule-in-8-directii.cpp) | Ca la numărarea zonelor, dar două celule de uscat (1) aparțin | O(n * m) |
| [Lee cu mai multe surse](clasa-12/02-lee-fill/lee-cu-mai-multe-surse.cpp) | Grila conține 0 (liber), 1 (zid) și 2 (sursă, de exemplu o fântână). | O(n * m) |
| [Lee — drumul minim într-o grilă](clasa-12/02-lee-fill/lee-drumul-minim.cpp) | Grila are n linii și m coloane: 0 = liber, 1 = obstacol. Ne putem | O(n * m) |
| [Lee cu reconstituirea drumului](clasa-12/02-lee-fill/lee-reconstituirea-drumului.cpp) | După ce Lee a completat matricea de distanțe, drumul se reface de la | O(n * m) pentru Lee |

### Matematică pentru programare

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Ciur cu cel mai mic divizor prim și factorizare rapidă](clasa-12/03-matematica/ciur-cel-mai-mic-divizor-prim.cpp) | O variantă a ciurului lui Eratostene: în loc să marcăm doar „compus”, | O(MAX log log MAX) pentru ciur |
| [Combinări modulo un număr prim](clasa-12/03-matematica/combinari-modulo-prim.cpp) | Calculăm C(n, k) mod P, cu P = 1 000 000 007 (prim) și n ≤ 10^6. | O(n + log P) |
| [Algoritmul lui Euclid extins](clasa-12/03-matematica/euclid-extins.cpp) | Pe lângă d = cmmdc(a, b), găsim numere întregi x și y cu | O(log min(a |
| [Exponențierea modulară](clasa-12/03-matematica/exponentiere-modulara.cpp) | Calculăm a^n mod m pentru n de până la 10^18. Folosim aceeași idee ca | O(log n) |
| [Exponențierea rapidă](clasa-12/03-matematica/exponentiere-rapida.cpp) | Calculăm a^n cu aproximativ log2(n) înmulțiri în loc de n. | O(log n) |
| [Numărul și suma divizorilor din descompunerea în factori primi](clasa-12/03-matematica/numarul-de-divizori-din-descompunere.cpp) | Dacă n = p1^e1 * p2^e2 * ... * pk^ek, un divizor alege pentru fiecare | O(sqrt(n)) |
| [Numărul multiplilor lui k dintr-un interval](clasa-12/03-matematica/numarul-multiplilor-dintr-un-interval.cpp) | Câte numere din [a, b] se divid cu k? Numerele din [1, x] divizibile | O(log min(k1 |
| [Suma unei progresii aritmetice: formulă vs. buclă](clasa-12/03-matematica/suma-progresiei-formula-vs-bucla.cpp) | Progresia are primul termen a, rația r și n termeni: a, a + r, ..., | O(1) cu formula |
| [Triunghiul lui Pascal (combinări)](clasa-12/03-matematica/triunghiul-lui-pascal.cpp) | Combinările C(i, j) — numărul de submulțimi cu j elemente ale unei | O(n^2) |

### Tehnici avansate: doi pointeri, căutare binară pe răspuns, stive monotone

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Căutare binară pe răspuns](clasa-12/04-tehnici-avansate/cautare-binara-pe-raspuns.cpp) | Avem n capitole cu a[i] pagini, în ordine, și k corectori. Fiecare | O(n * log(suma)) |
| [Doi pointeri — perechi cu suma x într-un vector sortat](clasa-12/04-tehnici-avansate/doi-pointeri-perechi-suma-x.cpp) | Vectorul are n valori distincte, în ordine strict crescătoare. Vrem | O(n) |
| [Element majoritar (Boyer-Moore)](clasa-12/04-tehnici-avansate/element-majoritar-boyer-moore.cpp) | Elementul majoritar apare de mai mult de n / 2 ori. Algoritmul de | O(n) timp |
| [Fereastra glisantă — cea mai lungă secvență cu suma ≤ S](clasa-12/04-tehnici-avansate/fereastra-glisanta-suma-cel-mult-s.cpp) | Toate numerele sunt strict pozitive. Ținem o fereastră [st, dr] și | O(n) |
| [Stiva monotonă — următorul element mai mare](clasa-12/04-tehnici-avansate/stiva-monotona-urmatorul-mai-mare.cpp) | Pentru fiecare a[i] căutăm prima valoare strict mai mare aflată în | O(n) |
| [Generarea submulțimilor cu măști de biți](clasa-12/04-tehnici-avansate/submultimi-cu-masti-de-biti.cpp) | O submulțime a lui {a[0], ..., a[n-1]} se poate codifica printr-un | O(2^n * n) |
| [Sume parțiale pe matrice](clasa-12/04-tehnici-avansate/sume-partiale-pe-matrice.cpp) | s[i][j] = suma elementelor din dreptunghiul cu colțurile (1, 1) și | O(n * m) pentru precalculare |

### Structuri de date și STL

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [deque — minimul pe ferestre de lungime k](clasa-12/05-structuri-de-date/deque-minimul-pe-ferestre.cpp) | Pentru fiecare secvență de k elemente consecutive vrem minimul. | O(n) |
| [queue — eliminarea din cerc](clasa-12/05-structuri-de-date/eliminare-in-cerc-cu-queue.cpp) | n copii, numerotați de la 1 la n, stau în cerc. Se numără din k în k, | O(n * k) |
| [pair — reuniunea intervalelor](clasa-12/05-structuri-de-date/pair-reuniunea-intervalelor.cpp) | pair<int, int> grupează două valori (first, second) și se compară | O(n log n) |
| [stack — verificarea parantezelor](clasa-12/05-structuri-de-date/paranteze-cu-stack.cpp) | Un șir cu paranteze (), [] și {} este corect dacă fiecare paranteză | O(n) |
| [priority_queue — cele mai mari k valori](clasa-12/05-structuri-de-date/priority-queue-cele-mai-mari-k.cpp) | priority_queue este un heap: top() dă elementul „cel mai important”, | O(n log k) |
| [set și map — frecvența cuvintelor](clasa-12/05-structuri-de-date/set-si-map-frecventa-cuvintelor.cpp) | Citim cuvinte (litere mici) până la sfârșitul datelor. Un set<string> | O(n log n) comparații de cuvinte |
| [Sortare cu comparator](clasa-12/05-structuri-de-date/sort-cu-comparator.cpp) | sort(început, sfârșit, cmp) ordonează după regula noastră: cmp(x, y) | O(n log n) |
| [Păduri de mulțimi disjuncte (union-find)](clasa-12/05-structuri-de-date/union-find.cpp) | Avem n elemente, fiecare inițial în propria mulțime. Operația 1 x y | O((n + m) * α(n)) |
| [Containerul vector din STL](clasa-12/05-structuri-de-date/vector-operatii-stl.cpp) | vector<int> este un tablou care își gestionează singur memoria: | O(n log n) |

### Recapitulare pentru bacalaureat

| Algoritm | Ce face | Complexitate |
|---|---|---|
| [Fișier — cel mai mare și cel mai mic număr format din cifre date](clasa-12/06-bacalaureat/fisier-cel-mai-mare-si-cel-mai-mic-numar-din-cifre.cpp) | Cerința (tip subiectul III.3): fișierul date.in conține cel mult 10^6 | O(n) timp |
| [Fișier — perechi de numere cu aceeași sumă a cifrelor](clasa-12/06-bacalaureat/fisier-perechi-aceeasi-suma-cifrelor.cpp) | Cerința (tip subiectul III.3): fișierul date.in conține pe prima | O(n * 9 + 82) timp |
| [Fișier — cea mai lungă secvență de termeni cu aceeași paritate](clasa-12/06-bacalaureat/fisier-secventa-aceeasi-paritate.cpp) | Cerința (tip subiectul III.3): fișierul date.in conține un șir de cel | O(n) timp |
| [Fișier — valorile comune a două șiruri ordonate](clasa-12/06-bacalaureat/fisier-valori-comune-siruri-sortate.cpp) | Cerința (tip subiectul III.3): fișierul date.in conține pe prima | O(n + m) |
| [Fișier — valorile care apar o singură dată](clasa-12/06-bacalaureat/fisier-valori-unice.cpp) | Cerința (tip subiectul III.3): fișierul date.in conține cel mult 10^6 | O(n + 1000) timp |
| [Matrice — contururi concentrice](clasa-12/06-bacalaureat/matrice-contururi-concentrice.cpp) | Cerința (tip subiectul III.2): se citește n (2 ≤ n ≤ 20). Construiți | O(n^2) |
| [Subprogram — numărul format din cifrele pare](clasa-12/06-bacalaureat/subprogram-cifre-pare.cpp) | Cerința (tip subiectul III.1): subprogramul pare are un parametru n | O(numărul de cifre ale lui n) |
| [Subprogram — câte numere dintr-un interval au un număr impar de divizori](clasa-12/06-bacalaureat/subprogram-divizori-impari-interval.cpp) | Cerința (tip subiectul III.1): subprogramul impare are parametrii a și | O(1) |
| [Subprogram — eliminarea elementelor cu k cifre dintr-un tablou](clasa-12/06-bacalaureat/subprogram-eliminare-din-tablou.cpp) | Cerința (tip subiectul III.1): subprogramul elimina are parametrii v | O(n * c) |
| [Text — inversarea cuvintelor de lungime pară](clasa-12/06-bacalaureat/text-cuvinte-pare-inversate.cpp) | Cerința (tip subiectul III.2): se citește un text de cel mult 100 de | O(L) |

---

Copyright © 2023–2026 Andras Bogdan Andrei. Toate drepturile rezervate.
Poți citi și rula algoritmii pentru învățare; copierea, republicarea sau redistribuirea lor fără acord scris
sunt interzise. Vezi [LICENSE](LICENSE).
