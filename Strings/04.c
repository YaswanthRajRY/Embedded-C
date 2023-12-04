/*
4) Find the longest palindrome substring in a given string. 
 
WTD: Identify the longest continuous sequence within the string that reads the same 
backward as forward. 
 
(e.g.: I/P: "babad" ,O/P: "bab") 
*/

#include<stdio.h>
#include<string.h>

void longestPalindrome(char str[])
{
    int ln = strlen(str);
    int start = 0;
    int maxlen = 1;
    int i;
    for(i=0; i<ln; i++) // loop until length of input string
    {
        int left=i,right=i; 
        while(left >= 0 && right < ln && str[left] == str[right]) // 
        {
            if(right - left > maxlen) // check maximum length of the substring
            {
                maxlen = right - left + 1;
                start = left;
                printf("L->%d R->%d\n",left, maxlen);
            }
            left--;
            right++;
        }
    }

    for(i=start; i<maxlen; i++) 
    {
        printf("%c",str[start++]);
    }
}
int main()
{
    char str[] = "babad";
    int ln = strlen(str);
    longestPalindrome(str);

    return 0;
}
