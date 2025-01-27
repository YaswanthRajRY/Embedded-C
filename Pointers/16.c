/*
16. Create a program that checks if a string is a palindrome using pointers. 
 
WTD: Use two pointers, one at the start and the other at the end. Traverse inward, 
comparing characters. 
 
(e.g.: I/P: "radar" ,O/P: True)
*/
#include <stdio.h>

int checkPalindrome(const char* str)
{
    int start = 0;
    int end = 0;

    while (str[end])
    {
        end++;
    }
    end -= 1;

    while (start < end)
    {
        if (str[start] != str[end])
        {
            return 0;
        }

        start++;
        end--;
    }

    return 1;
}

int main()
{
    char str[] = "radar";

    if (checkPalindrome(str))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}