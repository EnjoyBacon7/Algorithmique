#include <stdio.h>

int verifChaine1(char chaine1[50]);
int compte(char chaine[50]);

int main() {

    char chaine1[50];
    char chaine2[50];

    printf("Entrez la premiere chaine (un mot): ");
    fflush(stdin);
    scanf("%s", chaine1);
    while(!verifChaine1(chaine1)) {
        printf("La chaine ne doit comporter qu'un seul mot.\n");
        printf("Reessayer: ");
        fflush(stdin);
        scanf("%s", chaine1);
    }

    printf("Entrez la deuxieme chaine de caracteres (plusieurs mots): ");
    fflush(stdin);
    gets(chaine2);

    int nb;
    nb = compte(chaine1);
    printf("La chaine %s comporte %d caracteres\n", chaine1, nb);
    nb = compte(chaine2);
    printf("La chaine %s comporte %d caracteres\n", chaine2, nb);

    return 0;
}

int verifChaine1(char chaine1[50]) {

    for (int i = 0; i < 50; i++)
    {
        if(chaine1[i] == ' ') {
            return 0;
        }
    }
    return 1;
    
}

int compte(char chaine[50]) {

    int i = 0, nb = 0;
    while (chaine[i] != '\0')
    {
        nb++;
        i++;
    }
    return nb++;
}