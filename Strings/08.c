/*
8) Count the occurrences of a given character in a string. 
 
WTD: Count how many times a specified character appears in a given string. 
 
(e.g.: I/P: "apple",Char: 'p' ,O/P: "2")
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "apple";
    int len = strlen(str);
    int i,j;
    int count[256] = {0};

    for (i=0; i<len; i++)
    {
        count[str[i]]++;
    }
    for (i=0; i<len; i++)
    {
        if(count[str[i]] > 1)
        {
            printf("%c %d",str[i],count[str[i]]);
            count[str[i]] = 0;
        }
    }

    return 0;
}