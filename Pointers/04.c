/*
4. Implement a program that swaps two strings using pointers to pointers. 
 
WTD: Use a pointer to pointer to swap the base addresses of the two strings. 
 
(e.g.: I/P: char *str1 = "hello", *str2 = "world" ,O/P: str1 = "world", str2 = "hello" )
*/

#include <stdio.h>

void swap(char** s1, char** s2)
{
    char* temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int main()
{
    char* str1 = "Hello";
    char* str2 = "World !";

    swap(&str1, &str2);

    printf("%s %s\n", str1, str2);

    return 0;
}