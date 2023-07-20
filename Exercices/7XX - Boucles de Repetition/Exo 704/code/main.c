#include <stdio.h>

int main() {
    
    int fin = 0;

    int nbSaisies;
    int total;
    int saisie;

    while(!fin) {

        nbSaisies = 0;
        total = 0;

        while (1) {
            printf("Entrez une valeur : ");
            scanf("%d", &saisie);

            if (saisie < 0) break;

            nbSaisies++;
            total += saisie;
        }

        if (nbSaisies > 0) {
            float moyenne = (float)(total) / nbSaisies;
            printf("Nombre de saisies : %d\n", nbSaisies);
            printf("Total : %d\n", total);
            printf("Moyenne : %.2f\n", moyenne);
        } else {
            printf("Il n'y a pas de saisies.\n");
        }

        printf("Voulez-vous recommencer ? (0/1) : ");
        scanf("%d", &fin);
        fin = !fin;

    }

    return 0;
}
