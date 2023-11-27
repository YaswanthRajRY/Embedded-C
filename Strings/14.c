/*
14) Reverse a string using recursion.  
 
WTD: Use a recursive method to invert the order of characters in a string. 
 
(e.g.: I/P: "hello" ,O/P: "olleh")
*/

#include<stdio.h>
#include<string.h>

void reverse(char* str, int start, int end)
{
    if (start >=end) // condition to exit recursion function
    {
        return;
    }

    char temp = str[start]; // copy char to temp
    str[start] = str[end]; // swap last char to first
    str[end] = temp; // copy char in temp to end of the string

    reverse(str, ++start, --end); // increment start index and decrement end index and call reverse function for recursion
}

int main()
{
    char str[] = "hello";
    int len = strlen(str);
    reverse(str, 0, len-1);

    printf("%s",str);
    return 0;
}
