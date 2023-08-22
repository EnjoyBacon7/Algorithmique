#include <stdio.h>
#include <string.h>

void contraction(char chaine[100], char resultat[5]);
int chaineInChaine(char chaine[100], char sousChaine[20]);

int main() {

    char chaine[100];
    printf("Entrez une chaine principale : ");
    fgets(chaine, 100, stdin);
    chaine[strlen(chaine) - 1] = '\0';

    char contracte[5];
    contraction(chaine, contracte);
    printf("La contraction de la chaine est : %s\n", contracte);

    char sousChaine[20];
    printf("entrez la sous-chaine a chercher : ");
    fgets(sousChaine, 20, stdin);
    sousChaine[strlen(sousChaine) - 1] = '\0';

    int match = chaineInChaine(chaine, sousChaine);
    if(match) {
        printf("La sous-chaine se trouve bien dans la chaine.\n");
    } else {
        printf("La sous-chaine ne se trouve pas dans la chaine.\n");
    }

    return 0;
}

void contraction(char chaine[100], char resultat[5]) {

    int taille = strlen(chaine);

    if(taille < 4) {
        printf("La chaine est trop courte pour etre contractee.\n");
        resultat[0] = '\0';
    }

    resultat[0] = chaine[0];
    resultat[1] = chaine[1];
    resultat[2] = chaine[taille - 2];
    resultat[3] = chaine[taille - 1];
    resultat[4] = '\0';
}

int chaineInChaine(char chaine[100], char sousChaine[20]) {

    int taille = strlen(chaine);
    int match = 0;
    int k = 0;

    for (int i = 0; i < taille; i++)
    {
        if((k == strlen(sousChaine)) && (match == 1)) {
            return 1;
        }

        if(chaine[i] == sousChaine[k]) {
            k++;
            match = 1;
        } else {
            k = 0;
            match = 0;
        }
    }
    return 0;
}