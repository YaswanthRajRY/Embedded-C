/*
2) Convert a string to its integer representation without using any built-in functions.  
 
WTD: Transform a given string of numeric characters into its corresponding integer 
representation without relying on built-in methods. 
 
(e.g., "1234" to 1234)
*/

#include<stdio.h>
#include<stdlib.h>

int charToint(char* str)
{
    int i=0;
    int sign = 1;
    if (str[i] == '-')
    {
        i = 1;
        sign = -1;
    }
    int digit = 0;
    while(str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            int tempVar = str[i] - '0';
            digit = digit * 10 + tempVar;
        }
        i++;
    }
    return digit * sign;
}

int main()
{
    char str[] = "1234";
    int num = charToint(str);
    printf("%d",num);

    return 0;
}