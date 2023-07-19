#include <stdio.h>

int main()
{

    int boucles;

    do {
        printf("Combien de boucles voulez-vous faire (entier positif)? ");
        scanf("%d", &boucles);
    } while (boucles < 0);

    printf("\nBoucle for:\n");
    for (int i = 0; i < boucles; i++) {
        printf("Bienvenue en TP : indice %d\n", i + 1);
    }
    printf("\n");

    printf("Boucle while:\n");
    int i = 0;
    while (i < boucles) {
        printf("Bienvenue en TP : indice %d\n", i + 1);
        i++;
    }
    printf("\n");
}