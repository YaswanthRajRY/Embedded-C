/*
20) Find Lexicographically Minimal Rotation. 
 
WTD: Determine the lexicographically smallest rotation of a string. For "bca", the rotations 
are "bca", "cab", and "abc", and the smallest is "abc". 
 
(e.g.: I/P: "dacb"; O/P: "acbd")
*/

#include <stdio.h>
#include <string.h>

char rotateRight(char* str, int len) // rotate sting right 
{
    char temp = str[0]; // store first char in string
    int i;
    for (i=0; i<len-1; i++)
    {
        str[i] = str[i+1]; // move each char to previous index
    }
    str[len-1] = temp; // copy first char to last of the string
}

void lexicographyRotate(char* str, int len)
{
    char smallestChar = 'z'; // initialize larger char ASICll value
    int i;

    for (i=0; i<len; i++) // find smallest char 
    {
        if (smallestChar > str[i]) 
        {
            smallestChar = str[i];
        }
    }
    
    while (smallestChar != str[0]) // rotate until first char in string is equal to found shortest char present in the string
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
