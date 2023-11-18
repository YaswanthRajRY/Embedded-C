// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

int *a = 0;

int main() {
    // Write C code here
    char* str = malloc(sizeof(char) * 10);
    for (int i=0; i<2; i++)
    {
        str[i] = malloc(sizeof(char));
        scanf("%s",str[i]);
    }

    printf("%s",str[1]);

    return 0;
}