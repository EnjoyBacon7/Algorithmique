#include <stdio.h>
#include <math.h>

void airePeri(char type, float* perimetre, float* aire);

int main() {

    float perimetre, aire;
    char type;
    char finir;

    while(1) {

        printf("Entrez la forme voulue (c, r ou t): ");
        fflush(stdin);
        scanf("%c", &type);
        if(type != 't' && type != 'c' && type != 'r') {
            printf("Forme non reconnue\n");
            return 1;
        }
        airePeri(type, &perimetre, &aire);

        printf("Le perimetre est : %.2f\nL'aire est : %.2f\n", perimetre, aire);

        printf("Voulez vous continuer? (y/n) : ");
        fflush(stdin);
        scanf("%c", &finir);
        if(finir == 'n') {
            return 1;
        }
    }

    return 0;
}

void airePeri(char type, float* perimetre, float* aire) {

    if(type == 'c') {

        float rayon;

        printf("Entrez le rayon du cercle: ");
        scanf("%f", &rayon);

        *perimetre = 2 * 3.14 * rayon;

        *aire = 3.14 * pow(rayon, 2);
    }
    else if(type == 'r') {

        float largeur;
        float longueur;

        printf("Entrez la largeur du rectangle: ");
        scanf("%f", &largeur);
        printf("Entrez la longueur du rectangle: ");
        scanf("%f", &longueur);


        *perimetre = 2 * largeur + 2 * longueur;

        *aire = largeur * longueur;
    }
    else if(type == 't') {

        float cote1;
        float cote2;

        printf("Entrez le premier cote de l'angle droit: ");
        scanf("%f", &cote1);
        printf("Entrez le deuxieme cote de l'angle droit: ");
        scanf("%f", &cote2);


        *perimetre = cote1 + cote2 + sqrt(pow(cote1, 2) + pow(cote2, 2));

        *aire = (cote1 * cote2) / 2;
    }
}