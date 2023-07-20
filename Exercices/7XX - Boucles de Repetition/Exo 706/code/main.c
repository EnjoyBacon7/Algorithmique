#include <stdio.h>

int main() {

    int mois;
    printf("Entrez le nombre de mois (pour 30€ a 0.3%%) : ");
    scanf("%d", &mois);

    float solde = 30;
    for(int i = 0; i < mois; i++) {
        solde += solde * 0.3 / 100;
    }

    printf("Solde : %.2f\n", solde);
}