#include <stdio.h>

int main() {

    int val1;
    unsigned char val2;
    char lettre;

    int* pt1;
    unsigned char* pt2;
    char* pt3;

    int** ppt1;
    unsigned char** ppt2;
    char** ppt3;

    pt1 = &val1;
    pt2 = &val2;
    pt3 = &lettre;

    ppt1 = &pt1;
    ppt2 = &pt2;
    ppt3 = &pt3;

    val1 = 1;
    val2 = 'a';
    lettre = 'd';

    printf("Affectation directe:\n");
    printf("val1 = %d\nval2 = %c\nlettre = %c\n", val1, val2, lettre);

    *pt1 = 2;
    *pt2 = 'b';
    *pt3 = 'e';

    printf("Affectation indirecte 1:\n");
    printf("val1 = %d\nval2 = %c\nlettre = %c\n", val1, val2, lettre);

    *pt1 = 3;
    *pt2 = 'c';
    *pt3 = 'f';

    printf("Affectation indirecte 2:\n");
    printf("val1 = %d\nval2 = %c\nlettre = %c\n", val1, val2, lettre);

    return 0;
}