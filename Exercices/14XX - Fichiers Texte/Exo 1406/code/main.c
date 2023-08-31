#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date {
    int jour;
    int mois;
    int annee;
}t_date;

typedef struct livre {
    int identifiant;
    char* titre;
    char* auteurs[6];
    char* themes[6];
    float prixHT;
    t_date parution;
}t_livre;

void saisie(t_livre* monLivre);
void saisies(t_livre* bibliotheque[50], int nombre);
void affichage(t_livre* monLivre);
void affichages(t_livre* bibliotheque[50], int nombre);
void sauvegarde(t_livre* bibliotheque[50], int nombre);

int main() {

    t_livre* bibliotheque[50];
    int nombre = 3;
    saisies(bibliotheque, nombre);
    affichages(bibliotheque, nombre);
    sauvegarde(bibliotheque, nombre);

    printf("returning");
    fflush(stdout);
    return 0;
}

void saisie(t_livre* monLivre) {

    char tmp[100];

    printf("Entrez l'identifiant du livre: ");
    scanf("%d", &(monLivre->identifiant));
    fflush(stdin);

    printf("Entrez le titre du livre : ");
    fgets(tmp, 100, stdin);
    tmp[strcspn(tmp, "\n")] = 0;
    monLivre->titre = (char*)malloc(sizeof(char) * (strlen(tmp)+1));
    strcpy(monLivre->titre, tmp);

    printf("Entrez les auteurs du livre (Entrez \"fin\" pour finir l'entrée) :\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Auteur n.%d : ", i + 1);
        fgets(tmp, 100, stdin);
        tmp[strcspn(tmp, "\n")] = 0;
        monLivre->auteurs[i] = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(monLivre->auteurs[i], tmp);

        if(strcmp("fin", tmp) == 0) {
            break;
        }
    }
    monLivre->auteurs[5] = (char*)malloc(sizeof(char) * 4);
    strcpy(monLivre->auteurs[5], "fin");

    printf("Entrez les themes du livre (Entrez \"fin\" pour finir l'entrée) :\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Theme n.%d : ", i + 1);
        fgets(tmp, 100, stdin);
        tmp[strcspn(tmp, "\n")] = 0;
        monLivre->themes[i] = (char*)malloc(sizeof(char) * (strlen(tmp) + 1));
        strcpy(monLivre->themes[i], tmp);

        if(strcmp("fin", tmp) == 0) {
            break;
        }
    }
    monLivre->themes[5] = (char*)malloc(sizeof(char) * 4);
    strcpy(monLivre->themes[5], "fin");

    printf("Entrez le prix hors taxe du livre : ");
    scanf("%f", &(monLivre->prixHT));
    fflush(stdin);

    printf("Entrez la date de parution du livre :\n");
    printf("Jour : ");
    scanf("%d", &(monLivre->parution.jour));
    printf("Mois : ");
    scanf("%d", &(monLivre->parution.mois));
    printf("Annee : ");
    scanf("%d", &(monLivre->parution.annee));
}

void saisies(t_livre** bibliotheque, int nombre) {

    for (int i = 0; i < nombre; i++)
    {
        bibliotheque[i] = (t_livre*)malloc(sizeof(t_livre));
        saisie(bibliotheque[i]);
    }
    
}

void affichage(t_livre* monLivre) {

    printf("------------------\n");
    printf("id : %d\n", monLivre->identifiant);
    printf("titre : %s\n", monLivre->titre);
    printf("auteurs : %s\n", monLivre->auteurs[0]);
    int i = 1;
    while (strcmp(monLivre->auteurs[i], "fin") != 0)
    {
        printf("          %s\n", monLivre->auteurs[i]);
        i++;
    }
    printf("themes : %s\n", monLivre->themes[0]);
    i = 1;
    while (strcmp(monLivre->themes[i], "fin") != 0)
    {
        printf("         %s\n", monLivre->themes[i]);
        i++;
    }

    printf("prix HT : %.2f\n", monLivre->prixHT);
    printf("parution : %d/%d/%d\n", monLivre->parution.jour, monLivre->parution.mois, monLivre->parution.annee);    
}

void affichages(t_livre** bibliotheque, int nombre) {

    for (int i = 0; i < nombre; i++)
    {
        affichage(bibliotheque[i]);
    }
    printf("\n");
    
}

void sauvegarde(t_livre** bibliotheque, int nombre) {

    char nomFichier[50];

    printf("Dans quel fichier faut-il enregistrer les donnees? (Sauvegarder dans un fichier existant l'ecrasera) : ");
    fflush(stdin);
    fgets(nomFichier, 50, stdin);
    nomFichier[strcspn(nomFichier, "\n")] = 0;

    FILE* fp = fopen(nomFichier, "w");
    if(!fp) {
        printf("Erreur lors de l'ouverture/creation du fichier.");
        exit(1);
    }

    int j;
    for (int i = 0; i < nombre; i++)
    {
        fprintf(fp, "%d\n", bibliotheque[i]->identifiant);
        fprintf(fp, "%s\n", bibliotheque[i]->titre);
        j = 0;
        while (strcmp(bibliotheque[i]->auteurs[j], "fin") != 0)
        {
            fprintf(fp, "%s\n", bibliotheque[i]->auteurs[j]);
            j++;
        }
        fprintf(fp, "%s\n", bibliotheque[i]->auteurs[j]);
        j = 0;
        while (strcmp(bibliotheque[i]->themes[j], "fin") != 0)
        {
            fprintf(fp, "%s\n", bibliotheque[i]->themes[j]);
            j++;
        }
        fprintf(fp, "%s\n", bibliotheque[i]->themes[j]);
        fprintf(fp, "%f\n", bibliotheque[i]->prixHT);
        fprintf(fp, "%d/%d/%d\n", bibliotheque[i]->parution.jour, bibliotheque[i]->parution.mois, bibliotheque[i]->parution.annee);
    }
    printf("done");
    fflush(stdout);

    fclose(fp);

    printf("fclosed");
    fflush(stdout);
    
}