#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dinosaure {
    char nom[16];
    char famille[11];
    int disparition;
    char type;
} t_dinosaure;

t_dinosaure* creer();
void afficher(t_dinosaure* dino);
void toutAfficher(t_dinosaure** dinos, int nbDinos);
void rechercher(t_dinosaure** dinos, int nb, int date, char type);

int main() {

    int nbDinos = 0;
    t_dinosaure* dinos[20];

    for (int i = 0; i < 20; i++)
    {
        dinos[i] = creer();
        nbDinos++;
    }
    
    toutAfficher(dinos, nbDinos);

    printf("Entrez une annee de disparition: ");
    int date;
    scanf("%d", &date);

    printf("Entrez un type: ");
    char type;
    fflush(stdin);
    scanf("%c", &type);
    while (type != 'C' && type != 'H' && type != 'O') {
        printf("Erreur: le type doit etre C, H ou O\n");
        printf("Entrez le type du dinosaure: ");
        fflush(stdin);
        scanf("%c", &type);
    }

    rechercher(dinos, nbDinos, date, type);

    for (int i = 0; i < 20; i++)
    {
        free(dinos[i]);
    }    

    return 0;
}

t_dinosaure* creer() {

    t_dinosaure* dino = (t_dinosaure*)malloc(sizeof(t_dinosaure));

    printf("Entrez le nom du dinosaure: ");
    fgets(dino->nom, 16, stdin);
    dino->nom[strlen(dino->nom) - 1] = '\0';

    printf("Entrez la famille du dinosaure: ");
    fgets(dino->famille, 16, stdin);
    dino->famille[strlen(dino->famille) - 1] = '\0';

    printf("Entrez l'annee de disparition du dinosaure: ");
    fflush(stdin);
    scanf("%d", &dino->disparition);

    printf("Entrez le type du dinosaure: ");
    fflush(stdin);
    scanf("%c", &dino->type);
    
    while (dino->type != 'C' && dino->type != 'H' && dino->type != 'O') {
        printf("Erreur: le type doit etre C, H ou O\n");
        printf("Entrez le type du dinosaure: ");
        fflush(stdin);
        scanf("%c", &dino->type);
    }
    fflush(stdin);

    return dino;
}

void afficher(t_dinosaure* dino) {

    printf("Nom: %s\n", dino->nom);
    printf("Famille: %s\n", dino->famille);
    printf("Annee de disparition: %d\n", dino->disparition);
    printf("Type: %c\n", dino->type);
}

void toutAfficher(t_dinosaure** dinos, int nbDinos) {

    for (int i = 0; i < nbDinos; i++) {
        afficher(dinos[i]);
        printf("\n");
    }
}

void rechercher(t_dinosaure** dinos, int nb, int date, char type) {

    int trouve = 0;

    for (int i = 0; i < nb; i++) {
        if (dinos[i]->disparition == date && dinos[i]->type == type) {
            afficher(dinos[i]);
            printf("\n");
            trouve = 1;
        }
    }    

    if (!trouve) {
        printf("Aucun dinosaure trouve\n");
    }
}