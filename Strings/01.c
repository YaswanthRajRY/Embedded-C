/*
1) Print Duplicate characters from a string.  
 
What to do (WTD): Traverse through the given string and identify characters that appear 
more than once. 
 
(e.g.: I/P: "apple" ,O/P: "p")
*/

#include <stdio.h>
#include <string.h>

void findDuplicate(char* str)
{
    int s[256] = {0}; // creating hash table for character

    while (*str != '\0') // iterating each character in string untill null character
    {
        s[*str]++; // Increment the count for the current character in the array (ex: a ASICII code is 97, at index 97 in the array is incremented)
        str++; // move to next character in the string
    }    
    
    for (int i=0; i<256; i++) // iterating the array
    {
        if (s[i] > 1) // check element in the array is greater than 1. (ex: if a repeates in the string more than 1 time, then at index 97 the value is 2)
        {
            printf("%c ", i); // print character which is repeted more than once
        }
    }
}

int main()
{
    char str[] = "apple";
    findDuplicate(str);

    return 0; 
}
