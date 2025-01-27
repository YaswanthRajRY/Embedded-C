/*
8. Write a function that trims leading and trailing whitespace from a string using 
pointers. 
 
WTD: Use two pointers to find the first and last non-whitespace characters. Move 
characters to trim the string 
 
(e.g.: I/P: " Hello World " ,O/P: "Hello World" )
*/
#include <stdio.h>
#include <string.h>

void my_strmov(char* d, const char* s, int len)
{
    if (d < s)
    {
        for (int i=0; i<len; i++)
        {
            d[i] = s[i];
        }
    }
    else
    {
        for (int i=len; i>0; i--)
        {
            d[i - 1] = s[i - 1];
        }
    }
}

void trimWhitespaces(char* str, int len)
{
    int start = 0;
    int end = len - 1;

    while (start < len && str[start] == ' ')
    {
        start++;
    }

    while (end > start && str[end] == ' ')
    {
        end--;
    }

    int trimLen = end - start + 1;

    my_strmov(str, str + start, trimLen);

    str[trimLen] = '\0';
}

int main()
{
    char str[] = "   Hello World  ";
    int len = strlen(str);

    trimWhitespaces(str, len);

    printf("%s", str);

    return 0;
}