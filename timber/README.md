# Timber

Un clon simple del popular joc **Timberman**, desenvolupat durant les classes de programacio utilitzant C++ i la llibreria SFML per a grafics, sons i interaccio amb l'usuari. 

## Contingut del repositori
- ``timber.cpp`` - Codi del joc
- ``graphics/`` - Carpeta amb els grafics del joc
- ``fonts/`` - Carpeta amb la font utilitzada per els textos del joc
- ``sound/`` - Arxius de so del joc (S'implementara en els proxims dies)

## Caracteristiques:
- Jugador que ha de tallar un arbre amb una destral canviant de costat segons on baixin els obstacles.
- Temps limitat amb barra de temps.
- Obstacle (branques) que poden matar al jugador.
- Entitats mobils decoratives (nuvols i abella).
- Tronc volant visualment quan el jugador talla.
- Marcador amb la puntuacio en temps real.

## Controls
- **Enter** - Començar o reinciar el joc.
- **Fletxes dreta/esquerra** - Tallar l'arbre per la dreta o l'esquerra.
- **Esc** - Sortir del joc

## Estructura del joc
- **Player** – Sprite que es mou a l’esquerra o dreta per tallar arbres.
- **Branch** – Obstacles que poden fer perdre el joc si col·lisionen amb el jugador.
- **NPC** – Entitats mòbils com núvols i abella.
- **Log** – Tronc volant visual que apareix al tallar arbres.
- **Time Bar** – Barra que mostra el temps restant per cada acció.
- **Score Text** – Mostra la puntuació actual.

## Millores properes
- [x] Afegir sons al morir el jugador, acabar-se el temps, etc..
- [x] Corregir error del jugador despres de morir
- [x] Corregir errors amb els textos del HUD
- [x] Corregir error al tallar els troncs
- [x] Controlar la frequencia d'actualitzacio de puntuacio i FPS
- [X] Afegir HUD amb dades (FPS, temps)

## Reportar errors
Per reportar un error, informar sobre algun bug o alguna cosa que creus que es pugui millorar del joc, pots obrir un issue aqui: [Obrir issue](https://github.com/borreeell/timber/issues)



