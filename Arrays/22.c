/*
22) Compute the product of an array except self.  
 
WTD: For every index in the array, calculate the product of all numbers except for the 
number at that index. 
 
(e.g.: I/P: [1,2,3,4]; O/P: [24,12,8,6])
*/
#include <stdio.h>

void product(int arr[], int size)
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
}

int main()
{
    int arr[] = {1,2,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    product(arr, size);

    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}