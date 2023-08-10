#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char phrase1[100];
    char phrase2[100];

    printf("Entrez une phrase : ");
    gets(phrase1);

    printf("Entrez une deuxieme phrase : ");
    gets(phrase2);

    char* phraseAllouee;
    int taille = strlen(phrase1) + strlen(phrase2);
    phraseAllouee = (char*)malloc((taille + 1) * sizeof(char));

    strcpy(phraseAllouee, phrase1);
    strcat(phraseAllouee, phrase2);

    printf("La phrase concatenee allouee est : %s\n", phraseAllouee);
    printf("Dont la taille est : %d\n", taille);

    free(phraseAllouee);

    return 0;
}