#include <stdio.h>

int main() {

    int tab[13];

    for(int i = 0; i < 13; i++) {
        printf("Entrez l'entier: ");
        fflush(stdin);
        scanf("%d", &tab[i]);
    }

    for(int i = 0; i < 13; i++) {
        printf("Valeur %d : %d\n", i + 1, tab[i]);
    }

    return 0;
}