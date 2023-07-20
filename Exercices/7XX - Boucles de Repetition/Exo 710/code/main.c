#include <stdio.h>

int main() {

    int choixMenu;
    printf("\nChoisissez une forme : ");
    printf("\n1 - Triangle\n");
    printf("2 - Carre\n");
    printf("3 - Sablier\n");
    scanf("%d", &choixMenu);

    int taille;
    printf("\nEntrez la taille voulue: ");
    scanf("%d", &taille);

    if(choixMenu == 1) {
        for(int i = 0; i < taille; i++) {

            for(int j = 0; j < taille - (i + 1); j++) {
                printf(" ");
            }
            for(int j = 0; j < i * 2 + 1; j++) {
                printf("*");
            }
            printf("\n");
        }
        
    } else if(choixMenu == 2) {
        for(int i = 0; i < taille; i++) {
            for(int j = 0; j < taille; j++) {
                printf("*");
            }
            printf("\n");
        }
    } else if(choixMenu == 3) {

        for(int i = 0; i < taille; i++) {

            for(int j = 0; j < i; j++) {
                printf(" ");
            }
            for(int j = 0; j < (taille - (i + 1)) * 2 + 1; j++) {
                printf("*");
            }
            printf("\n");
        }

        for(int i = 0; i < taille; i++) {

            for(int j = 0; j < taille - (i + 1); j++) {
                printf(" ");
            }
            for(int j = 0; j < i * 2 + 1; j++) {
                printf("*");
            }
            printf("\n");
        }

    } else {
        printf("Choix invalide\n");
    }

}