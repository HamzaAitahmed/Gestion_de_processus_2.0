
# Gestion de la Mémoire et Allocation des Processus

Ce programme C simule la gestion de la mémoire dynamique à l'aide d'algorithmes d'allocation comme **First Fit**, **Best Fit** et **Worst Fit**. Il utilise des **listes chaînées** pour modéliser la mémoire et les processus, et des **pointeurs** pour manipuler ces structures.

---

## Variables Globales

### Pointeurs de Liste Chaînée

- **`node *head`** : Pointeur vers la tête de la liste chaînée qui représente les blocs de mémoire (libres ou alloués).
- **`process *fl`** : Pointeur vers la tête de la liste des processus à allouer en mémoire.
- **`Current_Head, Previous_Head`** : Utilisés pour parcourir la liste des blocs de mémoire.
- **`Current_FL, Previous_FL`** : Utilisés pour parcourir la liste des processus.

Ces pointeurs permettent de naviguer à travers la mémoire et la liste des processus.

### Autres Variables

- **`cpt_total`** : Compteur total pour suivre le temps d'exécution du programme.
- **`pos`** : Position dans la mémoire où un processus peut être inséré (calculée par `BestPosition()`).
- **`nbrProcessus`** : Nombre de processus à allouer en mémoire (demandé à l'utilisateur).
- **`i`** : Variable utilisée pour capturer le choix de l'algorithme d'allocation par l'utilisateur.

---

## 1. **`int main()`**

Cette fonction principale initialise le programme, alloue la mémoire, capture les processus et exécute l'algorithme d'allocation choisi par l'utilisateur.

### Étapes principales :
1. **Initialisation de la mémoire :**
   - La mémoire est représentée par une liste chaînée. Un premier bloc de mémoire est alloué en appelant `malloc()` :
     ```c
     head = (node *)malloc(sizeof(node));
     ```
     La taille totale de la mémoire est saisie auprès de l'utilisateur :
     ```c
     printf("entrer La taille total de La memoire : ");
     scanf("%d",&head->taille);
     ```

2. **Saisie des processus :**
   - Le nombre de processus est demandé, puis la fonction `saisieLesProcessusDansLaListe()` est appelée pour capturer les détails de chaque processus :
     ```c
     x = saisieLesProcessusDansLaListe(nbrProcessus);
     ```

3. **Choix de l'algorithme d'allocation :**
   - L'utilisateur choisit entre **First Fit**, **Best Fit** ou **Worst Fit** :
     ```c
     printf(" 1 -> FirstFit \\n 2 -> BestFit \\n 3 -> WorstFit \\n");
     scanf("%d",&i);
     ```
   - Ensuite, l'algorithme correspondant est exécuté en fonction du choix de l'utilisateur :
     ```c
     switch(i)
     {
         case 1: FirstFit(x); break;
         case 2: BestFit(x); break;
         case 3: WorstFit(x); break;
     }
     ```

---

## 2. **`saisieLesProcessusDansLaListe(int nbrProcessus)`**

Cette fonction capture les informations sur les processus qui doivent être alloués en mémoire. Elle remplit la liste chaînée `fl` avec les processus en saisissant leurs tailles.

### Paramètres :
- **`nbrProcessus`** : Le nombre de processus à capturer.

### Retourne :
- La date d'arrivée maximale des processus, qui sera utilisée pour l'allocation de mémoire.

---

## 3. **`BestPosition(int taille)`**

Cette fonction calcule la meilleure position en mémoire pour insérer un processus en fonction de sa taille. Elle retourne l'indice du bloc de mémoire le plus approprié pour accueillir le processus.

### Paramètres :
- **`taille`** : Taille du processus à allouer.

### Retourne :
- **`pos`** : La position (indice) du bloc de mémoire libre dans lequel le processus peut être inséré.

Cette fonction est utilisée par les algorithmes d'allocation pour déterminer le meilleur emplacement pour chaque processus.

---

## 4. **`FirstFit(int dateArriveeMax)`**

Cet algorithme place chaque processus dans le **premier bloc** de mémoire suffisamment grand pour l'accueillir.

### Paramètres :
- **`dateArriveeMax`** : La date d'arrivée maximale des processus.

### Fonctionnement :
- La mémoire est parcourue depuis le début, et dès qu'un bloc de taille suffisante est trouvé, le processus est inséré.
- Si aucun bloc ne convient, le processus est placé en file d'attente jusqu'à ce qu'un espace suffisant se libère.

---

## 5. **`BestFit(int dateArriveeMax)`**

Cet algorithme recherche le **plus petit bloc** de mémoire libre qui est assez grand pour contenir le processus, minimisant ainsi la perte d'espace.

### Paramètres :
- **`dateArriveeMax`** : La date d'arrivée maximale des processus.

### Fonctionnement :
- Tous les blocs libres de mémoire sont parcourus.
- Le bloc de mémoire dont la taille est la plus proche de celle du processus est choisi pour l'allocation.

---

## 6. **`WorstFit(int dateArriveeMax)`**

Cet algorithme place chaque processus dans le **plus grand bloc** de mémoire disponible. Cela laisse généralement de grands espaces libres pour les futurs processus.

### Paramètres :
- **`dateArriveeMax`** : La date d'arrivée maximale des processus.

### Fonctionnement :
- La mémoire est parcourue pour trouver le plus grand bloc libre, et le processus est alloué à cet emplacement.
- Cet algorithme est utile pour éviter trop de petits fragments de mémoire libre.

---

## 7. **`FB_TO_MFB()` et `FB_TO_MMLB()`**

Ces deux fonctions gèrent le déplacement des blocs de mémoire. Elles sont responsables d'insérer un processus dans un bloc de mémoire libre ou de gérer les transitions entre les différents états de la mémoire (occupé ou libre).

### Fonctionnement :
- **`FB_TO_MFB()`** : Insère un processus dans le **premier bloc** de mémoire libre.
- **`FB_TO_MMLB()`** : Insère un processus dans un **bloc de mémoire situé au milieu** de la liste des blocs libres.

Ces fonctions manipulent les listes chaînées des blocs libres et alloués en utilisant les pointeurs `Current_Head`, `Previous_Head`, `Current_FL` et `Previous_FL`.

---

## 8. **`afficher(int t)`**

Cette fonction affiche l'état de la mémoire et des processus après chaque opération d'allocation ou de désallocation.

### Paramètres :
- **`t`** : Le temps actuel (affiché à côté des informations du processus).

### Fonctionnement :
- La fonction parcourt la liste chaînée des blocs mémoire et affiche pour chaque bloc si celui-ci est libre ou occupé, avec les informations sur le processus qui l'occupe, s'il y a lieu.

---

## Compilation et Exécution

1. **Compilation** :
   ```bash
   gcc main.c -o gestion_memoire
   ```

2. **Exécution** :
   ```bash
   ./gestion_memoire
   ```

Lors de l'exécution, l'utilisateur doit fournir la taille de la mémoire et les détails des processus. Ensuite, il choisit l'algorithme d'allocation et observe comment les processus sont placés en mémoire.
