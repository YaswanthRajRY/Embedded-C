/*
8) Determine the intersection of two integer arrays. 
 
WTD: Compare every element of the two arrays, listing down the common integers that 
appear in both. 
 
(e.g.: I/P: [1,2,4,5,6], [2,3,5,7]; O/P: [2,5]) 
*/

#include <stdio.h>

int main()
{
    int arr1[] = {1,2,4,5,6};
    int arr2[] = {2,3,5,7};

    int len1 = sizeof(arr1) / sizeof(arr1[0]);
    int len2 = sizeof(arr2) / sizeof(arr2[0]);

    for (int i=0; i<len1; i++)
    {
        for (int j=0; j<len2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                printf("%d ",arr1[i]);
            }
        }
    }

    return 0;
}