/*
17) String Interleaving:  
 
WTD: Determine if a given string is an interleaving of two other strings. For example, "abc" 
and "123" can be interleaved as "a1b2c3". 
 
(e.g.: I/P: Strings: "xyz", "789", Interleaved: "x7y8z9"; O/P: True)
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool stringInterleaving(char *str1, char* str2, char* str3)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int i,j=0,k=0;

    if (len1 + len2 != len3) return false;

    for (i=0; i<len3; i++)
    {
        if (i%2 == 0)
        {
            if(str3[i] != str1[j])
            {
                return false;
            }
            j++;
        }
        else 
        {
            if(str3[i] != str2[k])
            {
                return false;
            }
            k++;
        }
    
    }

    return true;
}

int main()
{
    char str1[] = "abc";
    char str2[] = "123";
    char str3[] = "a1b2c3";
    

    if (stringInterleaving(str1, str2, str3))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}