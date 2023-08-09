#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generation1();
void generation2();
void generation3();
void generation4();
void generation5();
void generation6();

int main() {

    srand(time(NULL));

    while(1) {

        printf("\n");
        printf("Menu :\n");
        printf("1. Generation d'un nombre aleatoire\n");
        printf("2. Generation d'un nombre aleatoire entre 0 et une valeur saisie\n");
        printf("3. Generation d'un nombre aleatoire entre 2 valeurs saisies\n");
        printf("4. Generation de plusieurs nombres aleatoires entre 2 valeurs saisies\n");
        printf("5. Generation de plusieurs reels aleatoires entre 0 et 1 (bornes comprises)\n");
        printf("6. Generation de plusieurs reels aleatoires entre -50 et 90 (bornes comprises)\n");
        printf("\n");

        int choix = 0;
        printf("Entrez votre choix : ");
        fflush(stdin);
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            generation1();
            break;
        case 2:
            generation2();
            break;
        case 3:
            generation3();
            break;
        case 4:
            generation4();
            break;
        case 5:
            generation5();
            break;
        case 6:
            generation6();
            break;
        default:
            printf("Choix invalide\n");
            return 0;
        }
    }

    return 0;
}

void generation1() {
    printf("%d\n", rand());
}

void generation2() {

    int max = 0;
    printf("Entrez la valeur maximale : ");
    fflush(stdin);
    scanf("%d", &max);

    printf("%d\n", (rand() % max) + 1);
}

void generation3() {

    int min = 0;
    int max = 0;
    printf("Entrez la valeur minimale : ");
    fflush(stdin);
    scanf("%d", &min);
    printf("Entrez la valeur maximale : ");
    fflush(stdin);
    scanf("%d", &max);

    printf("%d\n", (rand() % (max - min + 1)) + min);
}

void generation4() {

    int min = 0;
    int max = 0;
    printf("Entrez la valeur minimale : ");
    fflush(stdin);
    scanf("%d", &min);
    printf("Entrez la valeur maximale : ");
    fflush(stdin);
    scanf("%d", &max);

    int nb = 0;
    printf("Entrez le nombre de valeurs a generer : ");
    fflush(stdin);
    scanf("%d", &nb);

    for (int i = 0; i < nb; i++)
    {
        printf("%d\n", (rand() % (max - min + 1)) + min);
    }
}

void generation5() {

    int nb = 0;
    printf("Entrez le nombre de valeurs a generer : ");
    fflush(stdin);
    scanf("%d", &nb);

    for (int i = 0; i < nb; i++)
    {
        printf("%f\n", (float)rand() / RAND_MAX);
    }
}

void generation6() {

    int nb = 0;
    printf("Entrez le nombre de valeurs a generer : ");
    fflush(stdin);
    scanf("%d", &nb);

    for (int i = 0; i < nb; i++)
    {
        printf("%f\n", (float)rand() / RAND_MAX * 140 - 50);
    }
}