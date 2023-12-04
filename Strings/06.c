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
    for(i=0; i<strlen(str); i++) // first iteration
    {
        count = 1;
        for(j=i; j<strlen(str); j++) // second iteration
        {
            if(str[i] == str[j] && i != j) // check if the char in 1st and 2nd iteration char is equal
            {
                count++;
                str[j]='0'; // replace the repeating char with 0
            }
        }
        if(str[i] != '0' && count > 1) // print char exclude 0
        {
            printf("%c ",str[i]);
        }
    }

    return 0;
}
