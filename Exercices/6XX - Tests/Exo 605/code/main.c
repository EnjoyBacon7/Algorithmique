#include <stdio.h>

int main() {

    int saisie;

    printf("Veuillez entrer un entier : ");
    scanf("%d", &saisie);

    if(saisie > 0) {
        printf("(if normal) La saisie est positive.\n");
    }
    else {
        printf("(if normal) La saisie n'est pas positive.\n");
    }

    (saisie > 0)? printf("(if condense) La saisie est positive.\n") : printf("(if condense) La saisie n'est pas positive.\n");

    return 0;
}