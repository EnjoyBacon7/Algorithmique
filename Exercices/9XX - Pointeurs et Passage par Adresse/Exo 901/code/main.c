#include <stdio.h>

int main() {

    int* pt;
    int val1, val2, val3;
    val1 = 10;
    val2 = 20;
    val3 = 1;
    pt = &val1;
    *pt = 100;

    printf("val1: %d\nval2: %d\nval3: %d\n\npt: %p\n*pt: %d\n&pt: %p\n", val1, val2, val3, pt, *pt, &pt);

    return 0;
}