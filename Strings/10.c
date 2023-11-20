/*
10) Reverse words in a given sentence without using any library method.  
 
WTD: Invert the order of words in a given sentence, maintaining the order of characters 
within each word. 
 
(e.g.: I/P: "Hello Word" ,O/P: "World Hello")
*/

#include<stdio.h>

void reverse(char* str)
{
    int i,j,len=0;

    while(str[len] != '\0')
    {
        len++;
    }
    
    for (i=0, j=len-1; i<j; i++, j--)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    
    printf("%s",str);
}

int main()
{
    char str[] = "Hello World";

    reverse(str);

    return 0;
}