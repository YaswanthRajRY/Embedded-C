/*
14. Implement a program that finds the first non-repeated character in a string using 
pointers. 
 
WTD: Use a fixed-size array to count occurrences. Traverse the string twice: first to count 
and then to find the non-repeated character. 
 
(e.g.: I/P: "swiss" ,O/P: 'w' )
*/
#include <stdio.h>

void findFirstNonRepeatedChar(const char* str)
{
    for (int i=0; str[i] != '\0'; i++)
    {
        int flag = 1;
        for (int j=0; str[j] != '\0'; j++)
        {
            if(str[i] == str[j] && i != j)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            printf("%c", str[i]);
            return;
        }
    } 
}

int main()
{
    char str[] = "swiss";
    
    findFirstNonRepeatedChar(str);

    return 0;
}