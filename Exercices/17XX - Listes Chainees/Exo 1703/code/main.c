#include <stdio.h>
#include <stdlib.h>

typedef struct maillon {

    char caractere;

    struct maillon* precedent;
    struct maillon* suivant;
} t_maillon;

int menu();
t_maillon* saisie();
void affichage_recursif(t_maillon* maillon);
void ajout_maillon(t_maillon** chaine, t_maillon* nouveauMaillon);
void suppression(t_maillon* maillon);

int main() {

    int choix;
    t_maillon* tete = NULL;
    while(1) {
            
        choix = menu();
        switch (choix)
        {
        case 1:
            ajout_maillon(&tete, saisie());
            break;
        case 2:
            affichage_recursif(tete);
            break;
        case 3:
            suppression(tete);
            break;
        case 4:
            liberation(tete);
            return 0;

        default:
            printf("Entrez non comprise.\n");
        }
    }

    liberation(tete);
    return 0;
}

int menu() {
    int choix;
    printf("\nMenu :\n");
    printf("1. Ajouter un element a la chaine\n");
    printf("2. Afficher la chaine\n");
    printf("3. Supprimer une lettre de la chaine\n");
    printf("4. Quitter\n");
    printf("Choix : ");
    scanf("%d", &choix);
    fflush(stdin);
    printf("\n");
    
    return choix;
}

t_maillon* saisie() {

    t_maillon* nouveauMaillon = (t_maillon*)malloc(sizeof(t_maillon));

    printf("Entrez le caractere : ");
    scanf("%c", &nouveauMaillon->caractere);
    fflush(stdin);
    nouveauMaillon->precedent = NULL;
    nouveauMaillon->suivant = NULL;
    return nouveauMaillon;
}

void affichage_recursif(t_maillon* maillon) {
    if(maillon != NULL) {
        printf("%c ", maillon->caractere);

        affichage_recursif(maillon->suivant);
    } else {
        printf("\n");
    }
}

void ajout_maillon(t_maillon** chaine, t_maillon* nouveauMaillon) {

    if (*chaine == NULL) {
        (*chaine) = nouveauMaillon;
        return;
    }

    nouveauMaillon->suivant = (*chaine);
    (*chaine)->precedent = nouveauMaillon;
    (*chaine) = nouveauMaillon;
}

void suppression(t_maillon* maillon) {

    printf("Entrez le caractere a supprimer : ");
    char caractere = getchar();
    fflush(stdin);

    while(maillon) {
        if(maillon->caractere == caractere) {
            if(maillon->precedent != NULL) {
                maillon->precedent->suivant = maillon->suivant;
            }
            if(maillon->suivant != NULL) {
                maillon->suivant->precedent = maillon->precedent;
            }
            free(maillon);
        }
        maillon = maillon->suivant;
    }

}

void liberation(t_maillon* maillon) {

    if(maillon != NULL) {
        liberation(maillon->suivant);
        free(maillon);
    }
}