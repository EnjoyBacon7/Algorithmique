#include <stdio.h>

int main()
{
    int entier;

    do {
        printf("Entrez un entier positif : ");
        scanf("%d", &entier);
    } while (entier < 0);

    for (int i = -entier; i <= entier; i++)
    {
        if (i % 3 == 0) {
            printf("%d\n", i);
        }
    }
        
    return 0;
}