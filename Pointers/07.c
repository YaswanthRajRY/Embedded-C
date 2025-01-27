/*
7. Implement a function that splits a string into two halves and returns pointers to the 
beginning of each half. 
 
WTD: Use pointer arithmetic to find the middle of the string. Return the original and the 
middle pointers. 
 
(e.g.: I/P: "HelloWorld" ,O/P: "Hello", "World" )
*/
#include <stdio.h>
#include <stdlib.h>

void split(char* str, char* str1, char* str2)
{
    int len = 0;
    char* t = str;

    while (*t)
    {
        t++;
        len++;
    }

    for (int i=0; i<len/2; i++)
    {
        *str1++ = *str++;
    }
    *str1 = '\0';

    for (int i=0; i<len/2; i++)
    {
        *str2++ = *str++;
    }
    *str2 = '\0';
}

int main()
{
    char* str = "HelloWorld";
    int str_len = strLen(str);
    
    char* str1 = (char*)malloc(sizeof(char) * (str_len/2 + 1));
    char* str2 = (char*)malloc(sizeof(char) * (str_len/2 + 1));

    split(str, str1, str2);

    printf("%s %s", str1, str2);

    return 0;
}