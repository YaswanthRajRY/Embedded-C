/*
13) Count the number of vowels and constants in a given string.  
 
WTD: Tally the number of vowel and consonant characters in the given string. 
 
(e.g.: I/P: "apple" ,O/P: Vowels: 2, Consonants: 3) 
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "apple";
    int len = strlen(str);
    int i;
    int vowels=0;

    for (i=0; i<len; i++) // iterate each char in string
    {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') // check for vowels
        {
            vowels++; // increment value
        }
    }

    printf("Vowels: %d\nConsonants: %d",vowels,len-vowels);
}
