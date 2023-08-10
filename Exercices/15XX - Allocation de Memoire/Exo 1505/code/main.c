#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "proto.h"

int main() {

    srand(time(NULL));

    int lignes = 0;
    int colonnes = 0;

    int** matrice = allocMatrice(&lignes, &colonnes);
    remplissageMatrice(matrice, lignes, colonnes);
    affichageMatrice(matrice, lignes, colonnes);

    for (int i = 0; i < lignes; i++) {
        free(matrice[i]);
    }

    return 0;
}

int** allocMatrice(int* lignes, int* colonnes) {

    printf("Entrez le nombre de lignes: ");
    scanf("%d", lignes);
    while (*lignes <= 0) {
        printf("Erreur: le nombre de lignes doit etre superieur a 0\n");
        printf("Entrez le nombre de lignes: ");
        scanf("%d", lignes);
    }

    printf("Entrez le nombre de colonnes: ");
    scanf("%d", colonnes);
    while (*colonnes <= 0) {
        printf("Erreur: le nombre de colonnes doit etre superieur a 0\n");
        printf("Entrez le nombre de colonnes: ");
        scanf("%d", colonnes);
    }

    int** matrice = (int**)malloc(*lignes * sizeof(int*));

    for (int i = 0; i < *lignes; i++) {
        matrice[i] = (int*)malloc(*colonnes * sizeof(int));
    }

    return matrice;
}

void remplissageMatrice(int** matrice, int lignes, int colonnes) {

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            matrice[i][j] = rand() % 256;
        }
    }
}

void affichageMatrice(int** matrice, int lignes, int colonnes) {

    printf("\n");

    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}