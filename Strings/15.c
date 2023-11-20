/*
15) Find all permutations of a string.  
 
WTD: Generate all possible arrangements of the characters from the given string. 
 
(e.g.: I/P: "ab" ,O/P: "ab","ba")
*/

#include<stdio.h>
#include<string.h>

void swap(char* str1, char* str2)
{
    char temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
void permutation(char* str, int l, int r)
{
    int i;
    if(l == r)
    {
        printf("%s\n",str);
    }
    else
    {
        for (i=l; i<=r; i++)
        {
            swap(str+l,str+i);
            permutation(str, l+1, r);
            swap(str+l,str+i);
        } 
    }
}

int main()
{
    char str[] = "abc";
    int len = strlen(str);

    permutation(str, 0, len-1);

    return 0;    
}