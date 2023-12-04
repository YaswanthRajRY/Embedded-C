/*
16) Check for Pangram 
 
WTD: Determine if the given string contains every letter of the alphabet at least once. For 
instance, "The quick brown fox jumps over a lazy dog" is a pangram. 
 
(e.g.: I/P: "Jinxed wizards pluck ivy from the big quilt"; O/P: True)
*/

#include<stdio.h>
#include<stdbool.h>

bool pangram(char* str)
{
    int charCount[26] = {0}; 
    int i = 0;

    while (*str != '\0') // iterate each char in the string until null char
    {
        char c = *str;
        if (c >= 'a' && c <= 'z') // check char is in range of 'a' to 'z' in ASICll code
        {
            charCount[c - 'a']++; // count char ex: (f)102 - (a)97 = 5 
        }
        else if (c >= 'A' && c <= 'Z') // check char is in range of 'a' to 'z' in ASICll code
        {
            charCount[c - 'A']++; // count char ex: (F)65 - (A)70 = 5 
        }
        str++;
    }

    for (i = 0; i < 26; i++) 
    {
        if (charCount[i] == 0) // if any element in the array is empty return 0
        {
            return false;
        }
    }

    return true;
}

int main()
{
    char* str = "Jinxed wizards pluck ivy from the big quilt";

    if (pangram(str)) 
    {
        printf("True");
    } 
    else 
    {
        printf("False");
    }

    return 0;
}
