/*
23) Maximum Occurring Character. 
 
WTD: Determine which character in a string appears the most times. 
 
( e.g.: I/P: "success"; O/P: "s". )
*/

#include <stdio.h>
#include <string.h>

void highoccurenceChar(char* str, int len)
{
    int charFreq[256] = {0};
    int maxChar = 0;
    char c;
    int i;

    for (i=0; i<len; i++) // iterate each char in the string
    {
        charFreq[str[i]]++; // count frequency of the char in the string
    }

    for (i=0; i<256; i++) // find max frequecy of the char in the strig
    {
        if (charFreq[i] > maxChar)
        {
            maxChar = charFreq[i]; // update max value
            c = i; // copy ASICll code of mostl repeated char
        }
    }
    printf("%c",c);
}

int main()
{
    char str[] = "sucess";
    int len = strlen(str);

    highoccurenceChar(str, len);

    return 0;
}
