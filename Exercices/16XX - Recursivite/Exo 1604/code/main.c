#include <stdio.h>

float calculFonction(int n, float Un, int n_max);

int main() {

    int n_max;
    printf("Entrez n : ");
    scanf("%d", &n_max);

    float resultat = calculFonction(0, 7, n_max);

    printf("Le resultat pour n = %d est : %f", n_max, resultat);

    return 0;
}

float calculFonction(int n, float Un, int n_max) {

    if (n_max == n) {return Un;}
    return calculFonction(++n, (3*Un + 2.5), n_max);

}