<img width="150" height="95" align="left" style="float: left; margin: 0 10px 0 0;" alt="IUT" src="https://cdn.discordapp.com/attachments/739553949199106158/937150810431823912/logoIUT.jpg">

# Chiffrement de messages

---

Application en C permettant d'encoder et de décoder avec différentes méthodes de cryptage (Cesar, Vigenere) un message entré.

---

## Chapitres

- [Participants](#participants)
- [Objectifs](#objectifs)
- [Documentation](#doc)

---

<div id='participants'/>

## Participants

L'équipe est composée de Eric PHILIPPE, Brandon SOUBAIGNE, ainsi que d'Alexandre MOURCACOS
Nous sommes trois étudiants en informatique à l'IUT de Toulouse.

---

<div id='objectifs' />

## Objectifs

L'objectif principal de ce système est d'offrir à l'utilisateur une interface de cryptage et de décryptage de messages.
On retrouvera alors le cryptage de messages avec des algorithmes de cryptage différents, à savoir le cryptage de César, le cryptage de Vigenere. 
Le tout se veut complètement découpé, afin de pouvoir réutiliser les parties désirés dans d'autres applications.

--- 

<div id='doc' />

## Documentation

La suivante va se décomposer en plusieurs chapitres:

1. [Encodeur César](#encodeur-cesar)
2. [Encodeur Vigenere](#encodeur-vigenere)
3. [Affichage](#affichage)
4. [Utils](#utils)

---

<div id='encodeur-cesar' />

### Encodeur César

Le suivant se décompose en deux fonctions différentes:

```c
void caesar(char *message, int shift);
void caesar_decode(char *message, int shift);
```

Elles ont pour seul but de chiffrer et déchiffrer un message sans aucune vérification en amont. La vérification des différents input se fait plus haut.
A noter également que la fonction update le paramètre de message pour le rendre plus facile à utiliser.

---

<div id='encodeur-vigenere'>

### Encodeur Vigenere

Le suivant se décompose également en deux fonctions différentes:

```c
void vigenere(char *text, char *key, char *out);
void vigenere_decode(char *text, char *key, char *out);
```

Ces deux fonctions se veulent également brute dans leurs traitements, afin de pouvoir réutiliser leur code dans d'autres applications. On notera aussi la présence d'un paramètre d'output, désirant varier les méthodes utilisées pour le chiffrement et déchiffrement.

---

<div id='affichage'>

### Affichage

L'affichage est une extension à l'application. Le tout se veut facile à utiliser, et à réutiliser dans d'autres cas. Le système se décompose en un plus petit système d'affichage et de passage des différents menus. Le second, lui gère le lancement de chaque fonction, et amorce les différentes fonctions, avec le traitement des erreurs possibles.
Tous les menus sont contenus dans le dossier "Menus", le tout dans des fichiers .txt.

```c
launcher.h;

void FullTryCeasar();
void encodedToFileCeaser();
void fileToDecodeCeaser();
void decodeCeaser();
void FullTryVigenere();
void encodedToFileVigenere();
void fileToDecodeVigenere();
void decodeVigenere();
```

```c
menus.h;

void displayMenu(int page);
int getCMD(int page);

```

Le premier fichier permet donc de lancer les différentes situations désirées. Le second fichier permet de gérer les différentes pages, et de récupérer les entrées utilisateurs.

---

<div id='utils' />

### Utils

Le fichier utils se veut tout particulièrement être un fichier modulaire et utilisable absolument partout. Ce sont des fonctions basiques d'input et de vérifications d'input permettant le traitement efficace de ces dernières.

```c
utils.c;

void getMessage(char* str);
void getKeyChar(char* str);
int getKey();
int isAlphaNum(char* str);

```

