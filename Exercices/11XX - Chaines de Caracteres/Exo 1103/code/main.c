#include <stdio.h>

void saisie(char chaine[50]);
void comptechars(char chaine[50], int tabCompte[2]);
int compteMots(char chaine[50]);

int main() {

    char chaine[50];
    int tabCompte[2] = {0, 0};

    saisie(chaine);
    comptechars(chaine, tabCompte);
    printf("La chaine %s comporte %d caracteres alphabetiques et %d caracteres numeriques\n", chaine, tabCompte[0], tabCompte[1]);
    printf("La chaine %s comporte %d mots\n", chaine, compteMots(chaine));

    return 0;
}

void saisie(char chaine[50]) {

    printf("Entrez une chaine de caracteres: ");
    fflush(stdin);
    gets(chaine);

}

void comptechars(char chaine[50], int tabCompte[2]) {

    int i = 0;
    while (chaine[i] != '\0')
    {
        if(chaine[i] >= 'a' && chaine[i] <= 'z') {
            tabCompte[0]++;
        } else if(chaine[i] >= '0' && chaine[i] <= '9') {
            tabCompte[1]++;
        }
        i++;
    }
}

int compteMots(char chaine[50]) {

    int nb = 0;
    int i = 0;
    while (chaine[i] != '\0')
    {
        if(chaine[i] == ' ' && chaine[i+1] != ' ') {
            nb++;
            printf("%c ", chaine[i-1]);
        }
        i++;
    }
    nb++;
    return nb; 
}