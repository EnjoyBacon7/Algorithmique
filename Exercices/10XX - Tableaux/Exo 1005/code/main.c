#include <stdio.h>

void saisie(int tab[10]);
void affichage(int tab[10]);
void triInsertion(int tab[10]);
void recherche(int tab[10], int x);

int main() {

    int tab[10];
    saisie(tab);
    affichage(tab);
    triInsertion(tab);
    affichage(tab);

    int x;
    printf("Entrez l'element a rechercher: \n");
    scanf("%d", &x);
    recherche(tab, x);

    return 0;

}

void saisie(int tab[10]) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Entrez un nombre : ");
        scanf("%d", &tab[i]);
    }
}

void affichage(int tab[10]) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

void triInsertion(int tab[10]) {
    int i, j, tmp;
    for (i = 1; i < 10; i++) {
        tmp = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > tmp) {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = tmp;
    }
}

void recherche(int tab[10], int x) {
    int i;
    for (i = 0; i < 10; i++) {
        if (tab[i] == x) {
            printf("L'element %d est trouve a l'indice %d", x, i);
            return;
        }
    }
    printf("L'element %d n'est pas trouve", x);
}