/*
9) Check if two strings are anagrams of each other. 
 
WTD: Determine if two provided strings can be rearranged to form each other, meaning 
they are anagrams. 
 
(e.g.: I/P: "listen" ,O/P: "silent") 
*/

#include<stdio.h>
#include<string.h>

int anagram(char* str1, char* str2)
{
    if (strlen(str1) != strlen(str2)) // return if string is not equal
    {
        return 0;
    }
    int count1[256]={0};
    int count2[256]={0};
    int i;

    for (i=0; i<strlen(str1); i++)
    {
        count1[str1[i]]++; // count frequency of char in string 1
        count2[str2[i]]++; // count frequency of char in string 2
    }

    for (i=0; i<256; i++)
    {
        if(count1[i] != count2[i]) 
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str1[] = "listen";
    char str2[] = "silent";
    int res = anagram(str1,str2);
    if (res)
    {
        printf("True");
    }
    else{
        printf("False");
    }

    return 0;
}
