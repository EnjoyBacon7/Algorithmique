#include <stdio.h>

int main() {

    char cara_k = 'k';
    char cara_0 = '0';
    int chiffre_0 = 0;

    if(cara_k) {
        printf("'k' est TRUE\n");
    }
    else {
        printf("'k' est FALSE\n");
    }

    if(cara_0) {
        printf("'0' est TRUE\n");
    }
    else {
        printf("'0' est FALSE\n");
    }

    if(chiffre_0) {
        printf("0 est TRUE\n");
    }
    else {
        printf("0 est FALSE\n");
    }

    return 0;
}