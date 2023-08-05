#include <stdio.h>
#include <string.h>

int main() {

    char chaine1[50];
    char chaine2[50];

    printf("Entrez la premiere chaine: ");
    fflush(stdin);
    gets(chaine1);

    printf("Entrez la deuxieme chaine: ");
    fflush(stdin);
    gets(chaine2);

    int i = 0;
    while(1) {
        if(chaine1[i] < chaine2[i]) {
            printf("La premiere chaine est avant la deuxieme chaine dans l'ordre alphabetique (version 1)\n");
            break;
        } else if(chaine1[i] > chaine2[i]) {
            printf("La deuxieme chaine est avant la premiere chaine dans l'ordre alphabetique (version 1)\n");
            break;
        } else if(chaine1[i] == '\0' && chaine2[i] == '\0') {
            printf("Les chaines sont identiques (version 1)\n");
            break;
        }
        i++;
    }

    int cmp = strcmp(chaine1, chaine2);
    if(cmp < 0) {
        printf("La premiere chaine est avant la deuxieme chaine dans l'ordre alphabetique (version 2)\n");
    } else if(cmp > 0) {
        printf("La deuxieme chaine est avant la premiere chaine dans l'ordre alphabetique (version 2)\n");
    } else {
        printf("Les chaines sont identiques (version 2)\n");
    }

    return 0;
}