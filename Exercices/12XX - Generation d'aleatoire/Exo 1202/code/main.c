#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remplissage(int tab[20]);
void compte(int tab[20], int* mult10, int* inf100, int* pourcent);

int main() {

    srand(time(NULL));

    int tab[20];
    remplissage(tab);

    int mult10 = 0;
    int inf100 = 0;
    int pourcent = 0;
    compte(tab, &mult10, &inf100, &pourcent);

    printf("Les valeurs du tableau sont :\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d\n", tab[i]);
    }
    printf("\n");

    printf("Il y a %d valeurs multiples de 10\n", mult10);
    printf("Il y a %d valeurs inferieures a 100\n", inf100);
    printf("Il y a %d pourcent de valeurs multiples de 3\n", pourcent);

    return 0;
}

void remplissage(int tab[20]) {

    for (int i = 0; i < 20; i++)
    {
        tab[i] = -1;
    }
    
    int done = 0;
    for (int i = 0; i < 20; i++)
    {
        done = 0;
        while (!done)
        {
            done = 1;
            tab[i] = rand() % 200;
            for (int j = 0; j < 20; j++)
            {
                if (tab[i] == tab[j] && i != j)
                {
                    done = 0;
                }
            }
        }
    }    
}

void compte(int tab[20], int* mult10, int* inf100, int* pourcent) {

    int comptePourcent = 0;
    for (int i = 0; i < 20; i++)
    {
        if (tab[i] % 10 == 0)
        {
            *mult10 += 1;
        }
        if (tab[i] < 100)
        {
            *inf100 += 1;
        }
        if (tab[i] % 3 == 0)
        {
            comptePourcent++;
        }
    }
    *pourcent = comptePourcent * 100 / 20;
}