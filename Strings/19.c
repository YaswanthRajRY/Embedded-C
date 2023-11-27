/*
19) Count Substrings with Equal 0s and 1s. 
 
WTD: Given a binary string, count the number of substrings that have an equal number of 
0s and 1s. For "0011", the answer is 4: "00", "11", "0011", and "01". 
 
(e.g.: I/P: "0101"; O/P: 4)
*/

#include <stdio.h>
#include <string.h>

void countSubstring(const char* str, int len)
{
    int count = 0;
    int i,j;
        
    for (i=0; i<len; i++) // loop to iterate each char in string
    {
        int zero = 0;
        int one = 0;
        for (j=i; j<len; j++) // second iteration from ith position
        {
            if (str[j] == '0')
            {
                zero++;
            }
            else if (str[j] == '1')
            {
                one++;
            }
        }
        if (zero % 2 == 0)
        {
            count++;
        } 
        else if (one % 2 == 0)
        {
            count++;
        }
        else if (one == zero)
        {
            count++;
        }
    }

    printf("%d",count);
}

int main()
{
	const char S[] = "1000";
	int n = strlen(S);

	countSubstring(S, n);
	return 0;
}

