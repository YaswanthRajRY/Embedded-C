/*
1. Write a program to find the size of a data type without using the `sizeof` operator, use 
pointer arithmetic. 
 
WTD: Declare a pointer to the given type and increment it. Subtract the original pointer 
value from the incremented value to get the size. 
 
(e.g.: I/P: int; O/P: 4( based on platform))
*/

#include <stdio.h>
#include <stdlib.h>

#define FIND_SIZE(x) (size_t)(&x + 1) - (size_t)&x

int main()
{
    int a;
    char b;
    float c;
    long d;
    double e;

    printf("%ld\n", FIND_SIZE(a));
    printf("%ld\n", FIND_SIZE(b));
    printf("%ld\n", FIND_SIZE(c));
    printf("%ld\n", FIND_SIZE(d));
    printf("%ld\n", FIND_SIZE(e));

    return 0;
}