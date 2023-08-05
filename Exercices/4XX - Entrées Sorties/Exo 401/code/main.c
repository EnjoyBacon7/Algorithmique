#include <stdio.h>

int main() {

    printf("Bonjour\n");

    int annee;
    printf("Entrez l'annee en cours : ");
    scanf("%d", &annee);
    if (annee == 2021) {
        printf("L'annee en cours est %d\n", annee);
    } else {
        printf("%d\n", annee);
    }

    annee = annee * -1;
    printf("L'opposé est %d\n", annee);

    int note1, note2, note3;
    float moyenne;

    printf("Entrez les trois notes ainsi: 1-2-3\n");
    scanf("%d-%d-%d", &note1, &note2, &note3);

    moyenne = (float)(note1 + note2 + note3) / 3;

    printf("Les notes sont %d, %d et %d\n", note1, note2, note3);
    printf("La moyenne est %.2f\n", moyenne);

    return 0;
}