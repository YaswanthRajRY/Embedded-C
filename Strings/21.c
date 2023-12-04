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

    for (i=0; i<=len1-len2; i++) // loop to compare substring with main string
    {   
        int flag = 1;
        for (j=0; j<len2; j++) // iterate main string
        {
            if (subStr[j] != str[j+i]) // compare the substring and main string
            {
                flag = 0;
            }
        }
        if(flag == 1) // if equal increment count
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
