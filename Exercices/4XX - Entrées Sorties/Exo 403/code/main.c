#include <stdio.h>

int main() {

    char monChar;

    printf("Entrez un caractère en minuscule : ");
    scanf("%c", &monChar);

    // Vérifier si le caractère est une minuscule (donc entre 'a' et 'z')
    if (monChar >= 'a' && monChar <= 'z') { // Blindage (vérification) de la valeur
        // Soustraire la différence entre une majuscule et une minuscule pour effectuer le changement
        char majChar = monChar - ('a' - 'A');
        // Affichage du résultat
        printf("Le caractère en majuscule est : %c\n", majChar);
    } else {    // Si le caractère n'est pas une minuscule, afficher un message d'erreur au lieu de calculer
        printf("Le caractère entré n'est pas une minuscule.\n");
    }

    return 0;
}
