#include <stdio.h>

int main() {

    int ent1, ent2, ent3;

    printf("Entrez trois entiers séparés par un espace : ");
    scanf("%d %d %d", &ent1, &ent2, &ent3);

    if(ent1 == ent2 && ent1 == ent3) {
        printf("Une seule valeur\n");
    }
    else if(ent1 != ent2 && ent1 != ent3 && ent2 != ent3) {
        printf("Trois valeurs differentes\n");
    }
    else {
        printf("Deux valeurs differentes\n");
    }

    return 0;
}