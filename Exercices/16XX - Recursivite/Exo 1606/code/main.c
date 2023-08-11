#include <stdio.h>
#include <stdlib.h>

void saisie(float* tab, int taille, int iteration);
void affiche(float* tab, int taille, int iteration);
void tri(float* tab, int debut, int fin);
void fusion(float* tab, int debut, int milieu, int fin);

int main() {

    int taille = 0;
    float* tab = NULL;
    
    printf("Entrez la taille du tableau : ");
    scanf("%d", &taille);

    tab = (float*)malloc(sizeof(float) * taille);

    saisie(tab, taille, 0);
    printf("Tableau non trie :\n");
    affiche(tab, taille, 0);
    tri(tab, 0, taille - 1);
    printf("Tableau trie :\n");
    affiche(tab, taille, 0);

    free(tab);

    return 0;
}

void saisie(float* tab, int taille, int iteration) {

    if(iteration == taille) {return;}

    printf("Entrez le reel n.%d : ", iteration + 1);
    fflush(stdin);
    scanf("%f", &tab[iteration]);

    saisie(tab, taille, ++iteration);
}

void affiche(float* tab, int taille, int iteration) {

    if(iteration == taille) {return;}

    printf("%d - %f\n", iteration + 1, tab[iteration]);
    affiche(tab, taille, ++iteration);
    
}

void tri(float* tab, int debut, int fin) {

    if (debut != fin) {
        tri(tab, debut, debut + (fin - debut) / 2);
        tri(tab, debut + (fin - debut) / 2 + 1, fin);
        
        fusion(tab, debut, debut + (fin - debut) / 2, fin);
    }
}

void fusion(float* tab, int debut, int milieu, int fin) {

    int i = debut;
    int j = milieu + 1;
    int k = 0;

    float* tabTemp = (float*)malloc(sizeof(float) * (fin - debut + 1));

    while (i <= milieu && j <= fin) {
        if (tab[i] < tab[j]) {
            tabTemp[k] = tab[i];
            i++;
        }
        else {
            tabTemp[k] = tab[j];
            j++;
        }
        k++;
    }

    if (i > milieu) {
        for (int l = j; l <= fin; l++) {
            tabTemp[k] = tab[l];
            k++;
        }
    }
    else {
        for (int l = i; l <= milieu; l++) {
            tabTemp[k] = tab[l];
            k++;
        }
    }

    for (int l = debut; l <= fin; l++) {
        tab[l] = tabTemp[l - debut];
    }

    free(tabTemp);
}