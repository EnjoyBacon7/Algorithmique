#include <stdio.h>
#include <stdlib.h>

int main()
{
    char lettre;
    printf("Enter a integer: ");
    scanf("%d", &lettre);

    printf("d: %d\n", lettre);
    printf("c: %c\n", lettre);

    printf("Enter a integer (between 97 and 122 this time): ");
    scanf("%d", &lettre);

    printf("d: %d\n", lettre);
    printf("c: %c", lettre);

// Les valeurs permettant d'afficher ces caractères spéciaux sont: 42, 64,  35, 36 respectivement

    return 0;
}
