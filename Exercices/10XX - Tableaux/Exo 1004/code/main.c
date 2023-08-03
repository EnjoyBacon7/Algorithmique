#include <stdio.h>

void saisie(float tab[20]);
void affichage(float tab[20]);
void triBulle(float tab[20]);
void triInsertion(float tab[20]);

int main() {

    float tab[20];
    saisie(tab);
    affichage(tab);
    triBulle(tab);
    affichage(tab);
    triInsertion(tab);
    affichage(tab);

    return 0;

}

void saisie(float tab[20]) {
    for(int i = 0; i < 20; i++) {
        printf("Entrez la valeur numero %d: ", i+1);
        fflush(stdin);
        scanf("%f", &tab[i]);
    }
}

void affichage(float tab[20]) {
    for(int i = 0; i < 20; i++) {
        printf("Valeur numero %d: %.2f\n", i+1, tab[i]);
    }
}

void triBulle(float tab[20]) {
    int i, j;
    float temp;
    for(i = 0; i < 20; i++) {
        for(j = 0; j < 20; j++) {
            if(tab[j] > tab[j+1]) {
                temp = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = temp;
            }
        }
    }
}

void triInsertion(float tab[20]) {
    int i, j;
    float temp;
    for(i = 1; i < 20; i++) {
        temp = tab[i];
        j = i;
        while(j > 0 && tab[j-1] > temp) {
            tab[j] = tab[j-1];
            j--;
        }
        tab[j] = temp;
    }
}