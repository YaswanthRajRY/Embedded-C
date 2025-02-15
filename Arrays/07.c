/*
7) Remove duplicates from an array without using any library. 
 
WTD: Navigate through the array, identifying and removing any repetitive occurrences of 
numbers, ensuring each number appears only once. 
 
(e.g.: I/P: [1,1,2,2,3,4,4]; O/P: [1,2,3,4])
*/

#include <stdio.h>
#include <stdlib.h>

/* // Time Complexity: O(n^2)
void removeDuplicates(int arr[], int* size)
{
    for (int i = 0; i < (*size)-1; i++)
    {
        int j = i+1;
        if (arr[i] == arr[j])
        {
            for (int k = i; k < (*size)-1; k++)
            {
                arr[k] = arr[k+1];
            }
            (*size)--;
        }
    }
}
*/

 // Time Complexity: O(n)
void removeDuplicates(int arr[], int* size)
{
    int* hash = (int*)calloc(1000, sizeof(int));
    int returnSize = 0;

    for (int i=0; i<(*size); i++)
    {
        if (hash[arr[i]] == 0)
        {
            hash[arr[i]]++;
            arr[returnSize++] = arr[i];
        }
    }

    *size = returnSize;
    free(hash);
}

int main()
{
    int  arr[] = {1,1,2,2,3,4,4,5,8,9,66,66};
    int size = sizeof(arr) / sizeof(arr[0]);

    removeDuplicates(arr, &size);

    for (int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}