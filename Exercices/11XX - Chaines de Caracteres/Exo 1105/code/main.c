#include <stdio.h>
#include <string.h>

void remplissage(char chaines[10][100]);
int recherche(char chaines[10][100], char mot[20]);

int main() {

    char chaines[10][100];
    remplissage(chaines);

    char mot[20];
    printf("Entrez le mot a identifier : ");
    fgets(mot, 20, stdin);
    mot[strlen(mot) - 1] = '\0';
    int trouve = recherche(chaines, mot);

    (trouve)? printf("Ce mot se trouve dans les chaines\n"): printf("Ce mot ne se trouve pas dans les chaines\n");

    return 0;
}

void remplissage(char chaines[10][100]) {

    for (int i = 0; i < 10; i++)
    {
        printf("Entrez la chaine de caracteres n.%d: ", i + 1);
        fgets(chaines[i], 100, stdin);
    }  
}

int recherche(char chaines[10][100], char mot[20]) {

    // Declaration d'une chaine temporaire pour stocker le mot traité à un moment donné
    char tmp[20];
    int j, k;

    // Boucle de traitement de chaque chaine
    for (int i = 0; i < 10; i++)
    {
        // Boucle de traitement d'une chaine individuelle
        // 'j' indice de parcours de ligne et 'k' indice de parcours de 'tmp'
        j = 0, k = 0;
        while (chaines[i][j] != '\0')
        {
            // Si on ne se trouve pas sur un espace, on ajoute le caractere à la chaine 'tmp'
            if (chaines[i][j] != ' ')
            {
                tmp[k] = chaines[i][j];
                k++;
            } 
            // Si on se trouve sur un espace, on va donc terminer la chaine tmp et comparer le mot avec
            else
            {
                tmp[k] = '\0';
                printf("'%s' -- '%s'\n", tmp, mot);
                if(strcmp(tmp, mot) == 0) {
                    // Si comparaison valide, on rend 1
                    return 1;
                }
                k = 0;
            }
            j++;
        }
        // Comparer le dernier mot car la boucle se termine avant de s'en occuper
        tmp[k - 1] = '\0';
        printf("'%s' -- '%s'\n", tmp, mot);
        if(strcmp(tmp, mot) == 0) {
            return 1;
        }
    }
    // On rend 0 si le mot ne s'y trouve pas
    return 0;
}