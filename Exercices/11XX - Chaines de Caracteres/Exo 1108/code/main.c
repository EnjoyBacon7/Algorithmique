#include <stdio.h>
#include <string.h>

void saisie(char verbe[25]);
void conjugaison(char verbe[25]);

int main() {

    char verbe[25];
    saisie(verbe);

    conjugaison(verbe);

    return 0;
}

void saisie(char verbe[25]) {

    int taille;

    printf("Entrez un verbe du premier groupe: ");
    fgets(verbe, 25, stdin);
    taille = strlen(verbe);
    verbe[taille - 1] = '\0';

    while(verbe[taille - 2] != 'r' || verbe[taille - 3] != 'e') {

        printf("Il ne s'agit pas d'un verbe du premier groupe. Entrez un nouveau verbe: ");
        fgets(verbe, 25, stdin);
        taille = strlen(verbe);
        verbe[taille - 1] = '\0';
    }
}

void conjugaison(char verbe[25]) {

    verbe[strlen(verbe) - 2] = '\0';
    printf("Voici la conjugaison de ce verbe au present :\n");
    printf("Je %se\n", verbe);
    printf("Tu %ses\n", verbe);
    printf("Il/Elle %se\n", verbe);
    printf("Nous %sons\n", verbe);
    printf("Vous %sez\n", verbe);
    printf("Ils/Elles %sent\n", verbe);
}