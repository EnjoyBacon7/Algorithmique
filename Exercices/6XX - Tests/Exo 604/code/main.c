#include <stdio.h>

int main() {

    char saisie;

    printf("Entrez un caractere a identifier : ");
    scanf("%c", &saisie);

    if(saisie >= 48 && saisie <= 57) {
        printf("La saisie est un chiffre (%c)\n", saisie);
    }
    if(saisie >= 65 && saisie <= 90) {
        printf("La saisie est une lettre majuscule (%c)\n", saisie);
    }
    if (saisie >= 97 && saisie <= 122) {
        printf("La saisie est une lettre minuscule (%c)\n", saisie);
    }

    return 0;
}