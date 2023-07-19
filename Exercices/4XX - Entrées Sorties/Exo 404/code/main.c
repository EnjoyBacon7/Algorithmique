#include <stdio.h>

int main() {

    int entier;

    printf("Entrez un entier: ");
    scanf("%d", &entier);

    int carre = entier * entier;

    printf("Le carré de %d est %d\n", entier, carre);
}