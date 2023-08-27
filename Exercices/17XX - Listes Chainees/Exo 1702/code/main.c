#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date {
    int jour;
    int mois;
    int annee;
} t_date;

typedef struct voiture {
    char* immatriculation;
    char* marque;
    char* modele;
    int vitesse_max;
    char carburant;

    t_date* date_sortie;

    struct voiture* suivant;
}t_voiture;

t_voiture* creer_voiture();
void affichage_recursif(t_voiture* maillon);
void affichage_marque_recursif(t_voiture* maillon, char* marque);
void suppression(t_voiture** maillon, char* immatriculation);
void menu(int* choix);

int main() {

    t_voiture* tete = NULL;
    t_voiture* tmp_voiture = NULL;
    char tmp_char[100];

    int choix;
    while (1) {
        menu(&choix);

        switch (choix)
        {
        case 1:

            tmp_voiture = creer_voiture();
            if(tete == NULL) {
                tete = tmp_voiture;
            }
            else {
                tmp_voiture->suivant = tete;
                tete = tmp_voiture;
            }
            break;

        case 2:

            affichage_recursif(tete);
            break;

        case 3:

            printf("Entrez la marque: ");
            fgets(tmp_char, 100, stdin);
            printf("\n");
            tmp_char[strcspn(tmp_char, "\n")] = 0;
            affichage_marque_recursif(tete, tmp_char);
            printf("\n");
            break;

        case 4:

            printf("Entrez l'immatriculation: ");
            fgets(tmp_char, 100, stdin);
            tmp_char[strcspn(tmp_char, "\n")] = 0;
            suppression(&tete, tmp_char);
            printf("Fait!\n");
            printf("\n");
            break;

        case 5:

            return 0;
            break;
        
        default:
            printf("Choix invalide!\n");
            printf("\n");
            break;
        }
    }
}

void menu(int* choix) {
    printf("1. Ajouter une voiture\n");
    printf("2. Afficher les voitures\n");
    printf("3. Afficher les voitures d'une marque\n");
    printf("4. Supprimer une voiture\n");
    printf("5. Quitter\n");
    printf("Choix: ");
    scanf("%d", choix);
    fflush(stdin);
    printf("\n");
}

t_voiture* creer_voiture() {
    t_voiture* voiture = (t_voiture*)malloc(sizeof(t_voiture));
    char tmp[100];

    printf("Entrez l'immatriculation de la voiture: ");
    fgets(tmp, (int)sizeof(tmp), stdin);
    voiture->immatriculation = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
    strcpy(voiture->immatriculation, tmp);
    voiture->immatriculation[strcspn(voiture->immatriculation, "\n")] = 0; // Enleve le \n de la chaine (https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-input/2693826#2693826)

    printf("Entrez la marque de la voiture: ");
    fgets(tmp, (int)sizeof(tmp), stdin);
    voiture->marque = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
    strcpy(voiture->marque, tmp);
    voiture->marque[strcspn(voiture->marque, "\n")] = 0;

    printf("Entrez le modele de la voiture: ");
    fgets(tmp, (int)sizeof(tmp), stdin);
    voiture->modele = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
    strcpy(voiture->modele, tmp);
    voiture->modele[strcspn(voiture->modele, "\n")] = 0;

    printf("Entrez la vitesse max de la voiture: ");
    scanf("%d", &voiture->vitesse_max);
    fflush(stdin);

    printf("Entrez le carburant de la voiture: ");
    scanf("%c", &voiture->carburant);
    fflush(stdin);

    voiture->date_sortie = (t_date*)malloc(sizeof(t_date));
    printf("Entrez la date de sortie de la voiture (jj/mm/aaaa):\n");
    printf("Jour: ");
    scanf("%d", &voiture->date_sortie->jour);
    fflush(stdin);
    printf("Mois: ");
    scanf("%d", &voiture->date_sortie->mois);
    fflush(stdin);
    printf("Annee: ");
    scanf("%d", &voiture->date_sortie->annee);
    fflush(stdin);
    printf("\n");

    voiture->suivant = NULL;

    return voiture;
}

void affichage_recursif(t_voiture* maillon) {
    if(maillon != NULL) {
        printf("Immatriculation: %s\n", maillon->immatriculation);
        printf("Marque: %s\n", maillon->marque);
        printf("Modele: %s\n", maillon->modele);
        printf("Vitesse max: %d\n", maillon->vitesse_max);
        printf("Carburant: %c\n", maillon->carburant);
        printf("Date de sortie: %d/%d/%d\n", maillon->date_sortie->jour, maillon->date_sortie->mois, maillon->date_sortie->annee);
        printf("\n");

        affichage_recursif(maillon->suivant);
    }
}

void affichage_marque_recursif(t_voiture* maillon, char* marque) {
    if(maillon != NULL) {
        if(!strcmp(marque, maillon->marque)) {
            printf("Immatriculation: %s\n", maillon->immatriculation);
        }
        
        affichage_marque_recursif(maillon->suivant, marque);
    }
}

void suppression(t_voiture** maillon, char* immatriculation) {

    t_voiture* tmp = *maillon;
    t_voiture* precedent = NULL;

    while(tmp != NULL) {

        if(strcmp(tmp->immatriculation, immatriculation) == 0) {
            
            if(precedent == NULL) {
                (*maillon) = tmp->suivant;
            } else {
                precedent->suivant = tmp->suivant;
            }

            free(tmp->immatriculation);
            free(tmp->marque);
            free(tmp->modele);
            free(tmp->date_sortie);
            free(tmp);

            return;
        }

        precedent = tmp;
        tmp = tmp->suivant;
    }
}