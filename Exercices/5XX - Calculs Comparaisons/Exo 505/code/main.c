#include <stdio.h>

int main() {

    char question;

    printf("Entrez la lettre de la question (a, b ou c): ");
    scanf("%c", &question);


    int X, Y, Z;

    if (question == 'a') {
        X = 4;
        Y = 1;
        Z = 4;
    }
    else if (question == 'b') {
        X = 4;
        Y = 5;
        Z = 4;
    }
    else if (question == 'c') {
        X = 1;
        Y = 3;
        Z = 1;
    }

    int X1 = X;
    int Y1 = Y;
    int Z1 = Z;

    // Séquence 1
    if ((X1<5 || Y1>2) &&( Z1>3))
        {
        X1       =1; if(Z1-Y1)>0 Z1=10;
        Y1       =Y1+Z1 ;
        }
    else
            X1 =2;
        Z1       = Y1+Z1;

    
}