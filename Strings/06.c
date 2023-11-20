/*
6) Duplicate characters found in a string.  
 
WTD: Spot all characters in the string that appear more than once and list them. 
 
(e.g.: I/P: "programming" ,O/P: "r","g","m")
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "programming";
    int i,j,count;
    for(i=0; i<strlen(str); i++)
    {
        count = 1;
        for(j=i; j<strlen(str); j++)
        {
            if(str[i] == str[j] && i != j)
            {
                count++;
                str[j]='0';
            }
        }
        if(str[i] != '0' && count > 1)
        {
            printf("%c ",str[i]);
        }
    }

    return 0;
}