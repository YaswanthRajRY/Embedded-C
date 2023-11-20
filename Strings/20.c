/*
20) Find Lexicographically Minimal Rotation. 
 
WTD: Determine the lexicographically smallest rotation of a string. For "bca", the rotations 
are "bca", "cab", and "abc", and the smallest is "abc". 
 
(e.g.: I/P: "dacb"; O/P: "acbd")
*/

#include <stdio.h>
#include <string.h>

char rotateRight(char* str, int len)
{
    char temp = str[0];
    int i;
    for (i=0; i<len-1; i++)
    {
        str[i] = str[i+1];
    }
    str[len-1] = temp;
}

void lexicographyRotate(char* str, int len)
{
    char smallestChar = 'z';
    int i;

    for (i=0; i<len; i++)
    {
        if (smallestChar > str[i])
        {
            smallestChar = str[i];
        }
    }
    
    while (smallestChar != str[0])
    {
        rotateRight(str, len);
    }
    
    printf("%s",str);
}

int main()
{
    char str[] = "dacb";
    int len = strlen(str);

    lexicographyRotate(str, len);

    return 0;
}