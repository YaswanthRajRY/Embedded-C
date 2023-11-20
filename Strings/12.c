/*
12) Check if a given string is a palindrome.  
 
WTD: Ascertain if the provided string reads the same forwards and backwards. 
 
(e.g.: I/P: "radar" ,O/P: "True")
*/

#include<stdio.h>
#include<string.h>

int palindrome(char* str, int l)
{
    int i,j;
    for (i=0, j=l-1; i<j; i++, j--)
    {
        if(str[i] != str[j])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[] = "radar";
    int len = strlen(str);

    int result = palindrome(str, len);
    if(result)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}