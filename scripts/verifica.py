"""Compilează fiecare algoritm și îl rulează pe exemplele din antetul lui.

Utilizare:
    python scripts/verifica.py              # toate fișierele
    python scripts/verifica.py clasa-09     # doar un folder
Variabila de mediu CXX alege compilatorul (implicit g++).
"""

import os
import re
import shutil
import subprocess
import sys
import tempfile
from pathlib import Path

RADACINA = Path(__file__).resolve().parent.parent
CXX = os.environ.get("CXX", "g++")
FLAGURI = ["-std=c++17", "-O2", "-Wall", "-Wextra"]
CAMPURI = ["Titlu", "Clasa", "Capitol", "Descriere", "Complexitate"]
SUFIX_EXE = ".exe" if os.name == "nt" else ""


def citeste_antet(text):
    m = re.match(r"\s*/\*(.*?)\*/", text, re.S)
    if not m:
        return None
    linii = []
    for linie in m.group(1).splitlines():
        linie = re.sub(r"^\s*\* ?", "", linie.rstrip())
        linii.append(linie)
    return linii


def extrage_campuri(linii):
    campuri = {}
    for linie in linii:
        m = re.match(r"^(\w[\w ]*?):\s*(.+)$", linie)
        if m and m.group(1) in CAMPURI and m.group(1) not in campuri:
            campuri[m.group(1)] = m.group(2).strip()
    return campuri


def extrage_exemple(linii):
    exemple = []
    stare = None
    intrare, iesire = [], []

    def inchide():
        if stare is not None:
            exemple.append(("\n".join(intrare).strip("\n"), "\n".join(iesire).strip("\n")))

    for linie in linii:
        m_in = re.match(r"^Intrare:\s*(.*)$", linie)
        m_out = re.match(r"^Ieșire:\s*(.*)$", linie)
        if m_in:
            inchide()
            stare, intrare, iesire = "in", [], []
            if m_in.group(1):
                intrare.append(m_in.group(1))
        elif m_out and stare == "in":
            stare = "out"
            if m_out.group(1):
                iesire.append(m_out.group(1))
        elif re.match(r"^(Exemplu|Observații|Explicație)\b", linie):
            inchide()
            stare = None
        elif stare == "in":
            intrare.append(linie)
        elif stare == "out":
            iesire.append(linie)
    inchide()
    return exemple


def ruleaza(exe, intrare, sursa, director):
    fisier_in = "date.in" if '"date.in"' in sursa else None
    fisier_out = "date.out" if '"date.out"' in sursa else None
    if fisier_in:
        (director / fisier_in).write_text(intrare + "\n", encoding="utf-8")
    rez = subprocess.run(
        [str(exe)],
        input=None if fisier_in else (intrare + "\n").encode(),
        stdin=subprocess.DEVNULL if fisier_in else None,
        capture_output=True,
        cwd=director,
        timeout=5,
    )
    if fisier_out:
        cale = director / fisier_out
        return rez.returncode, cale.read_text(encoding="utf-8") if cale.exists() else ""
    return rez.returncode, rez.stdout.decode(errors="replace")


def verifica_fisier(cale, director):
    sursa = cale.read_text(encoding="utf-8")
    nume = cale.relative_to(RADACINA).as_posix()
    erori = []
    linii = citeste_antet(sursa)
    if linii is None:
        return [f"{nume}: lipsește comentariul de antet /* ... */"]
    campuri = extrage_campuri(linii)
    for c in CAMPURI:
        if c not in campuri:
            erori.append(f"{nume}: lipsește câmpul „{c}:” din antet")
    if "bits/stdc++.h" in sursa:
        erori.append(f"{nume}: nu folosi <bits/stdc++.h> (nu există pe macOS)")
    exemple = extrage_exemple(linii)
    if not exemple:
        erori.append(f"{nume}: niciun exemplu „Intrare:/Ieșire:” în antet")

    exe = director / ("prog" + SUFIX_EXE)
    if exe.exists():
        exe.unlink()
    comp = subprocess.run([CXX, *FLAGURI, str(cale), "-o", str(exe)], capture_output=True, text=True, errors="replace")
    if comp.returncode != 0:
        return erori + [f"{nume}: eroare de compilare\n{comp.stderr.strip()}"]
    if "warning:" in comp.stderr:
        erori.append(f"{nume}: avertismente la compilare\n{comp.stderr.strip()}")

    for i, (intrare, asteptat) in enumerate(exemple, 1):
        try:
            cod, obtinut = ruleaza(exe, intrare, sursa, director)
        except subprocess.TimeoutExpired:
            erori.append(f"{nume}: exemplul {i} a depășit 5 secunde")
            continue
        if cod != 0:
            erori.append(f"{nume}: exemplul {i} s-a terminat cu codul {cod}")
        elif obtinut.split() != asteptat.split():
            erori.append(f"{nume}: exemplul {i} greșit\n  așteptat: {asteptat!r}\n  obținut:  {obtinut.strip()!r}")
    return erori


def main():
    filtru = sys.argv[1] if len(sys.argv) > 1 else ""
    fisiere = sorted(p for p in RADACINA.glob("clasa-*/**/*.cpp") if filtru in p.relative_to(RADACINA).as_posix())
    if shutil.which(CXX) is None:
        sys.exit(f"Compilatorul {CXX} nu a fost găsit.")
    toate = []
    with tempfile.TemporaryDirectory() as tmp:
        for cale in fisiere:
            erori = verifica_fisier(cale, Path(tmp))
            toate.extend(erori)
            print(("EȘUAT " if erori else "OK    ") + cale.relative_to(RADACINA).as_posix())
    print(f"\n{len(fisiere)} fișiere verificate, {len(toate)} probleme.")
    for e in toate:
        print("\n" + e)
    sys.exit(1 if toate else 0)


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    main()
