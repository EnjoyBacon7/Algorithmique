#include <stdio.h>

int carre(int valeur);

int main() {

    int a, b;
    printf("Entrez deux entiers (separes par un espace) : ");
    scanf("%d %d", &a, &b);

    int carre_a = carre(a);
    int carre_b = carre(b);

    printf("%d^2 = %d\n", a, carre_a);
    printf("%d^2 = %d\n", b, carre_b);

}

int carre(int valeur) {
    return valeur * valeur;
}