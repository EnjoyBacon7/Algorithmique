// Gros problème d'énoncé

#include <stdio.h>

void saisie(float tab[20]);
void affichage(float tab[20]);
void triInsertion(float tab[20]);
void recherche(float tab[20], float x);

int main() {

    float tab[20];
    saisie(tab);
    affichage(tab);
    triInsertion(tab);
    affichage(tab);

    float x;
    printf("Entrez l'element a rechercher: ");
    scanf("%f", &x);
    recherche(tab, x);

    return 0;

}

void saisie(float tab[20]) {

    for (int i = 0; i < 20; i++)
    {
        printf("Entrez la valeur numero %d: ", i + 1);
        fflush(stdin);
        scanf("%f", &tab[i]);
    }
    
}

void triInsertion(float tab[20]) {

    int i, j;
    float temp;
    for (i = 1; i < 20; i++)
    {
        temp = tab[i];
        j = i;
        while (j > 0 && tab[j - 1] > temp)
        {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = temp;
    }
}

void recherche(float tab[20], float x) {

    int i;
    for (i = 0; i < 20; i++)
    {
        if (tab[i] == x)
        {
            printf("L'element %f est trouve a l'indice %d", x, i);
            return;
        }
    }
    printf("L'element %f n'est pas trouve", x);
    
}

void affichage(float tab[20]) {

    for (int i = 0; i < 20; i++)
    {
        printf("Valeur numero %d: %.2f\n", i + 1, tab[i]);
    }
    
}