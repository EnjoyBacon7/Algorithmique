#include <stdio.h>

int main() {

    int saisie;

    printf("Entrez le nombre a convertir: ");
    scanf("%d", &saisie);

    while (saisie >= 1000) {
        printf("M");
        saisie -= 1000;
    }

    while (saisie >= 900) {
        printf("DCCCC");
        saisie -= 900;
    }

    while (saisie >= 500) {
        printf("D");
        saisie -= 500;
    }

    while (saisie >= 400) {
        printf("CCCC");
        saisie -= 400;
    }

    while (saisie >= 100) {
        printf("C");
        saisie -= 100;
    }

    while (saisie >= 90) {
        printf("LXXXX");
        saisie -= 90;
    }

    while (saisie >= 50) {
        printf("L");
        saisie -= 50;
    }

    while (saisie >= 40) {
        printf("XXXX");
        saisie -= 40;
    }

    while (saisie >= 10) {
        printf("X");
        saisie -= 10;
    }

    while (saisie >= 9) {
        printf("VIIII");
        saisie -= 9;
    }

    while (saisie >= 5) {
        printf("V");
        saisie -= 5;
    }

    while (saisie >= 4) {
        printf("IIII");
        saisie -= 4;
    }

    while (saisie >= 1) {
        printf("I");
        saisie -= 1;
    }

    printf("\n");

    return 0;
}