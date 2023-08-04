#include <stdio.h>

void saise(char mat[4][5]);
void transformation(char mat[4][5]);
void affichage(char mat[4][5]);
void inversion(char mat[4][5]);

int main() {

    char mat[4][5];
    saise(mat);
    affichage(mat);
    transformation(mat);
    affichage(mat);
    inversion(mat);
    affichage(mat);
    return 0;
}

void saise(char mat[4][5]) {

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Entrez un caractere (%d,%d): ", j, i);
            fflush(stdin);
            scanf("%c", &mat[i][j]);
        }
    }
    
}

void transformation(char mat[4][5]) {

    int decalage = 'A' - 'a';
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mat[i][j] >= 'a' && mat[i][j] <= 'z')
            {
                mat[i][j] = mat[i][j] + decalage;
            }
        }
    }
    
}

void affichage(char mat[4][5]) {

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c\t", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void inversion(char mat[4][5]) {

    char tmp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(i > 1){return;}
            tmp = mat[i][j];
            mat[i][j] = mat[4-i-1][5-j-1];
            mat[4-i-1][5-j-1] = tmp;
        }
    }
}