/*
6. Design a program to concatenate two strings without using standard library functions, 
only pointers. 
 
WTD: Traverse the first string till the end and then copy the second string from that point. 
 
(e.g.: I/P: char *str1 = "Good ", *str2 = "Morning" ,O/P: "Good Morning" )
*/
#include <stdio.h>
#include <stdlib.h>

int strLen(char* str)
{
    int len = 0;
    while (*str)
    {
        len++;
        str++;
    }

    return len;
}

void stringConcatenate(char* str1, char* str2)
{
    while (*str1 != '\0')
    {
        str1++;
    }

    while(*str2 != '\0')
    {
        *str1++ = *str2++;
    }

    *str1 = '\0';
}

int main()
{
    char str1[] = "Good";
    char str2[] = "Morning";

    int str1_len = strLen(str1);
    int str2_len = strLen(str2);

    char* conString = (char*)malloc(sizeof(char) * (str1_len + str2_len - 1));
    *conString = '\0';

    stringConcatenate(conString, str1);
    stringConcatenate(conString, str2);


    printf("%s", conString);

    return 0;
}