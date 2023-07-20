#include <stdio.h>

int main() {

    int n;
    printf("Entrez n : ");
    scanf("%d", &n);

    int U_n;
    int U_n_1 = 1;
    int U_n_2 = 1;

    if(n == 0) U_n = 1;
    else if(n == 1) U_n = 1;
    else {
        for (int i = 2; i <= n; i++)
        {
            U_n = U_n_1 + U_n_2;
            U_n_2 = U_n_1;
            U_n_1 = U_n;
        }
    }
    
    printf("U_%d = %d\n", n, U_n);

}