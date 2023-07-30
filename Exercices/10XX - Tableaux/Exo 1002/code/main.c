#include <stdio.h>

int main() {

    float tab[7][4];

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Entrez la valeur ligne %d, colonne %d : ", i+1, j+1);
            fflush(stdin);
            scanf("%f", &tab[i][j]);
        }
        
    }

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%f\t", tab[i][j]);
        }
        printf("\n");
        
    }
    
    
}