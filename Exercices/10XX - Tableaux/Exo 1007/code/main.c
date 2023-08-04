// Taille du tableau non spécifiée. Tableau de 10 utilisé. Le tab[3][4][2] de l'énoncé n'est pas logique ici.

#include <stdio.h>

char saisie();
void affichage(char tab[10]);
int occurrences(char tab[10], char* c);

int main() {

    char tab[10];
    for (int i = 0; i < 10; i++)
    {
        tab[i] = saisie();
    }
    affichage(tab);

    char c;
    int occ = occurrences(tab, &c);
    printf("Le caractere %c apparait %d fois dans le tableau.\n", c, occ);

    return 0;
}

char saisie() {

    char c;
    printf("Entrez un caractere: ");
    fflush(stdin);
    scanf("%c", &c);
    while (!(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'))
    {
        printf("Erreur: le caractere doit etre une lettre ou un chiffre.\n");
        printf("Entrez un caractere: ");
        fflush(stdin);
        scanf("%c", &c);
    }

    return c;

}

void affichage(char tab[10]) {

    for (int i = 0; i < 10; i++)
    {
        printf("%c ", tab[i]);
    }
    printf("\n");
    
}

int occurrences(char tab[10], char* c) {

    printf("Entrez un caractere: ");
    fflush(stdin);
    scanf("%c", c);

    int occ = 0;
    for (int i = 0; i < 10; i++)
    {
        if (tab[i] == *c)
        {
            occ++;
        }
    }
    return occ;
}