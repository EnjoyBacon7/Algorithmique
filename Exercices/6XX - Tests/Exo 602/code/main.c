#include <stdio.h>

int main() {

    int ent1, ent2, ent3;

    printf("Entrez trois entiers séparés par un espace : ");
    scanf("%d %d %d", &ent1, &ent2, &ent3);

    if(ent1 == ent2 && ent1 == ent3) {
        printf("Une seule valeur");
    }
    else if(ent1 != ent2 && ent1 != ent3 && ent2 != ent3) {
        printf("Trois valeurs differentes");
    }
    else {
        printf("Deux valeurs defferentes");
    }

    return 0;
}