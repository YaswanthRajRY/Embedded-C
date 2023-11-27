/*
2) Convert a string to its integer representation without using any built-in functions.  
 
WTD: Transform a given string of numeric characters into its corresponding integer 
representation without relying on built-in methods. 
 
(e.g., "1234" to 1234)
*/

#include<stdio.h>
#include<stdlib.h>

int charToint(char* str) //function for converting a string to its integer representation
{
    int i=0;
    int sign = 1;
    if (str[i] == '-') // check if first character in sting has negative sign (ex: "-1234")
    {
        i = 1;
        sign = -1;
    }
    int digit = 0;
    while(str[i] != '\0') // iterating each character untill null character
    {
        if (str[i] >= '0' && str[i] <= '9') // condition to check the character is within the range of 0-9 in ASICll code
        {
            int tempVar = str[i] - '0'; // extracting int value from char (ex: '5' - '0' (ASICll code for 5 is 53 and for 0 is 48). Then 53 - 48 = 5)
            digit = digit * 10 + tempVar; // update the digit
        }
        i++; // move to next char in string
    }
    return digit * sign; // return value with sign
}

int main()
{
    char str[] = "1234";
    int num = charToint(str);
    printf("%d",num);

    return 0;
}
