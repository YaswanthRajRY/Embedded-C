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

    for(i=0; i<len; i++) // first iteration 
    {
        count = 0;
        for(j=0; j<len; j++) // second iteration
        {
            if(str[i] == str[j] && i != j) // check char in first iteration is equal to second iteration and condition to avoid compare same index 
            {
                count = 1; // increment count value
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
