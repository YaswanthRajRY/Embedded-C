/*
18) Longest Substring Without Repeating Characters: 
 
WTD: Find the length of the longest substring without repeating characters. For 
"abcabcbb", the answer would be 3, because the longest substring without repeating letters is 
"abc". 
 
(e.g.: I/P: "pwwkew"; O/P: 3)
*/

#include <stdio.h>
#include <string.h>

void longestSubstring(char* str)
{
    int len = strlen(str);
    int i,maxlen=1;

    for (i=0; i<len; i++)
    {
        int next = i;
        int charCount[256]={0};
        while (next < len && charCount[str[next]] == 0) // find substring 
        {
            charCount[str[next]]++; // count frequenct of each char
            if(next - i + 1 > maxlen) // update maximum sub string
            {
                maxlen = next - i + 1;
            }
            next++;
        }
    } 
    printf("%d",maxlen);
}

int main()
{
    char str[] = "pwwkew";
    
    longestSubstring(str);

    return 0;
}
