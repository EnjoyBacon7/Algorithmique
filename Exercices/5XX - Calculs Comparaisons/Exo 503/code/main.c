#include <stdio.h>
#include <stdbool.h>

int main() {

    bool a;
    bool b;
    bool ET;
    bool OU;
    bool NON;

    printf("\n+----+     Table de verite de ET, OU, et NON     +----+\n");
    printf("+---------+---------+-----------+-----------+---------+\n");
    printf("|    a    |    b    |  a ET b   |  a OU b   |  NON a  |\n");
    printf("+---------+---------+-----------+-----------+---------+\n");
    
    a = true;
    b = true;
    ET = (a && b);
    OU = (a || b);
    NON = (!a);
    printf("|    1    |    1    |     %d     |     %d     |    %d    |\n", ET, OU, NON);
    
    a = true;
    b = false;
    ET = (a && b);
    OU = (a || b);
    NON = (!a);
    printf("|    1    |    0    |     %d     |     %d     |    %d    |\n", ET, OU, NON);
    
    a = false;
    b = true;
    ET = (a && b);
    OU = (a || b);
    NON = (!a);
    printf("|    0    |    1    |     %d     |     %d     |    %d    |\n", ET, OU, NON);

    a = false;
    b = false;
    ET = (a && b);
    OU = (a || b);
    NON = (!a);
    printf("|    0    |    0    |     %d     |     %d     |    %d    |\n", ET, OU, NON);

    printf("+---------+---------+-----------+-----------+---------+\n");

    bool ETNONB;
    bool ETNONA;
    bool ETNONDOUBLE;

    printf("\n+----+                           Table de verite plus complexe                            +----+\n");
    printf("+---------+---------+----------------+----------------+----------------------------------------+\n");
    printf("|    a    |    b    |  a ET (NON b)  |  b ET (NON a)  |  ( a ET (NON b) ) OU ( b ET (NON a) )  |\n");
    printf("+---------+---------+----------------+----------------+----------------------------------------+\n");

    a = true;
    b = true;
    ETNONB = (a && (!b));
    ETNONA = (b && (!a));
    ETNONDOUBLE = (ETNONB || ETNONA);
    printf("|    1    |    1    |       %d        |       %d        |                   %d                    |\n", ETNONB, ETNONA, ETNONDOUBLE);
    
    a = true;
    b = false;
    ETNONB = (a && (!b));
    ETNONA = (b && (!a));
    ETNONDOUBLE = (ETNONB || ETNONA);
    printf("|    1    |    0    |       %d        |       %d        |                   %d                    |\n", ETNONB, ETNONA, ETNONDOUBLE);

    a = false;
    b = true;
    ETNONB = (a && (!b));
    ETNONA = (b && (!a));
    ETNONDOUBLE = (ETNONB || ETNONA);
    printf("|    0    |    1    |       %d        |       %d        |                   %d                    |\n", ETNONB, ETNONA, ETNONDOUBLE);

    a = false;
    b = false;
    ETNONB = (a && (!b));
    ETNONA = (b && (!a));
    ETNONDOUBLE = (ETNONB || ETNONA);
    printf("|    0    |    0    |       %d        |       %d        |                   %d                    |\n", ETNONB, ETNONA, ETNONDOUBLE);

    printf("+---------+---------+----------------+----------------+----------------------------------------+\n");


    return 0;
}