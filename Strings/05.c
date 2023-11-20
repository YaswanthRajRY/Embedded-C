/*
5) Check if the string contains only digits. 
  
WTD: Determine if all characters in the provided string are numeric digits. 
 
(e.g.: I/P: "1234a" ,O/P: "False")
*/

#include<stdio.h>
#include<string.h>

void onlydigitInstring(char* strptr)
{
    while(*strptr != '\0')
    {
        if(*strptr < '0' && *strptr > '9')
        {
            printf("False");
            break;
        }
        else
        {
            printf("True");
            break;
        }
    }
}

int main()
{
    char str[] = "1234a";
    onlydigitInstring(str);

    return 0;
}