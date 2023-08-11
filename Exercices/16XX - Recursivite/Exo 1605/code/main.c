#include <stdio.h>

int puissanceCalcul(int nb, int puissance, int resultat, int iteration);

int main() {

    int nb, puissance;
    printf("Entrez le nombre : ");
    scanf("%d", &nb);

    printf("Entrez la puissance : ");
    fflush(stdin);
    scanf("%d", &puissance);

    int resultat = puissanceCalcul(nb, puissance, 1, 0);

    printf("Le resultat est : %d", resultat);

    return 0;
}

int puissanceCalcul(int nb, int puissance, int resultat, int iteration) {

    if (iteration == puissance) {return resultat;}
    return puissanceCalcul(nb, puissance, resultat * nb, ++iteration);
}