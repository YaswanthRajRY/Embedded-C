/*
24) Palindrome Partitioning.  
 
WTD: Partition a string such that every substring of the partition is a palindrome. Return 
the minimum cuts needed. 
 
( e.g.: I/P: "aab"; O/P: 1 (The string can be split as ["aa","b"]). )
*/

#include <stdio.h>
#include <string.h>

int palindrome(char* str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
        {
            end--;
        }
        else
        {
            if (end-start != 1)
            {
                start++; end--;
            }
            else
            {
                break;
            }
        }
    }

    for (int k=start; k<=end; k++)
    {
        printf("%c",str[k]);
    }
    printf("\n");
    return end;
}

int main()
{
    char str[] = "aabc";
    int l = strlen(str);
    for (int i=0; i<l; i++)
        i = palindrome(str,i,l-1);

    return 0; 
}