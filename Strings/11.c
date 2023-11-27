/*
11) Check if two strings are a rotation of each other.  
 
WTD: Verify if one string can be obtained by rotating another string, indicating how many 
positions were involved in the rotation. 
 
(e.g.: I/P: "abcde" "cdeab" ,O/P: "Rotation: 2L"(Obtaining String B by rotating String A)) 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotateLeft(char* str, int l) // function to rotate string left
{
    char temp = str[0]; // copy first char in string to temp
    for (int i = 0; i < l - 1; i++)
    {
        str[i] = str[i + 1]; // move each char in string to previous index 
    }
    str[l - 1] = temp; // update first char to last in the string
}

void rotateRight(char* str, int l) // function to rotate string right
{
    char temp = str[l - 1]; // copy last char in the string to temp
    for (int i = l - 1; i > 0; i--)
    {
        str[i] = str[i - 1]; // move each char in string to next index
    }
    str[0] = temp; // update last char to first in the string
}

void rotate(char* str1, char* str2)
{
    int left = 0, right = 0;
    int len = strlen(str1);
    char tempStr[len + 1];
    strcpy(tempStr, str1);

    if (strcmp(str1, str2) == 0) // compare 2 string if equal it gives 0
    {
        printf("Both strings are the same");
        return;
    }

    while (strcmp(tempStr, str2) != 0) // loop until both strings are equal
    {
        rotateRight(tempStr, len); // rotate string right
        right++;
    }

    strcpy(tempStr, str1);
    if (strcmp(tempStr, str2) == 0)  
    {
        printf("Rotation: 0\n"); 
        return;
    }

    while (strcmp(tempStr, str2) != 0) // loop until both strings are equal
    {
        rotateLeft(tempStr, len); // rotate string left
        left++;
    }

    if (right < left)
    {
        printf("%dR", right);
    }
    else
    {
        printf("%dL", left);
    }
}

int main()
{
    char str1[] = "abcde";
    char str2[] = "cdeab";

    rotate(str1, str2);

    return 0;
}
