/*
13) Merge two sorted arrays to produce one sorted array. 
 
WTD: Sequentially compare the elements of two sorted arrays, combining them into a 
single array that remains sorted. 
 
(e.g.: I/P: [1,3,5], [2,4,6]; O/P: [1,2,3,4,5,6] )
*/

#include<stdio.h>
#include<stdlib.h>

// Time Complexity: O(n+m)
int* mergeArr(int arr1[], int len1, int arr2[], int len2, int* returnSize)
{
    int* result = (int*)malloc(sizeof(int) * (len1 + len2));
    *returnSize = 0;
    int i = 0;
    int j = 0;

    while (i < len1 && j < len2)
    {
        result[(*returnSize)++] = (arr1[i] < arr2[j]) ? arr1[i++] : arr2[j++];
    }

    while (i < len1)
    {
        result[(*returnSize)++] = arr1[i++];
    }

    while (j < len2)
    {
        result[(*returnSize)++] = arr2[j++];
    }

    return result;
}

int main()
{
    int arr_A[] = {1,3,5};
    int arr_B[] = {2,4,6};
    int size_A = sizeof(arr_A) / sizeof(arr_A[0]);
    int size_B = sizeof(arr_B) / sizeof(arr_B[0]);

    int returnSize;

    int* res = mergeArr(arr_A, size_A, arr_B, size_B, &returnSize);

    for (int i=0; i<returnSize; i++)
        printf("%d ", res[i]);
     
    return 0;
}