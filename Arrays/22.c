/*
22) Compute the product of an array except self.  
 
WTD: For every index in the array, calculate the product of all numbers except for the 
number at that index. 
 
(e.g.: I/P: [1,2,3,4]; O/P: [24,12,8,6])
*/
#include <stdio.h>
#include <stdlib.h>

/* // Time Complexity: O(n)
int product(int arr[], int size)
{
    int product = 1;

    for (int i=0; i<size; i++)
    {
        product *= arr[i];
    }

    for (int i=0; i<size; i++)
    {
        arr[i] = product / arr[i];
    }

    return arr;
}
*/

 // without division
 // Time Complexity: O(n)
int* product(int arr[], int size)
{
    int *prefix = (int*)malloc(sizeof(int) * size);
    prefix[0] = 1;

    for (int i=1; i<size; i++)
    {
        prefix[i] = prefix[i - 1] * arr[i - 1];
    }

    int suffix = 1;
    for (int i=size-1; i>=0; i--)
    {
        prefix[i] = prefix[i] * suffix;
        suffix = suffix * arr[i];
    }

    return prefix;
}

int main()
{
    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    int* res = product(arr, size);

    for (int i=0; i<size; i++)
    {
        printf("%d ", res[i]);
    }

    free(res);
    return 0;
}