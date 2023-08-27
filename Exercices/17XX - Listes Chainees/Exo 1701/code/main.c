#include <stdio.h>
#include <stdlib.h>

typedef struct maillon {
    float valeur;
    struct maillon* suivant;
} t_maillon;

t_maillon* creer_maillon();
void afficher_maillon(t_maillon* maillon);
void affichage_recursif(t_maillon* maillon);

int main() {

    t_maillon* liste[10];

    liste[0] = creer_maillon();
    for (int i = 1; i < 10; i++) {
        liste[i] = creer_maillon();
        liste[i-1]->suivant = liste[i];
    }

    affichage_recursif(liste[0]);

    for(int i = 0; i < 10; i++) {
        free(liste[i]);
    }

    return 0;
}

t_maillon* creer_maillon() {
    t_maillon* maillon = (t_maillon*)malloc(sizeof(t_maillon));
    printf("Entrez la valeur du nouveau maillon: ");
    scanf("%f", &maillon->valeur);
    maillon->suivant = NULL;
    return maillon;
}

void afficher_maillon(t_maillon* maillon) {
    printf("Maillon: %f\n", maillon->valeur);
}

void affichage_recursif(t_maillon* maillon) {
    if (maillon != NULL) {
        afficher_maillon(maillon);
        affichage_recursif(maillon->suivant);
    }
}