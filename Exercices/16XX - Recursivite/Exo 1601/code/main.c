#include <stdio.h>

void saisieRecursive(float* tab, int iteration);
void affichageRecursif(float* tab, int iteration);

int main() {

    float tab[20];
    saisieRecursive(tab, 0);

    affichageRecursif(tab, 0);

    return 0;
}

void saisieRecursive(float* tab, int iteration) {

    if(iteration == 20) {return;}

    printf("Entrez le reel n.%d : ", iteration + 1);
    fflush(stdin);
    scanf("%f", &tab[iteration]);

    saisieRecursive(tab, ++iteration);

}

void affichageRecursif(float* tab, int iteration) {

    if(iteration == 20) {return;}

    printf("%d - %f\n", iteration + 1, tab[iteration]);

    affichageRecursif(tab, ++iteration);
}