#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Bonjour\n");

    int annee;
    scanf("%d", &annee);

    printf("%d", annee);
    if (annee == 2021) {
        printf("\nL'annee en cours est %d", annee);
    }

    annee = annee * -1;
    printf("\n%d\n", annee);

    int note1;
    int note2;
    int note3;
    float moyenne;

    scanf("%d", &note1);
    fflush(stdin);
    scanf("%d", &note2);
    fflush(stdin);
    scanf("%d", &note3);

    moyenne = (note1 + note2 + note3)/3;

    printf("%d, %d, %d : %f", note1, note2, note3, moyenne);

    return 0;
}
