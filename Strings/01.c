/*
1) Print Duplicate characters from a string.  
 
What to do (WTD): Traverse through the given string and identify characters that appear 
more than once. 
 
(e.g.: I/P: "apple" ,O/P: "p")
*/

#include <stdio.h>
#include <string.h>

void findDuplicate(char* str)
{
    int s[256] = {0};

    while (*str != '\0')
    {
        s[*str]++;
        str++;
    }    
    
    for (int i=0; i<256; i++)
    {
        if (s[i] > 1)
        {
            printf("%c ", i);
        }
    }
}

int main()
{
    char str[] = "apple";
    findDuplicate(str);

    return 0; 
}