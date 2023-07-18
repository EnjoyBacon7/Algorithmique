#include <stdio.h>  // Ajout de la bibliothèque qui définit les fonctions d'entrées/sorties (printf, scanf, ...)

// Fonction principale executée automatiquement
int main(void) {

    // Déclaration de la variable de l'exercice
    char monChar;

    // On demande et on récupère la valeur entrée par l'utilisateur
    printf("Veuillez entrer un entier : ");
    // monChar est un caractère, mais pour cet exo on va le traiter comme un entier. Ca va permettre de comprendre comment sont
    // stockés les caractères en mémoire. On va donc utiliser %d pour le scanf.
    scanf("%d", &monChar);  

    // Maintenant on affiche la valeur entrée par l'utilisateur en l'imprimant en tant que caractère et en tant qu'entier
    // Voir le README pour l'explication de ce qu'il se passe
    printf("Impression en tant qu'entier: %d\nImpression en tant que caractere : %c\n", monChar, monChar);

    return 0;
}

