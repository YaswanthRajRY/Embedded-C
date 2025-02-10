/*
4) Find all pairs of an integer array whose sum is equal to a given number. 
 
WTD: Explore combinations of integer pairs in the array. Check if the sum of any of these 
pairs matches a specified target number. 
 
(e.g.: I/P: [2,4,3,5,6,-2,4,7,8,9], Sum: 7; O/P: [2,5],[4,3] )
*/

#include <stdio.h>
#include <stdlib.h>

 // Time Complexity: O(n^2)
int** findPair(int arr[], int size, int target, int* returnSize)
{
    int** pair = (int**)malloc(sizeof(int*) * size);
    *returnSize = 0;

    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                pair[*returnSize] = (int*)malloc(sizeof(int) * 2);
                pair[*returnSize][0] = arr[i];
                pair[*returnSize][1] = arr[j];
                (*returnSize)++;
                break;
            }
        }
    }

    return pair;
}

int main()
{
    int arr[] = {2,4,3,5,6,-2,4,7,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int returnSize;

    int** res = findPair(arr, size, target, &returnSize);

    for (int i=0; i<returnSize; i++)
    {
        printf("[%d, %d]\n", res[i][0], res[i][1]);
    }

    for (int i=0; i<returnSize; i++)
        free(res[i]);

    free(res);

    return 0;
}