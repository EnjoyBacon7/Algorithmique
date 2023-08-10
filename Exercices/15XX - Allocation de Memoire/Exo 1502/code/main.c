#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char** tab = (char**)malloc(10 * sizeof(char*));

    char buf[100];
    for (int i = 0; i < 10; i++)
    {
        printf("Entrez la chaine %d : ", i);
        gets(buf);
        tab[i] = (char*)malloc((strlen(buf) + 1) * sizeof(char));
        strcpy(tab[i], buf);
    }

    printf("Tableau initial : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("Chaine %d : %s\n", i, tab[i]);
    }

    char* tmp;
    for (int i = 0; i < 10; i++)
    {
        tmp = tab[i];
        for (int j = i + 1; j < 10; j++)
        {
            if (strcmp(tmp, tab[j]) > 0)
            {
                tmp = tab[j];
                tab[j] = tab[i];
                tab[i] = tmp;
            }
        }
    }

    printf("Tableau trie : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("Chaine %d : %s\n", i, tab[i]);
    }

    char* unePhrase;

    int taille = 0;
    for (int i = 0; i < 10; i++)
    {
        taille += strlen(tab[i]) + 1;
    }

    unePhrase = (char*)malloc(taille * sizeof(char));

    strcpy(unePhrase, tab[0]);
    for (int i = 1; i < 10; i++)
    {
        strcat(unePhrase, " ");
        strcat(unePhrase, tab[i]);
        free(tab[i]);
    }
    free(tab);

    printf("La phrase : %s\n", unePhrase);
    printf("La taille de la phrase : %d ou %d\n", strlen(unePhrase));

    return 0;
}