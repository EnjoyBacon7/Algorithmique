#include <stdio.h>

// Code explicatif d'un affichage de forme

int main() {

    /// Demander taille à l'utilisateur
    
    // La phase facile de l'exo. Il suffit de faire un scanf pour demander la taille du carre à l'utilis
    
    int choixTaille;
    printf("Indiquez la taille du carre: ");
    scanf("%d", &choixTaille);
    printf("\n");
    
    /// Affichage d'un carre simple
    
    // Maintenant que l'on sait demander la taille de notre carre, il faut l'afficher!
    // Pour dessiner une figure avec des etoiles, on peut:
    
    printf("***\n***\n***");
    
    
    printf("\n\n");
    // ou:
    
    for (int i = 0; i < 3; i++) {
        printf("***\n");
    }
    
    
    printf("\n\n");

    // Ces deux premieres methodes ont le désavantage de devenir très compliquées a mesure que le carre devient grand et de ne pas etre flexible par rapport à un choix de l'utilisateur (ex: Je ne peux pas changer la taille de ces carres avec choixTaille). On va donc implémenter une inception de boucle, dans lesquelles les deux variables vont jouer le role de coordonnées x et y. (forme à deux dimensions). Ici, un carre a 4 cotes egaux, donc la hauteur est la meme que la largeur. Je peux utiliser choixTaille pour limite de x et de y
    
    printf("Affichage correct:\n\n");
    // Première boucle avec la variable y. Je vais donc mettre tout ce que je veux afficher par ligne et revenir à la ligne
    for (int y = 0; y < choixTaille; y++) {
        
        // Deuxième boucle avec la variable x. Je vais mettre ici ce qu'il faut afficher par colonne
        for (int x = 0; x < choixTaille; x++) {
            
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
