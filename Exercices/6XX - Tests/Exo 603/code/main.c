#include <stdio.h>

int main() {

    int saisie;

    printf("Entrez un entier : ");
    scanf("%d", &saisie);

    if(saisie % 2 == 0) {
        printf("La saisie est paire.\n");
    }else {
        printf("La saisie est impaire.\n");
    }

    return 0;
}