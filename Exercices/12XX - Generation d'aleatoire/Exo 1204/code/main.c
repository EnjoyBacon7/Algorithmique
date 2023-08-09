#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplissage(int tab[15][20]);
void compteur(int tab[15][20], int compte[26]);

int main() {

    srand(time(NULL));

    int tab[15][20];
    remplissage(tab);

    printf("Les valeurs du tableau sont :\n");
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }

    int compte[26];
    compteur(tab, compte);

    printf("\nIl y a :\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%d %c\n", compte[i], i + 'a');
    }

    return 0;
}

void remplissage(int tab[15][20]) {

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            tab[i][j] = rand() % ('z' - 'a' + 1) + 'a';
        }
        
    }
}

void compteur(int tab[15][20], int compte[26]) {

    for (int i = 0; i < 26; i++)
    {
        compte[i] = 0;
    }
    
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            compte[tab[i][j] - 'a']++;
        }
        
    }
}