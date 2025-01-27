/*
12. Design a program that checks if a string is a prefix of another string using pointers. 
 
WTD: Traverse both strings using two pointers. If all characters of the shorter string match 
the beginning of the longer string, return True. 
 
(e.g.: I/P: char *str1 = "Hello", *str2 = "Hel" ,O/P: True )
*/
#include <stdio.h>

int checkPrefix(char* str1, char* str2)
{
    while (*str2)
    {
        if (*str1 != *str2)
        {
            return 0;
        }

        str1++;
        str2++;
    }

    return 1;
}

int main()
{
    char* str1 = "Hello";
    char* str2 = "Hel";

    if (checkPrefix(str1, str2))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}