"""Generează README.md cu cuprinsul tuturor algoritmilor, din antetele fișierelor .cpp.

Utilizare: python scripts/genereaza_readme.py
"""

import re
import sys
from pathlib import Path
from urllib.parse import quote

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verifica import citeste_antet, extrage_campuri  # noqa: E402

RADACINA = Path(__file__).resolve().parent.parent
NUME_CLASA = {"09": "a IX-a", "10": "a X-a", "11": "a XI-a", "12": "a XII-a"}

INTRO = """# Algoritmi elementari în C++

Colecție completă de algoritmi pentru informatica de liceu (clasele IX–XII, profil matematică-informatică),
scrisă în C++ și organizată după programa școlară. Fiecare program are la început o explicație a ideii,
complexitatea și un exemplu de intrare și ieșire, și este verificat automat: se compilează și dă rezultatul
din exemplu.

**{total} algoritmi** în {capitole} capitole.

> Vrei să-i vezi animați pas cu pas, să rezolvi probleme cu evaluare automată și să dai teste grilă?
> Încearcă aplicația [CodePrepper](https://github.com/AndrasBogdanAndrei/CodePrepper).

## Cum folosești algoritmii

1. Deschide fișierul `.cpp` care te interesează și citește explicația din antet.
2. Compilează-l (Code::Blocks, sau din terminal: `g++ -std=c++17 -O2 fisier.cpp -o program`).
3. Rulează-l și introdu datele din exemplul din antet.

Verificarea automată a întregii colecții: `python scripts/verifica.py` (are nevoie de g++ sau clang++).

## Cuprins

{cuprins}
"""

FINAL = """
---

Copyright © 2023–2026 Andras Bogdan Andrei. Toate drepturile rezervate.
Poți citi și rula algoritmii pentru învățare; copierea, republicarea sau redistribuirea lor fără acord scris
sunt interzise. Vezi [LICENSE](LICENSE).
"""


def main():
    sectiuni = []
    cuprins = []
    total = 0
    capitole = 0
    for dir_clasa in sorted(RADACINA.glob("clasa-*")):
        nr = dir_clasa.name.split("-")[1]
        titlu_clasa = f"Clasa {NUME_CLASA.get(nr, nr)}"
        cuprins.append(f"- [{titlu_clasa}](#{titlu_clasa.lower().replace(' ', '-')})")
        sectiuni.append(f"\n## {titlu_clasa}\n")
        for dir_cap in sorted(p for p in dir_clasa.iterdir() if p.is_dir()):
            fisiere = sorted(dir_cap.glob("*.cpp"))
            if not fisiere:
                continue
            randuri = []
            titlu_cap = None
            for f in fisiere:
                campuri = extrage_campuri(citeste_antet(f.read_text(encoding="utf-8")) or [])
                titlu_cap = titlu_cap or campuri.get("Capitol", dir_cap.name)
                cale = quote(f.relative_to(RADACINA).as_posix())
                descriere = re.sub(r"\s+", " ", campuri.get("Descriere", "")).replace("|", "\\|")
                if len(descriere) > 140:
                    descriere = descriere[:137].rsplit(" ", 1)[0] + "…"
                complexitate = campuri.get("Complexitate", "").split(",")[0].replace("|", "\\|")
                randuri.append(f"| [{campuri.get('Titlu', f.stem)}]({cale}) | {descriere} | {complexitate} |")
            total += len(randuri)
            capitole += 1
            sectiuni.append(f"\n### {titlu_cap}\n\n| Algoritm | Ce face | Complexitate |\n|---|---|---|\n" + "\n".join(randuri) + "\n")
    text = INTRO.format(total=total, capitole=capitole, cuprins="\n".join(cuprins)) + "".join(sectiuni) + FINAL
    (RADACINA / "README.md").write_text(text, encoding="utf-8")
    print(f"README.md generat: {total} algoritmi, {capitole} capitole.")


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    main()
