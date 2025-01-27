/*
11. Implement a function that merges two sorted arrays into a third array using pointers. 
 
WTD: Use three pointers to traverse and compare the two input arrays and insert the 
smaller element into the third array. 
 
(e.g.: I/P: int arr1[] = {1,3,5}, arr2[] = {2,4,6} ,O/P: {1,2,3,4,5,6} )
*/
#include <stdio.h>
#include <stdlib.h>

int* mergeArray(int arr1[], int s1, int arr2[], int s2, int* len)
{
    int* mergedArray = (int*)malloc(sizeof(int) * (s1 + s2));

    int i = 0;
    int j = 0;

    while (i < s1 && j < s2)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArray[(*len)++] = arr1[i++];
        }
        else
        {
            mergedArray[(*len)++] = arr2[j++];
        }
    }

    while (i < s1)
    {
        mergedArray[(*len)++] = arr1[i++];
    }

    while (j < s2)
    {
        mergedArray[(*len)++] = arr2[j++];
    }

    return mergedArray;
}

int main()
{
    int arr1[] = {1,3,5};
    int arr2[] = {2,4,6,7,8,9,10};
    int s1 = sizeof(arr1)/sizeof(arr1[0]);
    int s2 = sizeof(arr2)/sizeof(arr2[0]);

    int len = 0;

    int* res = mergeArray(arr1, s1, arr2, s2, &len);

    for (int i=0; i<len; i++)
    {
        printf("%d ", res[i]);
    }

    return 0;
}