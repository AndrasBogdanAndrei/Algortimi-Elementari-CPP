"""Generează imaginile SVG animate din .github/assets/: bannerul, separatorul, cardurile claselor
(variante light și dark) și câte o pictogramă animată pentru fiecare capitol.

Animațiile sunt doar CSS @keyframes în interiorul SVG-ului (GitHub le afișează și în <img>), fără
JavaScript, fonturi sau imagini externe. Toate se opresc la prefers-reduced-motion: reduce și
rămân atunci într-o stare statică ușor de citit.

Utilizare: python scripts/genereaza_imagini.py  (se rulează automat și din genereaza_readme.py)
"""

import sys
from html import escape
from pathlib import Path

RADACINA = Path(__file__).resolve().parent.parent
ASSETS = RADACINA / ".github" / "assets"
CAPITOLE = ASSETS / "capitole"

FONT = "system-ui,-apple-system,'Segoe UI',Roboto,Helvetica,Arial,sans-serif"
MONO = "Consolas,Menlo,'DejaVu Sans Mono','Liberation Mono',monospace"
OPRIRE = "text{font-variant-ligatures:none}@media (prefers-reduced-motion:reduce){*{animation:none!important}}"
ROMAN = {"09": "IX", "10": "X", "11": "XI", "12": "XII"}

TEME = {
    "light": {
        "card": "#ffffff", "text": "#1b1d2e", "slab": "#555a75", "bordura": "#dde0ef", "pal": "#e8eafc",
        "brand": "#4f55e3", "accent": "#c98a12", "g1": "#4f6fe6", "g2": "#6a42d0", "panou": "#1a1c3a",
    },
    "dark": {
        "card": "#161b22", "text": "#e6edf3", "slab": "#9ea7b3", "bordura": "#30363d", "pal": "#232a45",
        "brand": "#7a7ff5", "accent": "#f5b83d", "g1": "#3346b8", "g2": "#4e2ca0", "panou": "#0b0d1c",
    },
}

# Numele scurte ale capitolelor, pentru cardurile claselor.
SCURT = {
    "cifre": "Cifre", "divizibilitate": "Divizibilitate", "secvente": "Secvențe", "baze": "Baze de numerație",
    "vectori": "Vectori", "sortare-cautare": "Sortare și căutare", "tehnici-vectori": "Frecvență și ciur",
    "fisiere": "Fișiere", "subprograme": "Subprograme", "matrice": "Matrice", "siruri-caractere": "Șiruri",
    "structuri": "Struct", "recursivitate": "Recursivitate", "divide-et-impera": "Divide et impera",
    "backtracking": "Backtracking", "greedy": "Greedy", "programare-dinamica": "Programare dinamică",
    "liste-stive-cozi": "Liste, stive, cozi", "grafuri-neorientate": "Grafuri neorientate",
    "grafuri-orientate": "Grafuri orientate", "arbori": "Arbori", "numere-mari": "Numere mari",
    "lee-fill": "Lee și fill", "matematica": "Matematică", "tehnici-avansate": "Tehnici avansate",
    "structuri-de-date": "Structuri de date", "bacalaureat": "Bacalaureat",
}


def kf(nume, cadre):
    """@keyframes din perechi (procent, declarații); procentele sunt făcute strict crescătoare."""
    pasi, ultim = [], -1.0
    for p, d in cadre:
        p = min(100.0, max(p, ultim + 0.01))
        ultim = p
        pasi.append(f"{p:.2f}%{{{d}}}")
    return f"@keyframes {nume}{{{''.join(pasi)}}}"


def svg(w, h, css, corp, titlu):
    return (
        f'<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" viewBox="0 0 {w} {h}" '
        f'role="img" aria-label="{escape(titlu)}"><title>{escape(titlu)}</title>'
        f"<style>{css}{OPRIRE}</style>{corp}</svg>\n"
    )


def scurt(folder):
    cheie = folder.split("/")[-1].split("-", 1)[1]
    return SCURT.get(cheie, cheie.replace("-", " ").capitalize())


# ---------------------------------------------------------------- bare care se sortează (bubble sort)

def bare_sortare(valori, latime, spatiu, inaltime, culoare, accent, prefix="b", text=None, pas=0.7):
    """Bare care se sortează prin metoda bulelor. Întoarce (css, corp, lățime totală)."""
    n, vmax = len(valori), max(valori)
    ordine = list(range(n))
    stari = [ordine[:]]
    for sf in range(n - 1, 0, -1):
        for i in range(sf):
            if valori[ordine[i]] > valori[ordine[i + 1]]:
                ordine[i], ordine[i + 1] = ordine[i + 1], ordine[i]
                stari.append(ordine[:])
    s = len(stari) - 1
    start, final, revenire = 1.0, 2.4, 0.8
    total = start + s * pas + final + revenire
    pct = lambda t: 100 * t / total  # noqa: E731
    px = latime + spatiu
    css, corp = [], []
    for b in range(n):
        poz = [st.index(b) for st in stari]
        cadre = [(0, poz[0]), (pct(start), poz[0])]
        for k in range(1, s + 1):
            if poz[k] != poz[k - 1]:
                t0 = start + (k - 1) * pas
                cadre += [(pct(t0 + 0.1 * pas), poz[k - 1]), (pct(t0 + 0.9 * pas), poz[k])]
        cadre += [(pct(total - revenire), poz[s]), (100, poz[0])]
        css.append(kf(f"{prefix}{b}", [(p, f"transform:translateX({x * px}px)") for p, x in cadre]))
        css.append(
            f".{prefix}{b}{{transform:translateX({poz[0] * px}px);"
            f"animation:{prefix}{b} {total:.2f}s ease-in-out infinite}}"
        )
        h = max(6, round(inaltime * valori[b] / vmax))
        eticheta = (
            f'<text x="{latime / 2}" y="{inaltime - 7}" text-anchor="middle" font-family="{MONO}" '
            f'font-size="13" font-weight="700" fill="{text}">{valori[b]}</text>'
            if text else ""
        )
        corp.append(
            f'<g class="{prefix}{b}"><rect class="{prefix}r" x="0" y="{inaltime - h}" width="{latime}" '
            f'height="{h}" rx="{min(5, latime / 4)}"/>{eticheta}</g>'
        )
    sortat = start + s * pas
    css.append(kf(f"{prefix}c", [
        (0, f"fill:{culoare}"), (pct(sortat), f"fill:{culoare}"), (pct(sortat + 0.4), f"fill:{accent}"),
        (pct(total - revenire), f"fill:{accent}"), (100, f"fill:{culoare}"),
    ]))
    css.append(f".{prefix}r{{fill:{culoare};animation:{prefix}c {total:.2f}s linear infinite}}")
    return "".join(css), "".join(corp), n * px - spatiu


# ---------------------------------------------------------------- banner

def banner(t, total, capitole):
    w, h = 1280, 320
    bcss, bcorp, bw = bare_sortare([5, 2, 8, 1, 6, 3, 7, 4], 34, 12, 150, "#ffffff", "#f5b83d", text="#3a2f8f")
    css = (
        bcss
        + kf("g1", [(0, "transform:translate(0,0)"), (50, "transform:translate(140px,40px)"), (100, "transform:translate(0,0)")])
        + kf("g2", [(0, "transform:translate(0,0)"), (50, "transform:translate(-160px,-50px)"), (100, "transform:translate(0,0)")])
        + kf("sus", [(0, "opacity:0;transform:translateY(14px)"), (100, "opacity:1;transform:none")])
        + kf("cl", [(0, "opacity:1"), (49, "opacity:1"), (50, "opacity:0"), (100, "opacity:0")])
        + kf("dr", [(0, "transform:translateX(-300px)"), (100, "transform:translateX(1580px)")])
        + ".gl1{animation:g1 14s ease-in-out infinite}.gl2{animation:g2 17s ease-in-out infinite}"
        + ".a1,.a2,.a3,.a4{animation:sus .9s ease-out both}.a2{animation-delay:.15s}.a3{animation-delay:.3s}"
        + ".a4{animation-delay:.45s}.cur{animation:cl 1.1s step-end infinite}.dr{animation:dr 7s linear infinite}"
    )
    chips, x = [], 64
    for eticheta in ("C++17", f"{capitole} de capitole", "clasele IX–XII", "verificat automat"):
        lw = round(len(eticheta) * 8.4 + 30)
        chips.append(
            f'<rect x="{x}" y="250" width="{lw}" height="34" rx="17" fill="#ffffff" fill-opacity=".16"/>'
            f'<text x="{x + lw / 2}" y="272" text-anchor="middle" font-size="15" font-weight="600" fill="#fff">{eticheta}</text>'
        )
        x += lw + 10
    px0 = 820 + (400 - bw) / 2
    corp = f"""<defs>
<linearGradient id="fg" x1="0" y1="0" x2="1" y2="1"><stop offset="0" stop-color="{t['g1']}"/><stop offset="1" stop-color="{t['g2']}"/></linearGradient>
<radialGradient id="lum"><stop offset="0" stop-color="#ffffff" stop-opacity=".32"/><stop offset="1" stop-color="#ffffff" stop-opacity="0"/></radialGradient>
<linearGradient id="raza" x1="0" y1="0" x2="1" y2="0"><stop offset="0" stop-color="#fff" stop-opacity="0"/><stop offset=".5" stop-color="#fff" stop-opacity=".10"/><stop offset="1" stop-color="#fff" stop-opacity="0"/></linearGradient>
<pattern id="pc" width="28" height="28" patternUnits="userSpaceOnUse"><circle cx="2" cy="2" r="1.4" fill="#fff" fill-opacity=".13"/></pattern>
<clipPath id="cl"><rect width="{w}" height="{h}" rx="24"/></clipPath>
</defs>
<g clip-path="url(#cl)" font-family="{FONT}">
<rect width="{w}" height="{h}" fill="url(#fg)"/>
<circle class="gl1" cx="180" cy="40" r="300" fill="url(#lum)"/>
<circle class="gl2" cx="1120" cy="320" r="320" fill="url(#lum)"/>
<rect width="{w}" height="{h}" fill="url(#pc)"/>
<g class="dr"><rect x="0" y="0" width="260" height="{h}" fill="url(#raza)" transform="skewX(-20)"/></g>
<g class="a1"><text x="64" y="112" font-size="56" font-weight="800" fill="#fff">Algoritmi elementari</text></g>
<g class="a2"><text x="64" y="176" font-size="56" font-weight="800" fill="#f5b83d">în C++</text>
<rect class="cur" x="250" y="134" width="5" height="48" rx="2" fill="#f5b83d"/></g>
<g class="a3"><text x="64" y="222" font-size="21" fill="#fff" fill-opacity=".93">{total} de probleme rezolvate și explicate, pentru liceu și bacalaureat</text></g>
<g class="a4">{''.join(chips)}</g>
<rect x="820" y="36" width="400" height="248" rx="20" fill="{t['panou']}" fill-opacity=".42"/>
<text x="1020" y="68" text-anchor="middle" font-family="{MONO}" font-size="14" fill="#fff" fill-opacity=".8">sortare prin metoda bulelor</text>
<g transform="translate({px0},96)">{bcorp}</g>
<rect x="{px0}" y="250" width="{bw}" height="3" rx="1.5" fill="#fff" fill-opacity=".35"/>
</g>"""
    return svg(w, h, css, corp, f"Algoritmi elementari în C++: {total} de probleme rezolvate pentru liceu și bacalaureat")


def separator(t):
    w, h = 1200, 16
    css = (
        kf("sp", [(0, "transform:translateX(-240px)"), (100, "transform:translateX(1200px)")])
        + ".sp{transform:translateX(480px);animation:sp 6s cubic-bezier(.45,0,.55,1) infinite}"
    )
    corp = f"""<defs><linearGradient id="sg" x1="0" y1="0" x2="1" y2="0">
<stop offset="0" stop-color="{t['brand']}" stop-opacity="0"/><stop offset=".45" stop-color="{t['brand']}"/>
<stop offset=".7" stop-color="{t['accent']}"/><stop offset="1" stop-color="{t['accent']}" stop-opacity="0"/></linearGradient></defs>
<rect x="0" y="7" width="{w}" height="2" rx="1" fill="{t['bordura']}"/>
<g class="sp"><rect x="0" y="6" width="240" height="4" rx="2" fill="url(#sg)"/><circle cx="200" cy="8" r="4" fill="{t['accent']}"/></g>"""
    return svg(w, h, css, corp, "Separator animat")


# ---------------------------------------------------------------- animațiile cardurilor de clasă

def fereastra(nume, a, b, total, cls):
    """Element vizibil doar în intervalul [a, b) dintr-un ciclu de `total` secunde."""
    p = lambda x: 100 * x / total  # noqa: E731
    cadre = [(0, "opacity:0"), (p(a) - 0.6, "opacity:0"), (p(a), "opacity:1"), (p(b) - 0.6, "opacity:1"), (p(b), "opacity:0"), (100, "opacity:0")]
    if a <= 0:
        cadre = [(0, "opacity:1"), (p(b) - 0.6, "opacity:1"), (p(b), "opacity:0"), (100 - 2.5, "opacity:0"), (100, "opacity:1")]
    return kf(nume, cadre) + f".{cls}{{animation:{nume} {total}s linear infinite}}"


def anim_cifre(t):
    """Suma cifrelor lui 48213: ultima cifră cade, suma crește."""
    total, cifre = 8.0, "48213"
    p = lambda x: 100 * x / total  # noqa: E731
    css, corp = [], []
    for j, c in enumerate(cifre):
        r = len(cifre) - 1 - j
        t0 = 0.8 + r * 1.2
        css.append(kf(f"d{j}", [
            (0, "opacity:1;transform:none"), (p(t0), "opacity:1;transform:none"),
            (p(t0 + 0.6), "opacity:0;transform:translateY(34px)"), (p(7.2), "opacity:0;transform:translateY(34px)"),
            (100, "opacity:1;transform:none"),
        ]))
        css.append(f".d{j}{{animation:d{j} {total}s ease-in-out infinite}}")
        x = 840 + j * 46
        corp.append(
            f'<g class="d{j}"><rect x="{x}" y="46" width="42" height="48" rx="10" fill="{t["pal"]}" stroke="{t["brand"]}" stroke-width="2"/>'
            f'<text x="{x + 21}" y="79" text-anchor="middle" font-family="{MONO}" font-size="24" font-weight="700" fill="{t["text"]}">{c}</text></g>'
        )
    sume, s = [0], 0
    for c in reversed(cifre):
        s += int(c)
        sume.append(s)
    momente = [0] + [0.8 + r * 1.2 + 0.6 for r in range(5)] + [7.4]
    for k, val in enumerate(sume):
        css.append(fereastra(f"s{k}", momente[k], momente[k + 1], total, f"s{k}"))
        baza = "" if k == 0 else ' opacity="0"'
        corp.append(
            f'<text class="s{k}"{baza} x="1084" y="78" font-family="{MONO}" font-size="22" font-weight="700" fill="{t["accent"]}">s = {val}</text>'
        )
    corp.append(f'<text x="840" y="150" font-family="{MONO}" font-size="14" fill="{t["slab"]}">suma cifrelor: s += n % 10; n /= 10;</text>')
    return "".join(css), "".join(corp)


def anim_hanoi(t):
    """Turnurile din Hanoi cu 3 discuri (7 mutări)."""
    tije, baza_y, gros, lifta = [878, 1002, 1126], 128, 16, 34
    latimi = [96, 70, 44]
    mutari = []

    def hanoi(n, a, c, b):
        if n:
            hanoi(n - 1, a, b, c)
            mutari.append((a, c))
            hanoi(n - 1, b, c, a)

    hanoi(3, 0, 2, 1)
    stive = [[0, 1, 2], [], []]
    poz = {d: (tije[0], baza_y - gros * (i + 1)) for i, d in enumerate(stive[0])}
    pas, start = 0.9, 0.6
    total = start + len(mutari) * pas + 1.6
    p = lambda x: 100 * x / total  # noqa: E731
    cadre = {d: [(0, poz[d]), (p(start), poz[d])] for d in range(3)}
    for k, (a, c) in enumerate(mutari):
        d = stive[a].pop()
        x0, y0 = poz[d]
        x1, y1 = tije[c], baza_y - gros * (len(stive[c]) + 1)
        stive[c].append(d)
        t0 = start + k * pas
        cadre[d] += [(p(t0), (x0, y0)), (p(t0 + 0.28), (x0, lifta)), (p(t0 + 0.6), (x1, lifta)), (p(t0 + 0.86), (x1, y1))]
        poz[d] = (x1, y1)
    css, corp = [], []
    for d in range(3):
        inceput = cadre[d][0][1]
        fr = cadre[d] + [(p(total - 0.55), poz[d]), (p(total - 0.5), inceput), (100, inceput)]
        css.append(kf(f"h{d}", [(q, f"transform:translate({x}px,{y}px)") for q, (x, y) in fr]))
        css.append(f".h{d}{{transform:translate({inceput[0]}px,{inceput[1]}px);animation:h{d} {total:.2f}s ease-in-out infinite,hf {total:.2f}s linear infinite}}")
    css.append(kf("hf", [(0, "opacity:1"), (p(total - 0.9), "opacity:1"), (p(total - 0.6), "opacity:0"), (p(total - 0.4), "opacity:0"), (100, "opacity:1")]))
    for x in tije:
        corp.append(f'<rect x="{x - 3}" y="56" width="6" height="74" rx="3" fill="{t["bordura"]}"/>')
    corp.append(f'<rect x="826" y="128" width="352" height="5" rx="2.5" fill="{t["slab"]}" fill-opacity=".5"/>')
    culori = [t["brand"], "#8a5cf0", t["accent"]]
    for d in range(3):
        corp.append(f'<g class="h{d}"><rect x="{-latimi[d] / 2}" y="0" width="{latimi[d]}" height="{gros - 2}" rx="7" fill="{culori[d]}"/></g>')
    corp.append(f'<text x="830" y="160" font-family="{MONO}" font-size="14" fill="{t["slab"]}">turnurile din Hanoi: 7 mutări pentru 3 discuri</text>')
    return "".join(css), "".join(corp)


def anim_bfs(t):
    """Parcurgere în lățime: nivelurile se aprind pe rând."""
    noduri = [(1010, 34), (930, 78), (1090, 78), (880, 124), (970, 124), (1050, 124), (1140, 124)]
    nivel = [0, 1, 1, 2, 2, 2, 2]
    arbore = [(0, 1), (0, 2), (1, 3), (1, 4), (2, 5), (2, 6)]
    total = 6.0
    p = lambda x: 100 * x / total  # noqa: E731
    css = []
    for lv in range(3):
        t0 = 0.6 + lv * 1.2
        css.append(kf(f"n{lv}", [(0, f"fill:{t['pal']}"), (p(t0), f"fill:{t['pal']}"), (p(t0 + 0.3), f"fill:{t['accent']}"), (p(5.0), f"fill:{t['accent']}"), (p(5.6), f"fill:{t['pal']}"), (100, f"fill:{t['pal']}")]))
        css.append(kf(f"m{lv}", [(0, f"stroke:{t['bordura']}"), (p(t0), f"stroke:{t['bordura']}"), (p(t0 + 0.3), f"stroke:{t['accent']}"), (p(5.0), f"stroke:{t['accent']}"), (p(5.6), f"stroke:{t['bordura']}"), (100, f"stroke:{t['bordura']}")]))
        css.append(f".n{lv}{{fill:{t['pal']};animation:n{lv} {total}s linear infinite}}.m{lv}{{stroke:{t['bordura']};animation:m{lv} {total}s linear infinite}}")
    corp = [f'<line x1="{noduri[4][0]}" y1="{noduri[4][1]}" x2="{noduri[5][0]}" y2="{noduri[5][1]}" stroke="{t["bordura"]}" stroke-width="3" stroke-dasharray="5 5"/>']
    for a, b in arbore:
        corp.append(f'<line class="m{nivel[b]}" x1="{noduri[a][0]}" y1="{noduri[a][1]}" x2="{noduri[b][0]}" y2="{noduri[b][1]}" stroke-width="3.5"/>')
    for i, (x, y) in enumerate(noduri):
        corp.append(
            f'<circle class="n{nivel[i]}" cx="{x}" cy="{y}" r="16" stroke="{t["brand"]}" stroke-width="2.5"/>'
            f'<text x="{x}" y="{y + 5}" text-anchor="middle" font-family="{MONO}" font-size="14" font-weight="700" fill="{t["text"]}">{i + 1}</text>'
        )
    corp.append(f'<text x="830" y="166" font-family="{MONO}" font-size="14" fill="{t["slab"]}">parcurgere în lățime (BFS), nivel cu nivel</text>')
    return "".join(css), "".join(corp)


def distante_lee(randuri, coloane, obstacole, start):
    from collections import deque

    dist = {start: 0}
    coada = deque([start])
    while coada:
        r, c = coada.popleft()
        for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            v = (r + dr, c + dc)
            if 0 <= v[0] < randuri and 0 <= v[1] < coloane and v not in obstacole and v not in dist:
                dist[v] = dist[(r, c)] + 1
                coada.append(v)
    return dist


def anim_lee(t):
    """Algoritmul lui Lee: valul de distanțe pornește din colțul stânga-sus."""
    randuri, coloane, latura, spatiu, x0, y0 = 4, 10, 26, 4, 846, 22
    obstacole = {(1, 2), (2, 2), (3, 2), (0, 5), (1, 5), (2, 5), (2, 8), (3, 8)}
    dist = distante_lee(randuri, coloane, obstacole, (0, 0))
    assert (randuri - 1, coloane - 1) in dist
    dmax = max(dist.values())
    pas = 0.3
    total = round(0.4 + dmax * pas + 1.8, 2)
    p = lambda x: 100 * x / total  # noqa: E731
    css, corp = [], []
    for d in range(dmax + 1):
        t0 = 0.4 + d * pas
        css.append(kf(f"l{d}", [(0, "opacity:0"), (p(t0), "opacity:0"), (p(t0 + 0.25), "opacity:1"), (p(total - 0.6), "opacity:1"), (p(total - 0.2), "opacity:0"), (100, "opacity:0")]))
        css.append(f".l{d}{{animation:l{d} {total}s linear infinite}}")
    for r in range(randuri):
        for c in range(coloane):
            x, y = x0 + c * (latura + spatiu), y0 + r * (latura + spatiu)
            if (r, c) in obstacole:
                corp.append(f'<rect x="{x}" y="{y}" width="{latura}" height="{latura}" rx="5" fill="{t["slab"]}" fill-opacity=".55"/>')
                continue
            corp.append(f'<rect x="{x}" y="{y}" width="{latura}" height="{latura}" rx="5" fill="{t["pal"]}"/>')
            d = dist.get((r, c))
            if d is None:
                continue
            final = (r, c) == (randuri - 1, coloane - 1)
            culoare = t["accent"] if final or d == 0 else t["brand"]
            opac = 1 if final or d == 0 else round(0.45 + 0.5 * d / dmax, 2)
            corp.append(
                f'<g class="l{d}"><rect x="{x}" y="{y}" width="{latura}" height="{latura}" rx="5" fill="{culoare}" fill-opacity="{opac}"/>'
                f'<text x="{x + latura / 2}" y="{y + 18}" text-anchor="middle" font-family="{MONO}" font-size="12" font-weight="700" fill="#fff">{d}</text></g>'
            )
    corp.append(f'<text x="846" y="166" font-family="{MONO}" font-size="14" fill="{t["slab"]}">algoritmul lui Lee: distanțe minime</text>')
    return "".join(css), "".join(corp)


ANIMATII_CLASA = {"09": anim_cifre, "10": anim_hanoi, "11": anim_bfs, "12": anim_lee}


def card_clasa(t, clasa):
    w, h = 1200, 180
    acss, acorp = ANIMATII_CLASA.get(clasa["nr"], anim_bfs)(t)
    nume = [scurt(c["folder"]) for c in clasa["capitole"]]
    randuri, rand = [], ""
    for n in nume:
        incercare = f"{rand} · {n}" if rand else n
        if len(incercare) > 62 and rand:
            randuri.append(rand)
            rand = n
        else:
            rand = incercare
    randuri.append(rand)
    nr_cap = len(clasa["capitole"])
    from genereaza_readme import cu_de  # import târziu: genereaza_readme importă acest modul

    css = acss + kf("pu", [(0, "transform:scale(1)"), (50, "transform:scale(1.06)"), (100, "transform:scale(1)")]) + \
        ".pu{transform-box:fill-box;transform-origin:center;animation:pu 3.2s ease-in-out infinite}"
    linii = "".join(
        f'<text x="160" y="{126 + 24 * i}" font-size="16" fill="{t["slab"]}">{escape(r)}</text>' for i, r in enumerate(randuri[:2])
    )
    corp = f"""<defs><linearGradient id="cg" x1="0" y1="0" x2="1" y2="1"><stop offset="0" stop-color="#4f6fe6"/><stop offset="1" stop-color="#6a42d0"/></linearGradient></defs>
<g font-family="{FONT}">
<rect x="1" y="1" width="{w - 2}" height="{h - 2}" rx="18" fill="{t['card']}" stroke="{t['bordura']}" stroke-width="2"/>
<g class="pu"><rect x="30" y="38" width="104" height="104" rx="24" fill="url(#cg)"/>
<text x="82" y="104" text-anchor="middle" font-size="38" font-weight="800" fill="#fff">{ROMAN.get(clasa['nr'], clasa['nr'])}</text></g>
<text x="160" y="66" font-size="32" font-weight="800" fill="{t['text']}">{escape(clasa['titlu'])}</text>
<text x="160" y="96" font-size="18" font-weight="600" fill="{t['brand']}">{cu_de(clasa['total'], 'algoritm', 'algoritmi')} în {cu_de(nr_cap, 'capitol', 'capitole')}</text>
{linii}
<line x1="820" y1="24" x2="820" y2="156" stroke="{t['bordura']}" stroke-width="2"/>
{acorp}
</g>"""
    return svg(w, h, css, corp, f"{clasa['titlu']}: {cu_de(clasa['total'], 'algoritm', 'algoritmi')}")


# ---------------------------------------------------------------- pictogramele capitolelor (64×64)

ALB, MOALE, GALBEN = "#ffffff", "rgba(255,255,255,.35)", "#f5b83d"


def i_cifre():
    css = kf("c", [(0, "opacity:1;transform:none"), (40, "opacity:1;transform:none"), (70, "opacity:0;transform:translateY(14px)"), (72, "opacity:0;transform:translateY(-10px)"), (100, "opacity:1;transform:none")]) + ".c{animation:c 2.4s ease-in-out infinite}"
    return css, f'<text x="12" y="40" font-family="{MONO}" font-size="21" font-weight="700" fill="{ALB}">12</text><text class="c" x="37" y="40" font-family="{MONO}" font-size="21" font-weight="700" fill="{GALBEN}">3</text>'


def i_ciur():
    css = kf("p", [(0, f"fill:{MOALE}"), (25, f"fill:{GALBEN}"), (60, f"fill:{GALBEN}"), (85, f"fill:{MOALE}"), (100, f"fill:{MOALE}")]) + f".p{{fill:{MOALE};animation:p 3s ease-in-out infinite}}"
    corp = []
    for k in range(9):
        n, x, y = k + 1, 16 + 16 * (k % 3), 16 + 16 * (k // 3)
        if n in (2, 3, 5, 7):
            corp.append(f'<circle class="p" style="animation-delay:{[2, 3, 5, 7].index(n) * 0.35}s" cx="{x}" cy="{y}" r="5.5"/>')
        else:
            corp.append(f'<circle cx="{x}" cy="{y}" r="4" fill="{MOALE}"/>')
    return css, "".join(corp)


def pasi_x(nume, pozitii, durata, cls, baza=0):
    n = len(pozitii)
    cadre = [(100 * i / n, f"transform:translateX({x}px)") for i, x in enumerate(pozitii)] + [(100, f"transform:translateX({pozitii[0]}px)")]
    return kf(nume, cadre) + f".{cls}{{transform:translateX({baza}px);animation:{nume} {durata}s step-end infinite}}"


def i_scanare():
    corp = "".join(f'<rect x="{7 + 13 * i}" y="26" width="11" height="12" rx="3" fill="{MOALE}"/>' for i in range(4))
    return pasi_x("s", [0, 13, 26, 39], 2.4, "s"), corp + f'<rect class="s" x="5" y="24" width="15" height="16" rx="4" fill="none" stroke="{GALBEN}" stroke-width="2.5"/>'


def i_binar():
    css = kf("u", [(0, "opacity:0"), (50, "opacity:1"), (100, "opacity:1")]) + kf("z", [(0, "opacity:1"), (50, "opacity:0"), (100, "opacity:0")])
    corp = []
    for i, x in enumerate([13, 25, 37, 49]):
        d = 1.2 * 2 ** (3 - i)
        css += f".u{i}{{animation:u {d}s step-end infinite}}.z{i}{{animation:z {d}s step-end infinite}}"
        corp.append(f'<text class="z{i}" x="{x}" y="40" text-anchor="middle" font-family="{MONO}" font-size="18" font-weight="700" fill="{MOALE}">0</text>')
        corp.append(f'<text class="u{i}" opacity="0" x="{x}" y="40" text-anchor="middle" font-family="{MONO}" font-size="18" font-weight="700" fill="{ALB}">1</text>')
    return css, "".join(corp)


def i_vector():
    corp = "".join(f'<rect x="{7 + 10.5 * i}" y="20" width="9" height="14" rx="2" fill="none" stroke="{ALB}" stroke-width="1.8"/>' for i in range(5))
    corp += f'<path class="v" d="M11.5 40l-4 6h8z" fill="{GALBEN}"/>'
    return pasi_x("v", [0, 10.5, 21, 31.5, 42], 2.5, "v"), corp


def i_bare():
    css, corp, bw = bare_sortare([3, 1, 4, 2], 9, 4, 34, ALB, GALBEN, prefix="q", pas=0.55)
    return css, f'<g transform="translate({(64 - bw) / 2},16)">{corp}</g>'


def i_sume():
    css = kf("g", [(0, "transform:scaleY(0)"), (20, "transform:scaleY(1)"), (80, "transform:scaleY(1)"), (100, "transform:scaleY(0)")])
    css += ".g{transform-box:fill-box;transform-origin:bottom;animation:g 3s ease-out infinite}"
    corp = "".join(f'<rect class="g" style="animation-delay:{i * 0.18}s" x="{9 + 9.5 * i}" y="{48 - 7 * (i + 1)}" width="7" height="{7 * (i + 1)}" rx="1.5" fill="{GALBEN if i == 4 else ALB}"/>' for i in range(5))
    return css, corp


def deseneaza(cls, lungime, durata, intarziere=0):
    return f".{cls}{{stroke-dasharray:{lungime};animation:dd{cls} {durata}s ease-in-out {intarziere}s infinite}}" + kf(
        f"dd{cls}", [(0, f"stroke-dashoffset:{lungime}"), (40, "stroke-dashoffset:0"), (80, "stroke-dashoffset:0"), (100, f"stroke-dashoffset:{lungime}")]
    )


def i_fisier():
    css = "".join(deseneaza(f"r{i}", 18, 3, i * 0.3) for i in range(3))
    corp = f'<path d="M18 12h20l9 9v31H18z" fill="none" stroke="{ALB}" stroke-width="2.5" stroke-linejoin="round"/><path d="M38 12v9h9" fill="none" stroke="{ALB}" stroke-width="2.5" stroke-linejoin="round"/>'
    corp += "".join(f'<path class="r{i}" d="M24 {30 + 7 * i}h18" stroke="{GALBEN if i == 0 else ALB}" stroke-width="2.5" stroke-linecap="round"/>' for i in range(3))
    return css, corp


def i_functie():
    css = kf("f", [(0, "transform:translateX(-14px);opacity:0"), (15, "opacity:1"), (45, "transform:translateX(16px);opacity:1"), (55, "transform:translateX(16px);opacity:0"), (100, "transform:translateX(16px);opacity:0")])
    css += kf("o", [(0, "opacity:0;transform:none"), (50, "opacity:0;transform:none"), (60, "opacity:1"), (90, "opacity:1;transform:translateX(14px)"), (100, "opacity:0;transform:translateX(14px)")])
    css += ".f{animation:f 2.6s ease-in-out infinite}.o{animation:o 2.6s ease-in-out infinite}"
    corp = f'<text x="32" y="38" text-anchor="middle" font-family="{MONO}" font-size="17" font-weight="700" fill="{ALB}">f( )</text>'
    corp += f'<circle class="f" cx="10" cy="32" r="3.5" fill="{GALBEN}"/><circle class="o" cx="46" cy="32" r="3.5" fill="{GALBEN}"/>'
    return css, corp


def grila(n, latura, spatiu, x0, y0, clasa_celula):
    corp = []
    for r in range(n):
        for c in range(n):
            x, y = x0 + c * (latura + spatiu), y0 + r * (latura + spatiu)
            corp.append(clasa_celula(r, c, x, y))
    return "".join(corp)


def i_matrice():
    css = kf("m", [(0, f"fill:{MOALE}"), (15, f"fill:{GALBEN}"), (55, f"fill:{GALBEN}"), (75, f"fill:{MOALE}"), (100, f"fill:{MOALE}")]) + f".m{{fill:{MOALE};animation:m 3s ease-in-out infinite}}"
    corp = grila(3, 12, 3, 11.5, 11.5, lambda r, c, x, y: (
        f'<rect class="m" style="animation-delay:{r * 0.3}s" x="{x}" y="{y}" width="12" height="12" rx="2.5"/>' if r == c
        else f'<rect x="{x}" y="{y}" width="12" height="12" rx="2.5" fill="{MOALE}"/>'))
    return css, corp


def i_text():
    css = "".join(kf(f"t{i}", [(0, "opacity:0"), (10 + 20 * i, "opacity:0"), (12 + 20 * i, "opacity:1"), (85, "opacity:1"), (90, "opacity:0"), (100, "opacity:0")]) + f".t{i}{{animation:t{i} 3.2s step-end infinite}}" for i in range(3))
    css += kf("k", [(0, "transform:translateX(0)"), (10, "transform:translateX(0)"), (30, "transform:translateX(11px)"), (50, "transform:translateX(22px)"), (70, "transform:translateX(33px)"), (88, "transform:translateX(33px)"), (90, "transform:translateX(0)"), (100, "transform:translateX(0)")])
    css += ".k{animation:k 3.2s step-end infinite}"
    corp = "".join(f'<text class="t{i}" x="{14 + 11 * i}" y="39" font-family="{MONO}" font-size="18" font-weight="700" fill="{ALB}">{ch}</text>' for i, ch in enumerate("abc"))
    return css, corp + f'<rect class="k" x="13" y="43" width="10" height="3" rx="1.5" fill="{GALBEN}"/>'


def i_struct():
    css = "".join(kf(f"s{i}", [(0, "transform:scaleX(0)"), (20 + 15 * i, "transform:scaleX(1)"), (85, "transform:scaleX(1)"), (100, "transform:scaleX(0)")]) + f".s{i}{{transform-box:fill-box;transform-origin:left;animation:s{i} 3s ease-out infinite}}" for i in range(3))
    corp = f'<text x="8" y="44" font-family="{MONO}" font-size="30" fill="{ALB}">{{</text><text x="40" y="44" font-family="{MONO}" font-size="30" fill="{ALB}">}}</text>'
    corp += "".join(f'<rect class="s{i}" x="24" y="{22 + 8 * i}" width="{16 - 4 * (i == 2)}" height="3.5" rx="1.75" fill="{GALBEN if i == 0 else ALB}"/>' for i in range(3))
    return css, corp


def i_recursie():
    css = kf("r", [(0, "stroke:rgba(255,255,255,.35)"), (20, f"stroke:{GALBEN}"), (45, "stroke:rgba(255,255,255,.35)"), (100, "stroke:rgba(255,255,255,.35)")])
    corp = []
    for i, s in enumerate([40, 28, 16]):
        css += f".r{i}{{stroke:{MOALE};animation:r 2.4s ease-in-out {i * 0.35}s infinite}}"
        corp.append(f'<rect class="r{i}" x="{32 - s / 2}" y="{32 - s / 2}" width="{s}" height="{s}" rx="{3 + i}" fill="none" stroke-width="3"/>')
    return css, "".join(corp) + f'<circle cx="32" cy="32" r="3" fill="{GALBEN}"/>'


def i_divide():
    css = "".join(kf(f"n{i}", [(0, "opacity:0;transform:translateY(-6px)"), (15 + 22 * i, "opacity:0;transform:translateY(-6px)"), (27 + 22 * i, "opacity:1;transform:none"), (85, "opacity:1;transform:none"), (100, "opacity:0")]) + f".n{i}{{animation:n{i} 3.4s ease-out infinite}}" for i in range(1, 3))
    corp = f'<rect x="10" y="14" width="44" height="8" rx="3" fill="{ALB}"/>'
    corp += f'<g class="n1"><rect x="10" y="28" width="20" height="8" rx="3" fill="{ALB}"/><rect x="34" y="28" width="20" height="8" rx="3" fill="{ALB}"/></g>'
    corp += '<g class="n2">' + "".join(f'<rect x="{10 + 12 * k}" y="42" width="8" height="8" rx="2.5" fill="{GALBEN}"/>' for k in range(4)) + "</g>"
    return css, corp


def i_backtracking():
    noduri = {"r": (32, 13), "a": (19, 31), "b": (45, 31), "aa": (12, 50), "ab": (26, 50), "ba": (38, 50), "bb": (52, 50)}
    muchii = [("r", "a"), ("r", "b"), ("a", "aa"), ("a", "ab"), ("b", "ba"), ("b", "bb")]
    drum = ["r", "a", "aa", "a", "ab", "a", "r", "b", "ba", "b", "bb", "b", "r"]
    cadre = [(100 * i / (len(drum) - 1), f"transform:translate({noduri[n][0]}px,{noduri[n][1]}px)") for i, n in enumerate(drum)]
    css = kf("bt", cadre) + f".bt{{transform:translate(32px,13px);animation:bt 5.2s ease-in-out infinite}}"
    corp = "".join(f'<line x1="{noduri[a][0]}" y1="{noduri[a][1]}" x2="{noduri[b][0]}" y2="{noduri[b][1]}" stroke="{MOALE}" stroke-width="2.5"/>' for a, b in muchii)
    corp += "".join(f'<circle cx="{x}" cy="{y}" r="4" fill="{ALB}"/>' for x, y in noduri.values())
    return css, corp + f'<circle class="bt" cx="0" cy="0" r="5.5" fill="{GALBEN}"/>'


def i_monede():
    css = ""
    corp = []
    for i, y in enumerate([48, 40, 32]):
        css += kf(f"m{i}", [(0, "opacity:0;transform:translateY(-30px)"), (8 + 18 * i, "opacity:0;transform:translateY(-30px)"), (22 + 18 * i, "opacity:1;transform:none"), (85, "opacity:1;transform:none"), (100, "opacity:0;transform:none")]) + f".m{i}{{animation:m{i} 3.4s cubic-bezier(.3,1.4,.6,1) infinite}}"
        corp.append(f'<g class="m{i}"><ellipse cx="32" cy="{y}" rx="{15 - 2 * i}" ry="5" fill="{GALBEN if i == 0 else ALB}" stroke="#6a42d0" stroke-width="1.5"/></g>')
    return css, "".join(corp)


def i_tabel():
    css = kf("t", [(0, f"fill:{MOALE}"), (8, f"fill:{GALBEN}"), (70, f"fill:{GALBEN}"), (80, f"fill:{MOALE}"), (100, f"fill:{MOALE}")]) + f".t{{fill:{MOALE};animation:t 3.6s ease-out infinite}}"
    corp = grila(3, 12, 3, 11.5, 11.5, lambda r, c, x, y: f'<rect class="t" style="animation-delay:{(r * 3 + c) * 0.2}s" x="{x}" y="{y}" width="12" height="12" rx="2.5"/>')
    return css, corp


def i_stiva():
    css, corp = "", [f'<path d="M16 14v36h32V14" fill="none" stroke="{ALB}" stroke-width="2.5" stroke-linejoin="round"/>']
    for i in range(3):
        a, b = 4 + 12 * i, 64 + 10 * (2 - i)
        css += kf(f"s{i}", [(0, "opacity:0;transform:translateY(-26px)"), (a, "opacity:0;transform:translateY(-26px)"), (a + 10, "opacity:1;transform:none"), (b, "opacity:1;transform:none"), (b + 8, "opacity:0;transform:translateY(-26px)"), (100, "opacity:0;transform:translateY(-26px)")])
        css += f".s{i}{{animation:s{i} 4s ease-in-out infinite}}"
        corp.append(f'<rect class="s{i}" x="20" y="{39 - 11 * i}" width="24" height="9" rx="2.5" fill="{GALBEN if i == 2 else ALB}"/>')
    return css, "".join(corp)


def i_graf():
    noduri = [(32, 12), (14, 30), (50, 30), (22, 52), (44, 52)]
    muchii = [(0, 1), (0, 2), (1, 3), (2, 4), (3, 4), (1, 2)]
    css = kf("g", [(0, f"fill:{MOALE}"), (12, f"fill:{GALBEN}"), (70, f"fill:{GALBEN}"), (85, f"fill:{MOALE}"), (100, f"fill:{MOALE}")]) + f".g{{fill:{MOALE};animation:g 3.6s ease-out infinite}}"
    corp = "".join(f'<line x1="{noduri[a][0]}" y1="{noduri[a][1]}" x2="{noduri[b][0]}" y2="{noduri[b][1]}" stroke="{ALB}" stroke-width="2"/>' for a, b in muchii)
    nivel = [0, 1, 1, 2, 2]
    corp += "".join(f'<circle class="g" style="animation-delay:{nivel[i] * 0.45}s" cx="{x}" cy="{y}" r="6" stroke="{ALB}" stroke-width="2"/>' for i, (x, y) in enumerate(noduri))
    return css, corp


def i_orientat():
    a, b, c = (14, 46), (32, 14), (50, 46)
    css = kf("o", [(0, f"transform:translate({a[0]}px,{a[1]}px)"), (33, f"transform:translate({b[0]}px,{b[1]}px)"), (66, f"transform:translate({c[0]}px,{c[1]}px)"), (100, f"transform:translate({a[0]}px,{a[1]}px)")])
    css += f".o{{transform:translate({a[0]}px,{a[1]}px);animation:o 3s linear infinite}}"
    corp = f'<defs><marker id="s" viewBox="0 0 8 8" refX="7" refY="4" markerWidth="5" markerHeight="5" orient="auto"><path d="M0 0L8 4L0 8z" fill="{ALB}"/></marker></defs>'
    for (x1, y1), (x2, y2) in ((a, b), (b, c), (c, a)):
        dx, dy = x2 - x1, y2 - y1
        L = (dx * dx + dy * dy) ** 0.5
        ux, uy = dx / L, dy / L
        corp += f'<line x1="{x1 + ux * 8:.1f}" y1="{y1 + uy * 8:.1f}" x2="{x2 - ux * 9:.1f}" y2="{y2 - uy * 9:.1f}" stroke="{ALB}" stroke-width="2" marker-end="url(#s)"/>'
    corp += "".join(f'<circle cx="{x}" cy="{y}" r="5.5" fill="none" stroke="{ALB}" stroke-width="2"/>' for x, y in (a, b, c))
    return css, corp + f'<circle class="o" cx="0" cy="0" r="4" fill="{GALBEN}"/>'


def i_arbore():
    noduri = [((32, 13), 0), ((19, 31), 1), ((45, 31), 1), ((12, 50), 2), ((26, 50), 2), ((38, 50), 2), ((52, 50), 2)]
    parinte = [None, 0, 0, 1, 1, 2, 2]
    css = kf("a", [(0, "opacity:0;transform:scale(.3)"), (12, "opacity:1;transform:scale(1)"), (80, "opacity:1;transform:scale(1)"), (95, "opacity:0;transform:scale(.3)"), (100, "opacity:0;transform:scale(.3)")])
    css += ".a{transform-box:fill-box;transform-origin:center;animation:a 3.6s ease-out infinite}"
    corp = []
    for i, ((x, y), lv) in enumerate(noduri):
        if parinte[i] is not None:
            (px, py), _ = noduri[parinte[i]]
            corp.append(f'<line class="a" style="animation-delay:{lv * 0.4}s" x1="{px}" y1="{py}" x2="{x}" y2="{y}" stroke="{MOALE}" stroke-width="2.5"/>')
    for (x, y), lv in noduri:
        corp.append(f'<circle class="a" style="animation-delay:{lv * 0.4}s" cx="{x}" cy="{y}" r="{5.5 if lv else 6.5}" fill="{GALBEN if lv == 0 else ALB}"/>')
    return css, "".join(corp)


def i_numere():
    texte, css, corp = ["998", "999", "1000"], "", []
    for i, tx in enumerate(texte):
        a, b = i * 100 / 3, (i + 1) * 100 / 3
        cadre = [(0, "opacity:0"), (a, "opacity:1"), (b, "opacity:0"), (100, "opacity:0")] if i else [(0, "opacity:1"), (b, "opacity:0"), (100, "opacity:0")]
        css += kf(f"x{i}", cadre) + f".x{i}{{animation:x{i} 3.6s step-end infinite}}"
        baza = "" if i == 2 else ' opacity="0"'
        corp.append(f'<text class="x{i}"{baza} x="32" y="44" text-anchor="middle" font-family="{MONO}" font-size="{17 if i == 2 else 19}" font-weight="700" fill="{ALB}">{tx}</text>')
    return css, "".join(corp) + f'<text x="48" y="22" text-anchor="middle" font-family="{MONO}" font-size="12" font-weight="700" fill="{GALBEN}">+1</text>'


def i_lee():
    css = kf("l", [(0, f"fill:{MOALE}"), (10, f"fill:{GALBEN}"), (55, f"fill:{GALBEN}"), (75, f"fill:{MOALE}"), (100, f"fill:{MOALE}")]) + f".l{{fill:{MOALE};animation:l 3.6s ease-out infinite}}"
    corp = grila(4, 9.5, 2.5, 8, 8, lambda r, c, x, y: f'<rect class="l" style="animation-delay:{(r + c) * 0.22:.2f}s" x="{x}" y="{y}" width="9.5" height="9.5" rx="2"/>')
    return css, corp


def i_matematica():
    css = kf("p", [(0, "transform:scale(1)"), (50, "transform:scale(1.12)"), (100, "transform:scale(1)")]) + ".p{transform-box:fill-box;transform-origin:center;animation:p 2.6s ease-in-out infinite}"
    css += kf("d", [(0, "opacity:.2"), (50, "opacity:1"), (100, "opacity:.2")]) + ".d{animation:d 1.8s ease-in-out infinite}"
    corp = f'<text class="p" x="32" y="40" text-anchor="middle" font-family="{FONT}" font-size="30" font-weight="700" fill="{ALB}">∑</text>'
    corp += "".join(f'<circle class="d" style="animation-delay:{i * 0.3}s" cx="{24 + 8 * i}" cy="52" r="2.5" fill="{GALBEN}"/>' for i in range(3))
    return css, corp


def i_pointeri():
    corp = "".join(f'<rect x="{5 + 9.3 * i}" y="22" width="7.6" height="12" rx="2" fill="{MOALE}"/>' for i in range(6))
    css = kf("st", [(0, "transform:translateX(0)"), (33, "transform:translateX(9.3px)"), (66, "transform:translateX(18.6px)"), (100, "transform:translateX(0)")])
    css += kf("dr", [(0, "transform:translateX(0)"), (33, "transform:translateX(-9.3px)"), (66, "transform:translateX(-18.6px)"), (100, "transform:translateX(0)")])
    css += ".st{animation:st 3s step-end infinite}.dr{animation:dr 3s step-end infinite}"
    corp += f'<path class="st" d="M8.8 40l-4 6h8z" fill="{GALBEN}"/><path class="dr" d="M55.3 40l-4 6h8z" fill="{ALB}"/>'
    return css, corp


def i_coada():
    css = kf("q", [(0, "transform:translateX(0)"), (100, "transform:translateX(-12px)")]) + ".q{animation:q 1.4s ease-in-out infinite}"
    css += kf("qi", [(0, "opacity:1"), (100, "opacity:0")]) + kf("qo", [(0, "opacity:0"), (100, "opacity:1")])
    css += ".qi{animation:qi 1.4s ease-in-out infinite}.qo{opacity:0;animation:qo 1.4s ease-in-out infinite}"
    corp = '<g class="q">'
    for i in range(5):
        cls = ' class="qi"' if i == 0 else ' class="qo"' if i == 4 else ""
        corp += f'<rect{cls} x="{8 + 12 * i}" y="26" width="9" height="12" rx="2.5" fill="{GALBEN if i == 1 else ALB}"/>'
    corp += "</g>"
    return css, corp + f'<path d="M8 46h48" stroke="{MOALE}" stroke-width="2" stroke-linecap="round"/>'


def i_bac():
    css = deseneaza("v", 40, 3)
    corp = f'<circle cx="32" cy="32" r="19" fill="none" stroke="{MOALE}" stroke-width="3"/>'
    return css, corp + f'<path class="v" d="M22 33l7 7 14-15" fill="none" stroke="{GALBEN}" stroke-width="4" stroke-linecap="round" stroke-linejoin="round"/>'


PICTOGRAME = {
    "cifre": i_cifre, "divizibilitate": i_ciur, "secvente": i_scanare, "baze": i_binar, "vectori": i_vector,
    "sortare-cautare": i_bare, "tehnici-vectori": i_sume, "fisiere": i_fisier, "subprograme": i_functie,
    "matrice": i_matrice, "siruri-caractere": i_text, "structuri": i_struct, "recursivitate": i_recursie,
    "divide-et-impera": i_divide, "backtracking": i_backtracking, "greedy": i_monede,
    "programare-dinamica": i_tabel, "liste-stive-cozi": i_stiva, "grafuri-neorientate": i_graf,
    "grafuri-orientate": i_orientat, "arbori": i_arbore, "numere-mari": i_numere, "lee-fill": i_lee,
    "matematica": i_matematica, "tehnici-avansate": i_pointeri, "structuri-de-date": i_coada,
    "bacalaureat": i_bac,
}


def pictograma(titlu, folder):
    cheie = folder.split("/")[-1].split("-", 1)[1]
    css, corp = PICTOGRAME.get(cheie, i_recursie)()
    fundal = (
        '<defs><linearGradient id="ig" x1="0" y1="0" x2="1" y2="1"><stop offset="0" stop-color="#4f6fe6"/>'
        '<stop offset="1" stop-color="#6a42d0"/></linearGradient></defs><rect width="64" height="64" rx="14" fill="url(#ig)"/>'
    )
    return svg(64, 64, css, fundal + corp, f"Animație: {titlu}")


# ---------------------------------------------------------------- căi și generare

def cale_pictograma(folder):
    return f".github/assets/capitole/{folder.replace('/', '-')}.svg"


def cale_card(nr, tema):
    return f".github/assets/clasa-{nr}-{tema}.svg"


def genereaza(clase):
    """Scrie toate SVG-urile și întoarce lista căilor relative scrise."""
    ASSETS.mkdir(parents=True, exist_ok=True)
    CAPITOLE.mkdir(parents=True, exist_ok=True)
    total = sum(c["total"] for c in clase)
    capitole = sum(len(c["capitole"]) for c in clase)
    fisiere = {}
    for tema, t in TEME.items():
        fisiere[f".github/assets/banner-{tema}.svg"] = banner(t, total, capitole)
        fisiere[f".github/assets/separator-{tema}.svg"] = separator(t)
        for clasa in clase:
            fisiere[cale_card(clasa["nr"], tema)] = card_clasa(t, clasa)
    for clasa in clase:
        for cap in clasa["capitole"]:
            fisiere[cale_pictograma(cap["folder"])] = pictograma(cap["titlu"], cap["folder"])
    asteptate = set()
    for rel, continut in fisiere.items():
        cale = RADACINA / rel
        cale.write_text(continut, encoding="utf-8", newline="\n")
        asteptate.add(cale)
        if len(continut.encode("utf-8")) > 300_000:
            sys.exit(f"{rel} depășește 300 KB.")
    for vechi in CAPITOLE.glob("*.svg"):
        if vechi not in asteptate:
            vechi.unlink()
    return sorted(fisiere)


if __name__ == "__main__":
    sys.stdout.reconfigure(encoding="utf-8")
    sys.path.insert(0, str(Path(__file__).resolve().parent))
    from genereaza_readme import colectie

    scrise = genereaza(colectie())
    print(f"{len(scrise)} imagini SVG generate în .github/assets/.")
