#include <stdio.h>

int main() {

    int monInt;
    char monChar;
    float monFloat;

    printf("La taille d'un int est de %d octets\n", sizeof(monInt));
    printf("La taille d'un char est de %d octets\n", sizeof(monChar));
    printf("La taille d'un float est de %d octets\n", sizeof(monFloat));
}