#include <stdio.h>
#include <stdlib.h>
#include <time.h>   

int generation1();
int generation2();

int main() {

    srand(time(NULL));

    int nbGenere = generation2();
    int nbEssai = 0;
    int nbSaisi = 0;

    while (nbSaisi != nbGenere) {
        printf("Essai numero %d\n", nbEssai + 1);
        printf("Saisir un nombre entre 1 et 200 : ");
        fflush(stdin);
        scanf("%d", &nbSaisi);
        nbEssai++;
        if (nbSaisi > nbGenere) {
            printf("C'est moins !\n");
        } else if (nbSaisi < nbGenere) {
            printf("C'est plus !\n");
        } else {
            printf("\nBravo ! Le nombre etait bien %d\n", nbGenere);
            printf("Vous avez trouve en %d essai(s)\n", nbEssai);
        }
        printf("\n");
    }

    return 0;
}

int generation1() {
    return rand();
}

int generation2() {
    return (rand() % 200) + 1;
}