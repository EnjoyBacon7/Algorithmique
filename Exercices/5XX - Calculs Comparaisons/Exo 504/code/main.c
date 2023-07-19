#include <stdio.h>
#include <stdbool.h>

int main()
{

    int i, a;
    float f;
    i = 7;
    a = -2;
    f = 5.5;

    bool Q1 = f > 5;
    bool Q2 = (i + f) <= 1;
    bool Q3 = a >= -10 * (i + f);
    bool Q4 = (i >= 6) && ((a % 2) != 0);
    bool Q5 = (i >= 6) || ((a % 2) != 0);
    bool Q6 = (f < 11) && (i > 100);

    printf("f > 5 : %d\n", Q1);
    printf("(i + f) <= 1 : %d\n", Q2);
    printf("a >= -10 * (i + f) : %d\n", Q3);
    printf("(i >= 6) && ((a %% 2) != 0) : %d\n", Q4);
    printf("(i >= 6) || ((a %% 2) != 0) : %d\n", Q5);
    printf("(f < 11) && (i > 100) : %d\n", Q6);

    return 0;
}