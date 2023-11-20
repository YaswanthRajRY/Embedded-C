/*
14) Reverse a string using recursion.  
 
WTD: Use a recursive method to invert the order of characters in a string. 
 
(e.g.: I/P: "hello" ,O/P: "olleh")
*/

#include<stdio.h>
#include<string.h>

void reverse(char* str, int start, int end)
{
    if (start >=end)
    {
        return;
    }

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse(str, ++start, --end);
}

int main()
{
    char str[] = "hello";
    int len = strlen(str);
    reverse(str, 0, len-1);

    printf("%s",str);
    return 0;
}