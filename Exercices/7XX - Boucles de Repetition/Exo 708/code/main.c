#include <stdio.h>

int main() {

    int n;
    printf("Entrez n : ");
    scanf("%d", &n);

    int U_n = 3;
    for (int i = 0; i < n; i++)
    {
        U_n = 3 * U_n + 4;
    }
    printf("U_%d = %d\n", n, U_n);
    
}