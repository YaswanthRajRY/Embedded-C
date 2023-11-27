/*
22) String Encoding.  
 
WTD: Encode a string by replacing each character with the third character after it in the 
alphabet. Wrap around to the start of the alphabet after 'z'. 
 
( e.g.: I/P: "abc"; O/P: "def". )
*/

#include <stdio.h>
#include <string.h>

void encodeStr(char* str, int len)
{
    int i;

    for (i=0; i<len; i++) // iterate each char in the string
    {
        if (str[i] >= 'a' && str[i] <= 'z') // check if char is in the range of 'a' - 'z' in ASICll code
        {
            str[i] = (str[i] - 'a' + len) % 26 + 'a'; // increase the index of char by value 3 
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = (str[i] - 'A' + len) % 26 + 'Z';
        }
    }

    printf("%s",str);
}

int main()
{
    char str[] = "xyz";
    int len = strlen(str);

    encodeStr(str, len);

    return 0;
}
