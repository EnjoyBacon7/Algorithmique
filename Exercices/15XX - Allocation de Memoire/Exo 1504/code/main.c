#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lectureDonnee();
void ecritureMult(int* tab, int taille);

int main() {

    srand(time(NULL));

    int taille = lectureDonnee();
    int* tab = (int*)malloc(taille * sizeof(int));

    for (int i = 0; i < taille; i++) {
        tab[i] = (rand() % 174) - 24;
    }

    FILE* resultat = fopen("resultat.txt", "w");
    for (int i = 0; i < taille; i++) {
        fprintf(resultat, "%d\n", tab[i]);
    }
    fclose(resultat);

    ecritureMult(tab, taille);

    free(tab);

    return 0;
}

int lectureDonnee() {

    int taille;
    FILE* fp = fopen("donnee.txt", "r");
    fscanf(fp, "%d", &taille);
    fclose(fp);

    return taille;
}

void ecritureMult(int* tab, int taille) {

    FILE* mult3 = fopen("mult3.txt", "w");
    FILE* autre = fopen("autres.txt", "w");

    for (int i = 0; i < taille; i++) {

        if (tab[i] % 3 == 0) {
            fprintf(mult3, "%d\n", tab[i]);
        }
        else {
            fprintf(autre, "%d\n", tab[i]);
        }
    }

    fclose(mult3);
    fclose(autre);
}