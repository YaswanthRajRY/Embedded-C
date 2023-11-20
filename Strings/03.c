/*
3) Print the first non-repeated character from a string.  
WTD: Examine the string and pinpoint the very first character that doesn't repeat elsewhere 
in the string. 
 
(e.g.: I/P: "swiss" ,O/P: "w")
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "swiss";
    int len = strlen(str);
    int i,j,count;

    for(i=0; i<len; i++)
    {
        count = 0;
        for(j=0; j<len; j++)
        {
            if(str[i] == str[j] && i != j)
            {
                count = 1;
                break;
            }
        }
        if(count == 0)
        {
            printf("%c",str[i]);
            break;
        }
    }
}