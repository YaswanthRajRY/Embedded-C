/*
20) Rearrange array such that arr[i] becomes arr[arr[i]]. 
 
WTD: Transform the array such that the number at each index corresponds to the number 
found at the index from the original array specified by the current number. 
 
(e.g.: I/P: [0, 1, 2, 3]; O/P: [0, 1, 2, 3]) 
*/
#include <stdio.h>

 // Time Complexity: O(n)
void rearrange(int arr[], int size)
{
    for (int i=0; i<size; i++)
    {
        arr[i] += (arr[arr[i]] % size) * size;
    }

    for (int i=0; i<size; i++)
    {
        arr[i] /= 4;
    }
}

int main()
{
    int arr[] = {3, 0, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    rearrange(arr, size);

    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}