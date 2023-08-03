#include <stdio.h>

int main() {



    return 0;
}

void remplissage(float tab[10]) {

    for (int i = 0; i < 10; i++)
    {
        printf("Entrez la note numero %d: ", i+1);
        fflush(stdin);
        scanf("%f", tab[i]);

        if(tab[i] < 0 && tab[i] > 20) {
            printf("Valeur impossible.");
            i--;
        }
    }
    
}