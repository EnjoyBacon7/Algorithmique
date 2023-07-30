#include <stdio.h>

void ssprgrm(int x1, int x2);

int main() {

    int  val1, val2;

    printf("Entrez le premier entier: ");
    scanf("%d", &val1);
    printf("Entrez le deuxième entier: ");
    scanf("%d", &val2);

    printf("Les deux entiers entres sont donc (dans le main): %d et %d\n", val1, val2);

    ssprgrm(val1, val2);

    printf("Les deux entiers entres sont donc (apres le sous-programme): %d et %d\n", val1, val2);

    return 0;
}


void ssprgrm(int x1, int x2) {

    printf("Les deux entiers dans le sous-programme sont: %d et %d\n", x1, x2);

    x1 += 10;

    printf("Les deux entiers modifiés dans le sous-programme sont: %d et %d\n", x1, x2);
}