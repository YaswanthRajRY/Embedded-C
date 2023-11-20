/*
7) Check if a string has balanced parentheses.  
 
WTD: Ensure that for every opening bracket, parenthesis, or brace in the string, there's a 
corresponding closing counterpart, and they are correctly nested. 
 
(e.g.: I/P: "()[{}]" ,O/P: "True")
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "()[{}]";
    int len = strlen(str);
    char s[len];
    int i,j=0,bol=1;

    for(i=0; i<len; i++)
    {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s[j++] = str[i];
        }
        if(str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            char res = s[--j];
            if(str[i] == ')' && res != '(' || str[i] == ']' && res != '[' || str[i] == '}' && res != '{')
            {
                bol = 0;
                break;
            }
        }
    }
    (bol > 0) ? printf("True") : printf("False");

    return 0;
}
