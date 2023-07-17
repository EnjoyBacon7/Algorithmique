#include <stdio.h> // Bibliothèque utilisée pour printf()

// On crée une structure appelée structure
struct structure {
    char caractere;     // avec un caractère
    int nombres[15];    // et un tableau de 15 entiers
};

// On crée un alias pour la structure. On peut maintenant utiliser t_struct au lieu de struct structure
typedef struct structure t_struct;
// Habituellement, cette étape est faite dans la structure elle-même, comme suit:

// typedef struct structure {
//     char caractere;
//     int nombres[15];
// } t_struct;

// Mais c'est bien de comprendre ce qu'il se passe derrière le typedef

// Fonction de remplissage de struct
t_struct remplissage(t_struct maStruct) {
    maStruct.caractere = 'a';           // Ce n'est pas précisé dans l'énoncé, on met donc un caractère au hasard
    for (int i = 0; i < 15; i++) {
        maStruct.nombres[i] = i;        // On remplit le tableau avec les nombres de 0 à 14, ce qui n'est pas non plus précisé dans l'énoncé
    }
    return maStruct;
}

// Fonction d'affichage de struct
void afficher(t_struct maStruct) {
    printf("Caractere : %c\n", maStruct.caractere);
    for (int i = 0; i < 15; i++) {
        printf("Nombre %d : %d\n", i, maStruct.nombres[i]);
    }
}

// Fonction principale
int main() {
    t_struct maStruct;                  // Déclaration de la structure
    maStruct = remplissage(maStruct);   // Remplissage de la structure
    afficher(maStruct);                 // Affichage de la structure
    return 0;
}

