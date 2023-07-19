#include <stdio.h>

int main()
{

    int saisie;

    printf("Entrez un entier: ");
    scanf("%d", &saisie);

    int reponse = 0;

    if (saisie % 5 == 0)
        reponse += 1;
    if (saisie >= 3)
        reponse += 2;

    if (reponse == 1)
        printf("%d est un multiple de 5 seulement.\n", saisie);
    else if (reponse == 2)
        printf("%d est superieur ou egal a 3 seulement.\n", saisie);
    else if (reponse == 3)
        printf("%d est un multiple de 5 et superieur ou egal a 3.\n", saisie);
    else
        printf("%d n'est ni un multiple de 5 ni superieur ou egal a 3.\n", saisie);
}