/*
23) Compute the leaders in an array. 
 
WTD: Traverse the array from right to left, finding numbers that remain the largest 
compared to all numbers on their right. 
 
(e.g.: I/P: [16,17,4,3,5,2]; O/P: [17,5,2])
*/
#include <stdio.h>
#include <stdlib.h>

 // Time Complexity: O(n)
int* findLargestNum(int arr[], int size, int* returnSize)
{
    int* result = (int*)malloc(sizeof(int) * size);
    *returnSize = 0;
    int max = 0;

    for (int i=size-1; i>=0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            result[(*returnSize)++] = max;
        }
    }

    for (int i=0, j = (*returnSize - 1); i<j; i++, j--)
    {
        int temp = result[i];
        result[i] = result[j];
        result[j] = temp;
        i++;
        j--;
    }

    return result;
}

int main()
{
    int arr[] = {16,17,4,3,5,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int returnSize;

    int* res = findLargestNum(arr, size, &returnSize);

    printf("[");
    for (int i=0; i<returnSize; i++)
        printf("%d%c ", res[i], (i < returnSize - 1)?',' : ']');

    return 0;
}