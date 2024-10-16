# Gestion de la Mémoire avec Allocation de Processus

Ce projet C implémente des algorithmes d'allocation de mémoire pour la gestion de processus, en utilisant des méthodes telles que le **Worst Fit**. Le programme gère une liste chaînée représentant la mémoire disponible et assigne des processus en fonction de leur taille à des blocs de mémoire disponibles.

## Fonctionnalités Principales
- **Saisie et gestion des processus** : Le programme permet de capturer une liste de processus avec leur taille.
- **Gestion de la mémoire** : Les blocs de mémoire libres et occupés sont gérés via des listes chaînées.
- **Algorithmes d'allocation** :
  - **Worst Fit** : L'algorithme place un processus dans le plus grand bloc libre disponible.

## Structure du Programme

### 1. `BestPosition(int taille)`
Cette fonction retourne la meilleure position pour insérer un processus dans la mémoire en fonction de sa taille. Elle parcourt la liste des blocs de mémoire disponibles et sélectionne celui qui correspond le mieux.

**Paramètres :**
- `taille` : Taille du processus à allouer.

**Retourne :**
- L'indice du bloc de mémoire où le processus peut être inséré.

### 2. Gestion de la Liste des Blocs Libres (`Current_Head`, `Previous_Head`)
Le programme utilise une liste chaînée pour gérer les blocs de mémoire. Chaque bloc peut être libre ou occupé. Ces blocs sont représentés par des structures (`Current_Head`, `Previous_Head`) et sont parcourus pour trouver des emplacements libres.

### 3. **`MB_TO_MFB` (Memory Block to Middle of Free Block)**
Cette fonction est utilisée pour insérer un bloc de mémoire libre dans une zone spécifique, souvent le premier bloc de la liste. Elle gère les cas où un processus est inséré dans la première zone mémoire libre.

**Paramètres :**
- `Current_Head` : Le bloc actuel de mémoire à traiter.
- `Current_FL` : Le processus à allouer.
- `Previous_FL` : Le bloc mémoire précédent dans la liste.

### 4. **`MB_TO_MMLB` (Memory Block to Middle of Linked Block)**
Similaire à `MB_TO_MFB`, cette fonction gère l'insertion d'un processus dans un bloc libre, mais dans un emplacement situé au milieu de la liste de la mémoire.

**Paramètres :**
- `Current_Head`, `Previous_Head` : Les blocs de mémoire actuels et précédents.
- `Current_FL` : Le processus à allouer.
- `Previous_FL` : Le bloc mémoire précédent dans la liste.

### 5. **`afficher(int t)`**
Cette fonction affiche l'état de la mémoire et des processus à un moment donné. Elle est utilisée pour visualiser l'exécution en cours.

**Paramètres :**
- `t` : Le temps actuel, qui est affiché à côté de chaque processus dans la mémoire.

### 6. **`int main()`**
La fonction principale du programme initialise la mémoire, saisit les processus, et exécute l'algorithme d'allocation. Voici les principales étapes :
1. La mémoire est initialisée avec une taille de 180.
2. Une liste de processus est saisie via `saisieLesProcessusDansLaListe`.
3. L'algorithme de **Worst Fit** est exécuté pour placer les processus dans la mémoire.

**Fonctions utilisées :**
- `saisieLesProcessusDansLaListe(int nbrProcessus)` : Capture une liste de processus en fonction du nombre total de processus.
- `WorstFit(int x)` : Exécute l'algorithme de Worst Fit pour placer les processus dans les blocs mémoire libres.

## Exécution du Programme
1. Compilez le fichier C avec `gcc` :
   ```bash
   gcc main.c -o gestion_memoire
   ```

2. Exécutez le programme :
   ```bash
   ./gestion_memoire
   ```

Le programme assignera les processus aux blocs de mémoire et affichera le résultat.
