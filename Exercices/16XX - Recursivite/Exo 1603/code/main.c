#include <stdio.h>

int strlongueur(char* chaine, int iteration);

int main() {

    char chaine[300];
    printf("Entrez une chaine de caracteres: ");
    fgets(chaine, 300, stdin);

    int longueur = strlongueur(chaine, 0); 
    printf("La chaine fait %d caracteres.", longueur);

    return 0;
}

int strlongueur(char* chaine, int iteration) {

    if(chaine[iteration] == '\0') {return iteration - 1;}
    strlongueur(chaine, ++iteration);
}