/*
21) Substring Count.  
 
WTD: Find out how many times a particular substring appears in the given string.  
 
(e.g.: I/P: Main String: "banana", Substring: "ana"; O/P: )
*/

#include <stdio.h>
#include <string.h>

void subStringCount(char* str, char* subStr)
{
    int len1 = strlen(str);
    int len2 = strlen(subStr);
    int i,j;
    int count=0;

    for (i=0; i<=len1-len2; i++)
    {   
        int flag = 1;
        for (j=0; j<len2; j++)
        {
            if (subStr[j] != str[j+i])
            {
                flag = 0;
            }
        }
        if(flag == 1)
        {
            count++;
        }
    }
    printf("%d",count);
}

int main()
{
    char str[] = "banana";
    char subStr[] = "ana";
    int len = strlen(str);

    subStringCount(str, subStr);

    return 0;
}