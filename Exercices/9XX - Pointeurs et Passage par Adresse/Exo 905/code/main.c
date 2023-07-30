#include <stdio.h>

float saisieDonnees(int* id, float* prixHT, int* TVA);

int main() {

    int id, TVA;
    float prixHT, prixTTC;

    prixTTC = saisieDonnees(&id, &prixHT, &TVA);

    printf("id : %d\nTVA : %d%%\nprixHT : %.2f\nprixTCC : %.2f\n", id, TVA, prixHT, prixTTC);

    return 0;
}

float saisieDonnees(int* id, float* prixHT, int* TVA) {

    printf("Entrez l'identifiant du produit: ");
    scanf("%d", id);
    printf("Entrez le prix HT du produit: ");
    scanf("%f", prixHT);
    printf("Entrez le taux de TVA du produit en pourcentage: ");
    scanf("%d", TVA);

    return (*prixHT / 100) * *TVA;
}