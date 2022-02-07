//
//  main.c
//  assietes chainees
//
//  Created by Camille Bizeul on 02/07/2022.
//

// Petit bug, si l'astérisk et le hashtag sont au même endroit, ils sont affichés tout à gauche. (pcq je fais un -1 qqpart et du coup il essaie de faire une boucle -1 fois et c'est nul)

// Bibliothèques requises
#include <stdio.h>  // STanDard Input Output (scanf, printf, etc...)
#include <stdlib.h> // STanDard LIBrary (malloc + exit)

// Structure de la file
struct file {
    char fileElements[50];      // Tableau qui contient toutes les valeurs qui peuvent etre stockées dans la file
    int indiceAjout;            // Indice qui garde en mémoire là ou le prochain élément à ajouter sera ajouté dans le tableau ci-dessus
    int indiceRetrait;          // Indice qui garde en mémoire l'emplacement du plus ancien élément dans la file (principe First In First Out)
};

// Prototypes des fonctions
/// Les prototypes sont la "définition" des fonctions. Ils permettent aux programme de les utiliser (les fonctions).
/// Attention! Ces prototypes doivent etre en haut du code (comme ici) ou dans un fichier header (.h) séparé
/// Note que les fonctions ont (pour la plupart) le meme parametre: "struct file* fileStruct". Celui-ci me permet d'avoir accès à l'emplacement memoire de la structure qui m'interesse où que je sois dans mon programme
int estPleine(struct file* fileStruct);
int estVide(struct file* fileStruct);
int min(int a, int b);
int max(int a, int b);
void enfile10(struct file* fileStruct);
void defile(struct file* fileStruct);
void visualiser(struct file* fileStruct);
void menu(struct file* fileStruct);

// ------------------------------------------------------------
// Le main, le fameux
int main() {
    
    struct file* fileStruct;                    // Déclaration d'un pointeur sur une instance de la structure plus haut
    fileStruct = malloc(sizeof(struct file));   // Allocation dynamique de mémoire à ca pointeur. Ici, on calcule et alloue la mémoire strictement necessaire afin de ne pas gaspiller.
    fileStruct->indiceAjout = 0;                // Pendant tout l'exercice, il s'agit d'un pointeur. On utilise donc des fleches: '->'
    fileStruct->indiceRetrait = 0;
    
    menu(fileStruct);                           // Démarrage du programme. Vroom
    return 0;
}
// ------------------------------------------------------------

// Fonction menu qui permet a l'utilisateur de manipuler la file (elle se répète tant que l'on entre pas '4')
void menu(struct file* fileStruct) {
    
    int choix = 0;
    
    printf("\n1: Add 10 elements to \"file\"\n2: Get element out of \"file\"\n3: Visualize \"file\"\n4: Quit\n\n"); // Joli printf explicatif
    fflush(stdin);                  // Petit probleme de scanf sans le fflush. Descend en bas de page pour l'explication
    scanf("%d", &choix);            // Si tu ne comprend pas ce que fait ce scanf, tu as beauucoup de retard
    
    // Ici, une chaine de if, else if me permet d'agir en fonction de ce que demande l'utilisateur.
    /// Les plus futés d'entre vous auront pensé au switch case. Oui, j'aurais pu. Mais c'est physico-chimiquement impossible de réussir un switch-case du premier coup sans regarder la doc. J'en suis convaincu.
    /// Note aussi que je n'ai pas mis d'accolades sur les if, else if. Je peux faire cela car il n'y a qu'une seule opération à l'intérieur de ceux-ci, et seulement pour cette raison
    if (choix == 1)
        enfile10(fileStruct);
    else if (choix == 2)
        defile(fileStruct);
    else if (choix == 3)
        visualiser(fileStruct);
    else if (choix == 4)
        exit(0);
    // Je traite le cas ou l'entrée n'est pas prise en compte au dessus...
    else
        printf("\nThat isn't an interpretable input\n");
    // ...et je relance le menu pour laisser l'utilisateur continuer
    menu(fileStruct);
    
}

// ------------------------------------------------------------

// Vérifie si la file est vide
int estVide(struct file* fileStruct) {
    // Je profite du fait que si les indices d'ajout et de retrait sont égaux, cela veut forcément dire que l'indice de retrait a rattrapé l'indice d'ajout -> la file est vide (note encore l'absence d'accolade)
    if (fileStruct->indiceAjout == fileStruct->indiceRetrait)
        return 1;
    // Si mon if n'est pas vérifié, soit: la file n'est pas vide, je retourne 0
    return 0;
}

// Vérifie si la file est pleine
int estPleine(struct file* fileStruct) {
    // Cette fois-ci je ne peux pas douiller comme au-dessus. Il faut que je traite tous les cas.
    /// Le premier cas consiste à vérifier si la case après celle sur laquelle pointe l'indice d'Ajout est celle sur laquelle point l'indice de retrait. Cette condition vérifiée veut dire que tous les éléments sont pris et que je ne peux pas en rajouter: la file est pleine.
    /// Le deuxième cas prend en compte le fait que, une fois à la fin du tableau (car la "file" est quand meme un tableau), la case d'après correspond à la première: on revient au début (on passe de 49, le 50ième élément, à 0, le premier)
    if (((fileStruct->indiceAjout + 1) == (fileStruct->indiceRetrait)) || ((fileStruct->indiceAjout == 49) && fileStruct->indiceRetrait == 0)) {
        return 1;
    }
    // Si mon if n'est pas vérifié, soit: la file n'est pas pleine, je retourne 0
    return 0;
    
}

// ------------------------------------------------------------

// Fonctions min et max qui rendent la valeur minimum et maximum respectivement en parametre
/// Elles sont très simple à comprendre, encore une fois, si tu ne comprends pas, il y a beaucoup de niveau à rattraper
int min(int a, int b) {
    if (a < b)
        return a;
    else if ( b < a)
        return b;
    return 0;
}

int max(int a, int b) {
    if (a < b)
        return b;
    else if (b < a)
        return a;
    return 0;
}

// ------------------------------------------------------------
// Ici on entre dans les fonctions qui gèrent chaque choix que peut faire l'utilisateur


// Fonction demandée par l'exercice. Elle permet d'entrer 10 characteres d'affilée (en entrant '1')
void enfile10(struct file* fileStruct) {
    
    // Boucle for qui se répete 10 fois (donc 10 entrées
    for (int i = 0; i < 10; i++) {
        if (estPleine(fileStruct) == 0){        // On vérifie qu'elle n'est pas pleine (on pourrait écraser des valeurs sinon)
            printf("Enter a character: ");
            fflush(stdin);                      // Encore un fflush (meme raison que ligne 50)
            
            // Ici, le scanf est technique. Il s'agit simplement de stocker l'entrée utilisateur
            /// Je navigue dans le TABLEAU qui se trouve à l'ADRESSE de la STRUCTURE et je cherche l'élément de ce meme tableau qui se trouve à l'INDICE indiceAjout qui se trouve aussi dans ma STRUCTURE
            /// fiou...
            scanf("%c", &fileStruct->fileElements[fileStruct->indiceAjout]);
            
            // On incrémente l'indice d'ajout (on le remet à 0 si il est égal à 49)
            if (fileStruct->indiceAjout == 49)
                fileStruct->indiceAjout = 0;
            else
                fileStruct->indiceAjout++;
        }
        else {                                  // Si ma file est pleine, j'affiche un message d'erreur
            printf("The buffer is full!");
            break;
        }
        // On revient au menu
    }
    
}

// Fonction demandée par l'exercice. Elle permet de faire sortir la plus ancienne valeur (principe First In First Out) (en entrant '2')
/// Tout betement, on fait l'inverse de ce qu'on a fait plus haut, et ca, sans boucle for
void defile(struct file* fileStruct) {
    
    if (estVide(fileStruct) == 0) {             // On check qu'elle n'est pas vide (comment sortir une valeur qui n'existe pas?)
        
        // Ici je récupère le caractère qui se trouve à l'indice de retrait
        printf("\nThe exiting value from \'file\' is: %c\n", fileStruct->fileElements[fileStruct->indiceRetrait]);
        
        // J'efface manuellement la valeur qui s'y trouve
        /// Ceci NE CHANGE EN RIEN LE FONCTIONNEMENT du code. Il permet de mieux comprendre la visualisation (plus bas), mais peut etre ignoré en pratique
        fileStruct->fileElements[fileStruct->indiceRetrait] = '\0';
        
        // Encore une fois, on incrémente l'indice (de retrait cette fois ci) (à 0 si 49)
        if (fileStruct->indiceRetrait == 49)
            fileStruct->indiceRetrait = 0;
        else
            fileStruct->indiceRetrait++;
    }
    else {                                      // Si la file est vide, je l'affiche
        printf("\nThe \'file\' is empty!\n");
    }
    
}

// Petite fonction d'affichage visuel de la file qui permet de ludiquement comprendre ce qu'il se passe concretement. L'asterisk (*) représente la où pointe indiceAjout, et le hashtag (#) indique la ou pointe indiceRetrait. (Le code est un peu compliqué en terme d'algo. Si tu comprends c'est que tu gères... mm moi je comprends pas :)
void visualiser(struct file* fileStruct) {
    
    fflush(stdin);
    printf("\n[ ");                                                 // Affichage du crochet
    for (int i = 0; i < 50; i++) {                                  // Boucle for qui imprime tous les elements du tableau...
        if (fileStruct->fileElements[i] == '\0') {
            printf("'_' ");                                     //...avec des '_' (pour les voir) si ils sont nuls '\0'...
        }
        else {
            printf("'%c' ", fileStruct->fileElements[i]);       //...ou leurs valeursi ils ne le sont pas
        }
    }
    printf("]\n");                                                  // Affichage du dernier crochet
    
    
    // Ici ca se complique
    ///Le but ici est d'afficher un asteisk à l'emplacement de l'indice d'ajout, et un  hashtag à l'emplacement de l'indice de retrait. Pour ca il faut déterminer:
    ///  -lequel arrive en premier
    ///  -le nombre d'espaces avant le premier caractere
    ///  - et le nombre d'espaces entre les deux caracteres
    
    // Ici je calcule la position (en caracteres) des deux icones à partir de la gauche
    /// Il y a 4 caractères qui séparent chaque emplacement: "' '_" Il suffit de multiplier l'indice dans le tableau par l'espacement entres les differents emplacements (4), et rajouter les nombre de caracteres avant la première position (3) pour calculer la position des deux icones
    /// ...
    int ajoutOffset = (4*fileStruct->indiceAjout) + 3;
    int retraitOffset =(4*fileStruct->indiceRetrait) + 3;
    
    // On détermine ensuite lequel des deux indice est le plus petit et le plus grand
    int minValeur = min(ajoutOffset, retraitOffset);
    char minChar;
    int maxValeur = max(ajoutOffset, retraitOffset);
    char maxChar;
    
    // On associe les icones avec l'objet correspondant
    if (minValeur == ajoutOffset) {
        minChar = '*';
        maxChar = '#';
    }
    else {
        minChar = '#';
        maxChar = '*';
    }
    
    // On imprime le nombre d'espaces avant le premier caractère
    for (int i = 0; i < min(ajoutOffset, retraitOffset); i++) {
        printf(" ");
    }
    
    // Le premier caractère
    printf("%c", minChar);
    
    // On imprime le nombre d'espaces entre les deux caractères...
    for (int i = 0; i < maxValeur - minValeur - 1; i++) {
        printf(" ");
    }
    
    //...suivi du deuxième caractère...
    printf("%c\n\n", maxChar);
    
    //...ainsi qu'une légende
    printf("indiceAjout: \'*\'\n");
    printf("indiceRetrait: \'#\'\n");
}

// FFLUSH

//Le role du fflush après (ou avant) les scanf est simple. Lorsqu'une entrée clavier est demandée, l'entrée de l'utilisateur
//est enregistrée dans le "stdin". Or le scanf laisse l'utilisateur taper jusqu'à ce qu'un "\n" ou un "\r" apparaisse. Celui-ci
//indique la fin de la saisie, et le scanf enregistre tout ce qui a été entré AVANT ce "\n". Cela veut dire qu'un scanf()
//consécutif commencera à lire le stdin avec un "\n". Le scanf se termine immédiatement et n'est pas pris en compte. L'interet
//du fflush(stdin) est justement de se débarrasser du "\n" restant dans le stdin, afin que les scanf suivants ne soient pas ignorés,
//voire fassent crash le programme. Le gets() n'a pas ce problème, mais présente des failles de sécurité
