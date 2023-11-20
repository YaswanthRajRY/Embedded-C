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

    while (*str != '\0') {
        char c = *str;
        if (c >= 'a' && c <= 'z') {
            charCount[c - 'a']++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            charCount[c - 'A']++;
        }
        str++;
    }

    for (i = 0; i < 26; i++) {
        if (charCount[i] == 0) {
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