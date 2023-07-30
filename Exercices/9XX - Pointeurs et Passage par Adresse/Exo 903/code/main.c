#include <stdio.h>

void somme(int x1, int x2, int* somme);

int main() {

    int entier1, entier2;

    printf("Entrez deux entiers a sommer: ");
    scanf("%d %d", &entier1, &entier2);

    int resultat;

    somme(entier1, entier2, &resultat);

    printf("La somme est: %d\n", resultat);

    return 0;
}

void somme(int x1, int x2, int* resultat) {

    *resultat = x1 + x2;
}