#include <stdio.h>
#include <limits.h>

int main() {

    printf("Sur un octet de memoire :\n");
    printf("char : %d à %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char : 0 à %d\n", UCHAR_MAX);
    printf("\n");

    printf("Sur deux octet de memoire :\n");
    printf("short int : %i à %i\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short int : 0 à %i\n", USHRT_MAX);
    printf("\n");

    printf("Sur 4 octet de memoire :\n");
    printf("int : %i à %i\n", INT_MIN, INT_MAX);
    printf("unsigned int : 0 à %u\n", UINT_MAX);
    printf("\n");
    
    printf("Sur 8 octet de memoire :\n");
    printf("long int : %li à %li\n", LONG_MIN, LONG_MAX);
    printf("unsigned long int : 0 à %lu\n", ULONG_MAX);
    printf("\n");
}