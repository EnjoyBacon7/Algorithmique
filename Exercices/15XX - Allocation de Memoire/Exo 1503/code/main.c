#include <stdio.h>
#include <stdlib.h>

float* saisie(int* taille);
void affichage(float* tab, int taille);
void tri(float* tab, int taille);

int main() {

    int taille;
    float* tab = saisie(&taille);

    printf("Tableau initial : \n");
    affichage(tab, taille);

    printf("Tableau trie : \n");
    tri(tab, taille);
    affichage(tab, taille);

    free(tab);

    return 0;
}

float* saisie(int* taille) {

    printf("Entrez la taille du tableau : ");
    scanf("%d", taille);

    float* tab = (float*)malloc(*taille * sizeof(float));

    for (int i = 0; i < *taille; i++)
    {
        printf("Entrez la valeur %d : ", i + 1);
        scanf("%f", &tab[i]);
    }

    return tab;
}

void affichage(float* tab, int taille) {

    for (int i = 0; i < taille; i++)
    {
        printf("Valeur %d : %f\n", i + 1, tab[i]);
    }
}

void tri(float* tab, int taille) {

    float tmp;
    for (int i = 0; i < taille; i++)
    {
        tmp = tab[i];
        for (int j = i + 1; j < taille; j++)
        {
            if (tmp > tab[j])
            {
                tmp = tab[j];
                tab[j] = tab[i];
                tab[i] = tmp;
            }
        }
    }
}