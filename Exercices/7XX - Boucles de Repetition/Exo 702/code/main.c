#include <stdio.h>

int main() {

    printf("\nBoucle for:\n");
    for (int i = 2; i < 100; i+=4)
    {
        printf("%d\t", i);
    }
    printf("\n");
    
    printf("Boucle while:\n");
    int i = 2;
    while (i < 100) {
        printf("%d\t", i);
        i += 4;
    }
    printf("\n");

    return 0;
}