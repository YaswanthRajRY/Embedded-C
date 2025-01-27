/*
13. Write a function that converts a string to lowercase using pointers. 
 
WTD: Traverse the string. For each character, if it's uppercase, add 32 to convert it to 
lowercase. 
 
(e.g.: I/P: "HELLO" ,O/P: "hello" )
*/
#include <stdio.h>

void convertLowerCase(char* str)
{
    while(*str)
    {
        if (*str >= 65 && *str <= 90)
        {
            *str += 32;
        }
        str++;
    }
    
}

int main()
{
    char str[] = "HELLO";

    convertLowerCase(str);

    printf("%s",str);

    return 0;
}