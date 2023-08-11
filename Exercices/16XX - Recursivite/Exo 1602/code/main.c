#include <stdio.h>
#include <stdlib.h>

int sommeCalcul(int*tab, int taille, int somme, int iteration);

int main() {

    int taille;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &taille);

    int* tab = (int*)malloc(taille * sizeof(int));
    for (int i = 0; i < taille; i++)
    {
        printf("Entrez l'entier n.%d : ", i);
        fflush(stdin);
        scanf("%d", &tab[i]);
    }

    int somme = sommeCalcul(tab, taille, 0, 0);
    
    printf("La somme de tous les elements du tableau est : %d", somme);

    return 0;
}

int sommeCalcul(int* tab, int taille, int somme, int iteration) {

    if (iteration == taille) {return somme;}
    somme += tab[iteration];
    sommeCalcul(tab, taille, somme, ++iteration);
}