"""Generează README.md cu cuprinsul tuturor algoritmilor, din antetele fișierelor .cpp.

Utilizare: python scripts/genereaza_readme.py

Toate numerele din README (algoritmi, capitole, programe pe clasă) sunt calculate
din fișierele reale. Funcția colectie() și listele FAQ și POPULARE pot fi importate
și de alte scripturi (de exemplu cel care construiește pagina proiectului).
"""

import re
import sys
from pathlib import Path
from html import escape
from urllib.parse import quote

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verifica import citeste_antet, extrage_campuri  # noqa: E402
import genereaza_imagini as imagini  # noqa: E402

RADACINA = Path(__file__).resolve().parent.parent
NUME_CLASA = {"09": "a IX-a", "10": "a X-a", "11": "a XI-a", "12": "a XII-a"}

DEPOZIT = "AndrasBogdanAndrei/Algoritmi-Elementari-CodePrepper"
URL_DEPOZIT = f"https://github.com/{DEPOZIT}"
URL_PAGINA = "https://andrasbogdanandrei.github.io/Algoritmi-Elementari-CodePrepper/"
URL_CODEPREPPER = "https://github.com/AndrasBogdanAndrei/CodePrepper"
URL_CODEPREPPER_PAGINA = "https://andrasbogdanandrei.github.io/CodePrepper/"
AUTOR = "Andras Bogdan Andrei"

# Algoritmii pe care elevii îi caută cel mai des, cu denumirea uzuală (și cea în engleză).
# Fiecare cale trebuie să existe; generatorul se oprește cu eroare dacă un fișier lipsește.
POPULARE = [
    ("Sortarea prin metoda bulelor (bubble sort)", "clasa-09/06-sortare-cautare/sortare-prin-metoda-bulelor.cpp"),
    ("Sortarea prin selecție (selection sort)", "clasa-09/06-sortare-cautare/sortare-prin-selectie.cpp"),
    ("Sortarea prin inserție (insertion sort)", "clasa-09/06-sortare-cautare/sortare-prin-insertie.cpp"),
    ("Căutarea binară", "clasa-09/06-sortare-cautare/cautare-binara.cpp"),
    ("Algoritmul lui Euclid (cmmdc)", "clasa-09/02-divizibilitate/cmmdc-prin-impartiri.cpp"),
    ("Ciurul lui Eratostene", "clasa-09/07-tehnici-vectori/ciurul-lui-eratostene.cpp"),
    ("Sortarea rapidă (quicksort)", "clasa-10/06-divide-et-impera/sortare-rapida.cpp"),
    ("Sortarea prin interclasare (merge sort)", "clasa-10/06-divide-et-impera/sortare-prin-interclasare.cpp"),
    ("Turnurile din Hanoi", "clasa-10/06-divide-et-impera/turnurile-din-hanoi.cpp"),
    ("Permutări prin backtracking", "clasa-11/01-backtracking/permutari.cpp"),
    ("Problema celor n dame", "clasa-11/01-backtracking/n-dame.cpp"),
    ("Problema rucsacului (programare dinamică)", "clasa-11/03-programare-dinamica/rucsacul-discret.cpp"),
    ("Cel mai lung subșir comun", "clasa-11/03-programare-dinamica/cel-mai-lung-subsir-comun.cpp"),
    ("Parcurgerea în lățime (BFS)", "clasa-11/05-grafuri-neorientate/parcurgerea-in-latime-bfs.cpp"),
    ("Algoritmul lui Dijkstra", "clasa-11/06-grafuri-orientate/dijkstra.cpp"),
    ("Algoritmul lui Lee", "clasa-12/02-lee-fill/lee-drumul-minim.cpp"),
]

# Întrebări frecvente. Răspunsurile folosesc doar `cod` și [linkuri](url) absolute,
# ca să poată fi afișate identic și pe pagina proiectului. {programe} se înlocuiește cu
# numărul real de programe (cu acordul corect: „266 de programe”).
FAQ = [
    (
        "Pentru cine este colecția de algoritmi?",
        "Pentru elevii de liceu de la profilul matematică-informatică (clasele a IX-a – a XII-a), "
        "pentru cei care se pregătesc de bacalaureatul la informatică și pentru profesorii care caută "
        "exemple scurte și explicate. Programele urmează ordinea din programa școlară, de la cifrele "
        "unui număr până la grafuri și arbori.",
    ),
    (
        "Cum compilez și rulez un algoritm în C++?",
        "Cu g++: `g++ -std=c++17 -O2 fisier.cpp -o program`, apoi `./program` (pe Windows, `program.exe`). "
        "Introdu datele din exemplul scris în antetul fișierului. Merge la fel în Code::Blocks sau în orice "
        "editor care folosește un compilator C++17.",
    ),
    (
        "De unde știu că programele sunt corecte?",
        "Fiecare fișier are în antet cel puțin un exemplu de intrare și ieșire. Scriptul `scripts/verifica.py` "
        "compilează toate cele {programe} cu `-Wall -Wextra`, le rulează pe exemple și compară "
        "rezultatul. Verificarea rulează automat pe Windows, Linux și macOS la fiecare modificare.",
    ),
    (
        "Ce găsesc pentru bacalaureatul la informatică?",
        "Temele din programă: cifrele unui număr, divizibilitate, vectori, sortări (metoda bulelor, selecție, "
        "inserție, numărare), căutare binară, fișiere text, subprograme, matrice, șiruri de caractere, "
        "recursivitate și backtracking, plus capitolul „Recapitulare pentru bacalaureat”, cu probleme de "
        "tipul celor de la examen.",
    ),
    (
        "Ce algoritmi avansați conține colecția?",
        "Programare dinamică (rucsac, cel mai lung subșir comun, distanța de editare), grafuri (BFS, DFS, "
        "Dijkstra, Roy-Floyd, sortare topologică), arbori, liste, stive și cozi, numere mari, algoritmul "
        "lui Lee, fill și tehnici precum doi pointeri sau căutarea binară pe răspuns.",
    ),
    (
        "Pot copia codul în alt proiect sau pe alt site?",
        "Poți citi, compila și rula programele gratuit, pentru învățare, iar profesorii le pot prezenta la "
        "clasă cu menționarea sursei. Copierea, republicarea, publicarea unor variante modificate sau "
        f"folosirea comercială cer acordul scris al autorului. Detaliile sunt în [LICENSE]({URL_DEPOZIT}/blob/main/LICENSE).",
    ),
    (
        "Ce este CodePrepper?",
        f"[CodePrepper]({URL_CODEPREPPER}) este aplicația gratuită pentru Windows, macOS și Linux care include "
        "această colecție: lecții, algoritmi animați pas cu pas, probleme C++ cu evaluare automată și teste "
        "grilă în stilul bacalaureatului.",
    ),
    (
        "Am găsit o greșeală. Cum o raportez?",
        f"Deschide un [issue]({URL_DEPOZIT}/issues/new/choose) cu șablonul „Greșeală într-un algoritm” și scrie "
        "fișierul, datele de intrare, rezultatul obținut și cel așteptat. Pașii sunt descriși în "
        f"[CONTRIBUTING.md]({URL_DEPOZIT}/blob/main/CONTRIBUTING.md).",
    ),
]


def cu_de(n, singular, plural):
    """Acordul numeralului în română: 1 algoritm, 15 algoritmi, 266 de algoritmi."""
    if n == 1:
        return f"1 {singular}"
    rest = n % 100
    if rest == 0 or rest >= 20:
        return f"{n} de {plural}"
    return f"{n} {plural}"


def descriere_completa(linii):
    """Câmpul Descriere, cu tot cu rândurile de continuare (indentate)."""
    bucati = []
    in_descriere = False
    for linie in linii:
        if linie.startswith("Descriere:"):
            in_descriere = True
            bucati.append(linie[len("Descriere:"):].strip())
        elif in_descriere:
            if linie.strip() and linie[:1].isspace():
                bucati.append(linie.strip())
            else:
                break
    return " ".join(bucati)


def scurteaza(text, limita=160):
    if len(text) <= limita:
        return text
    taiat = text[:limita]
    punct = taiat.rfind(". ")
    if punct >= 60:
        return taiat[: punct + 1]
    return taiat.rsplit(" ", 1)[0].rstrip(",;:") + "…"


def complexitate_scurta(text):
    """Partea de dinaintea primei virgule din afara parantezelor: „O(log(min(a, b)))” rămâne întreg."""
    nivel = 0
    for i, ch in enumerate(text):
        if ch in "([":
            nivel += 1
        elif ch in ")]":
            nivel -= 1
        elif ch == "," and nivel == 0:
            return text[:i].strip()
    return text.strip()


def ancora(titlu, folosite):
    """Ancora pe care GitHub o generează pentru un titlu Markdown."""
    baza = re.sub(r"[^\w\- ]", "", titlu.strip().lower()).replace(" ", "-")
    n = folosite.get(baza, 0)
    folosite[baza] = n + 1
    return baza if n == 0 else f"{baza}-{n}"


def colectie():
    """Lista claselor, fiecare cu capitolele și algoritmii ei, citită din antetele fișierelor."""
    clase = []
    for dir_clasa in sorted(RADACINA.glob("clasa-*")):
        nr = dir_clasa.name.split("-")[1]
        clasa = {
            "nr": nr,
            "titlu": f"Clasa {NUME_CLASA.get(nr, nr)}",
            "folder": dir_clasa.name,
            "capitole": [],
        }
        for dir_cap in sorted(p for p in dir_clasa.iterdir() if p.is_dir()):
            fisiere = sorted(dir_cap.glob("*.cpp"))
            if not fisiere:
                continue
            capitol = {"titlu": None, "folder": dir_cap.relative_to(RADACINA).as_posix(), "algoritmi": []}
            for f in fisiere:
                linii = citeste_antet(f.read_text(encoding="utf-8")) or []
                campuri = extrage_campuri(linii)
                capitol["titlu"] = capitol["titlu"] or campuri.get("Capitol", dir_cap.name)
                capitol["algoritmi"].append(
                    {
                        "titlu": campuri.get("Titlu", f.stem),
                        "cale": f.relative_to(RADACINA).as_posix(),
                        "descriere": descriere_completa(linii) or campuri.get("Descriere", ""),
                        "complexitate": complexitate_scurta(campuri.get("Complexitate", "")),
                    }
                )
            clasa["capitole"].append(capitol)
        clasa["total"] = sum(len(c["algoritmi"]) for c in clasa["capitole"])
        clase.append(clasa)
    return clase


def faq_completat(total):
    return [(q, r.replace("{programe}", cu_de(total, "program", "programe"))) for q, r in FAQ]


def poza(baza, alt, latime=None):
    """<picture> cu varianta dark și light a unei imagini din .github/assets (baza fără „-light.svg”)."""
    w = f' width="{latime}"' if latime else ' width="100%"'
    return (
        f'<picture><source media="(prefers-color-scheme: dark)" srcset="{baza}-dark.svg">'
        f'<img src="{baza}-light.svg" alt="{alt}"{w}></picture>'
    )


SEPARATOR = '\n<p align="center">' + poza(".github/assets/separator", "") + "</p>\n"


def icoana(folder, titlu, marime=40):
    return (
        f'<img src="{imagini.cale_pictograma(folder)}" width="{marime}" height="{marime}" '
        f'align="absmiddle" alt="{"" if marime < 30 else "Animație: " + escape(titlu)}">'
    )


def celula(text):
    return re.sub(r"\s+", " ", text).replace("|", "\\|")


def construieste(clase):
    total = sum(c["total"] for c in clase)
    nr_capitole = sum(len(c["capitole"]) for c in clase)
    algoritmi = {a["cale"]: a for c in clase for cap in c["capitole"] for a in cap["algoritmi"]}
    for _, cale in POPULARE:
        if cale not in algoritmi:
            sys.exit(f"POPULARE: fișierul {cale} nu există.")

    folosite = {}
    for titlu in ("Cuprins", "Cum folosești algoritmii", "Cei mai căutați algoritmi"):
        ancora(titlu, folosite)

    cuprins = [
        "- [Cum folosești algoritmii](#cum-folosești-algoritmii)",
        "- [Cei mai căutați algoritmi](#cei-mai-căutați-algoritmi)",
    ]
    sectiuni = []
    for clasa in clase:
        a_clasa = ancora(clasa["titlu"], folosite)
        cuprins.append(
            f"- **[{clasa['titlu']}](#{a_clasa})** — {cu_de(clasa['total'], 'algoritm', 'algoritmi')}, "
            f"{cu_de(len(clasa['capitole']), 'capitol', 'capitole')}"
        )
        sectiuni.append(
            SEPARATOR
            + f"\n## {clasa['titlu']}\n\n"
            + poza(f".github/assets/clasa-{clasa['nr']}", f"{clasa['titlu']}: animație și lista capitolelor")
            + "\n\n"
            f"{cu_de(clasa['total'], 'algoritm', 'algoritmi')} în "
            f"{cu_de(len(clasa['capitole']), 'capitol', 'capitole')}. "
            f"Folder: [`{clasa['folder']}`]({clasa['folder']}).\n"
        )
        for cap in clasa["capitole"]:
            a_cap = ancora(cap["titlu"], folosite)
            n = len(cap["algoritmi"])
            cuprins.append(f"  - [{cap['titlu']}](#{a_cap}) ({n})")
            randuri = [
                f"| [{celula(a['titlu'])}]({quote(a['cale'])}) | {celula(scurteaza(a['descriere']))} "
                f"| {celula(a['complexitate'])} |"
                for a in cap["algoritmi"]
            ]
            sectiuni.append(
                f"\n### {cap['titlu']}\n\n"
                f"{icoana(cap['folder'], cap['titlu'])} &nbsp; "
                f"**{cu_de(n, 'program', 'programe')}** în [`{cap['folder']}`]({quote(cap['folder'])}).\n\n"
                "| Algoritm | Ce face | Complexitate |\n|---|---|---|\n" + "\n".join(randuri) + "\n"
            )
    cuprins.append("- [Întrebări frecvente](#întrebări-frecvente)")
    cuprins.append("- [Contribuții, suport și licență](#contribuții-suport-și-licență)")

    populare = "\n".join(
        f"- {icoana(cale.rsplit('/', 1)[0], eticheta, 22)} [{eticheta}]({quote(cale)}) — "
        f"{algoritmi[cale]['complexitate']}"
        for eticheta, cale in POPULARE
    )
    faq = "\n".join(f"\n### {q}\n\n{r}" for q, r in faq_completat(total))
    badge_total = quote(f"programe-{total}-2ea44f", safe="-")

    banner = poza(".github/assets/banner", f"Algoritmi elementari în C++: {cu_de(total, 'program', 'programe')} rezolvate")
    return f"""<p align="center"><a href="{URL_PAGINA}">{banner}</a></p>

# Algoritmi elementari în C++ — probleme rezolvate pentru liceu și bacalaureat

**{cu_de(total, 'algoritm', 'algoritmi')} elementari în C++, explicați și verificați**, pentru informatica de liceu
(clasele IX–XII) și bacalaureat: cifre, vectori, sortări, backtracking, greedy, programare dinamică, grafuri și altele.

[![Verificare algoritmi]({URL_DEPOZIT}/actions/workflows/verificare.yml/badge.svg)]({URL_DEPOZIT}/actions/workflows/verificare.yml)
[![Licență: toate drepturile rezervate](https://img.shields.io/badge/licen%C8%9B%C4%83-toate_drepturile_rezervate-blue)](LICENSE)
[![Programe](https://img.shields.io/badge/{badge_total})](#cuprins)
[![C++17](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=cplusplus&logoColor=white)](#cum-folosești-algoritmii)
[![Stele pe GitHub](https://img.shields.io/github/stars/{DEPOZIT}?style=flat&logo=github&label=stele)]({URL_DEPOZIT}/stargazers)

**[Pagina proiectului]({URL_PAGINA})** · **[Aplicația CodePrepper]({URL_CODEPREPPER})** ·
[Cuprins](#cuprins) · [Cum folosești](#cum-folosești-algoritmii) · [Întrebări frecvente](#întrebări-frecvente)

Colecția este organizată după programa școlară de la profilul matematică-informatică, în
{cu_de(nr_capitole, 'capitol', 'capitole')}. Fiecare program are la început o explicație a ideii, complexitatea și cel
puțin un exemplu de intrare și ieșire. Toate programele sunt verificate automat: se compilează fără avertismente și dau
exact rezultatul din exemplu, pe Windows, Linux și macOS.

> Vrei să vezi algoritmii animați pas cu pas, să rezolvi probleme cu evaluare automată și să dai teste grilă?
> Încearcă aplicația gratuită **[CodePrepper]({URL_CODEPREPPER})** ([pagina aplicației]({URL_CODEPREPPER_PAGINA})).

{SEPARATOR}
## Cuprins

{chr(10).join(cuprins)}
{SEPARATOR}
## Cum folosești algoritmii

1. Alege clasa și capitolul din [cuprins](#cuprins) și deschide fișierul `.cpp` care te interesează.
2. Citește antetul: ideea algoritmului, complexitatea și exemplele de intrare și ieșire.
3. Compilează și rulează programul, apoi introdu datele din exemplu:

```sh
g++ -std=c++17 -O2 -Wall fisier.cpp -o program
./program          # pe Windows: program.exe
```

În Code::Blocks sau în alt editor, creează un proiect nou, lipește codul și alege standardul C++17. Programele de la
capitolele „Fișiere text” și „Recapitulare pentru bacalaureat” care lucrează cu fișiere citesc din
`date.in` (unele scriu în `date.out`), în folderul din care rulezi programul.

Verificarea întregii colecții (are nevoie de Python 3 și de g++ sau clang++):

```sh
python scripts/verifica.py              # toate cele {cu_de(total, 'program', 'programe')}
python scripts/verifica.py clasa-11     # doar o clasă sau un capitol
```
{SEPARATOR}
## Cei mai căutați algoritmi

{populare}
{"".join(sectiuni)}{SEPARATOR}
## Întrebări frecvente
{faq}
{SEPARATOR}
## Contribuții, suport și licență

- Ai găsit o greșeală sau vrei un algoritm nou? Citește [CONTRIBUTING.md](CONTRIBUTING.md) și deschide un
  [issue]({URL_DEPOZIT}/issues/new/choose).
- Întrebări despre un algoritm: [SUPPORT.md](SUPPORT.md). Probleme de securitate: [SECURITY.md](SECURITY.md).
- Reguli de comportament: [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

---

Copyright © 2023–2026 {AUTOR}. Toate drepturile rezervate.
Poți citi și rula algoritmii pentru învățare; copierea, republicarea sau redistribuirea lor fără acord scris
sunt interzise. Vezi [LICENSE](LICENSE).
"""


def main():
    clase = colectie()
    imagini.genereaza(clase)
    text = construieste(clase)
    (RADACINA / "README.md").write_text(text, encoding="utf-8", newline="\n")
    total = sum(c["total"] for c in clase)
    capitole = sum(len(c["capitole"]) for c in clase)
    print(f"README.md generat: {total} algoritmi, {capitole} capitole.")


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    main()
