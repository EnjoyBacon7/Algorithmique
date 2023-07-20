#include <stdio.h>

int main() {

    int saisie;
    printf("Entrez jusqu'a quel nombre vous voulez afficher les nombres premiers : ");
    scanf("%d", &saisie);

    for(int i = 2; i <= saisie; i++) {
        int estPremier = 1;
        for(int j = 2; j < i; j++) {
            if (i % j == 0) {
                estPremier = 0;
                break;
            }
        }
        if (estPremier) {
            printf("%d\n", i);
        }
    }
}