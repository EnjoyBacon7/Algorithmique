#include <stdio.h>

float calculs(int* max, int* min);

int main() {

    int max = 0, min = 0;
    float moyenne;

    moyenne = calculs(&max, &min);

    printf("max = %d\nmin = %d\nmoyenne = %0.2f", max, min, moyenne);

    return 0;
}

float calculs(int* max, int* min) {

    int saisie;
    float somme = 0;
    int nbValeurs = 0;
    while(1) {

        printf("Entrez un entier strictement negatif: ");
        fflush(stdin);
        scanf("%d", &saisie);

        if(saisie <= 0) {

            if(nbValeurs == 0) {
                *max = saisie;
                *min = saisie;
            }

            if(saisie < *min) {*min = saisie;}
            if(saisie > *max) {*max = saisie;}

            somme += saisie;
            nbValeurs++;
        } else {
            break;
        }
    }

    return (somme / nbValeurs);

}