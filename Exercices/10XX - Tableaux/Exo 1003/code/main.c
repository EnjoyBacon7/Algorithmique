#include <stdio.h>

void remplissage(float tab[10]);
void affichage(float tab[10]);
float initialisation(float tab[10]);
void minMax(float tab[10], float* min, float* max);

int main() {

    float tab[10];
    float min, max;
    float moyenne = initialisation(tab);
    minMax(tab, &min, &max);

    printf("La moyenne est de %.2f\n", moyenne);
    printf("La note minimale est de %.2f\n", min);
    printf("La note maximale est de %.2f\n", max);

    return 0;
}

void remplissage(float tab[10]) {

    for (int i = 0; i < 10; i++)
    {
        printf("Entrez la note numero %d: ", i+1);
        fflush(stdin);
        scanf("%f", &tab[i]);

        if(tab[i] < 0 && tab[i] > 20) {
            printf("Valeur impossible.");
            i--;
        }
    }
    
}

void affichage(float tab[10]) {

    for (int i = 0; i < 10; i++)
    {
        printf("Note numero %d: %.2f\n", i+1, tab[i]);
    }
    
}

float initialisation(float tab[10]) {

    remplissage(tab);
    affichage(tab);
    
    float moyenne = 0;
    for(int i = 0; i < 10; i++) {
        moyenne += tab[i];
    }
    moyenne /= 10;

    return moyenne;

}

void minMax(float tab[10], float* min, float* max) {

    *min = tab[0];
    *max = tab[0];

    for(int i = 0; i < 10; i++) {
        if(tab[i] < *min) {
            *min = tab[i];
        }
        if(tab[i] > *max) {
            *max = tab[i];
        }
    }

}
// Demander de retourner le min et le max dans la fonction minMax est impossible car on ne peut retourner qu'une seule valeur.
// On ne peut pas non plus retourner de tableau. Il faut donc passer par des pointeurs.