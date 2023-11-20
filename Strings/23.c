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

    for (i=0; i<len; i++)
    {
        charFreq[str[i]]++;
    }

    for (i=0; i<256; i++)
    {
        if (charFreq[i] > maxChar)
        {
            maxChar = charFreq[i];
            c = i;
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