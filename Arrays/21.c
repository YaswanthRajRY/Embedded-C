/*
21) Find the peak element in an array (greater than or equal to its neighbors). 
 
WTD: Scrutinize the array to find an element that is both larger than its predecessor and its 
successor. 
 
(e.g.: I/P: [1, 3, 20, 4, 1, 0]; O/P: 20 )
*/
#include <stdio.h>

void findPeakElement(int arr[], int size)
{
    if (arr[0] >= arr[1])
    {
        printf("%d ", arr[0]);
    }

    for (int i=1; i<size-1; i++)
    {
        if (arr[i] > arr[i-1] && arr[i] >= arr[i+1])
        {
            printf("%d ", arr[i]);
        }
    }

    if (arr[size-1] > arr[size-2])
    {
        printf("%d ", arr[size-1]);
    }
}

int main()
{
    int arr[] = {1, 3, 20, 4, 1, 30};
    int size = sizeof(arr)/sizeof(arr[0]);

    findPeakElement(arr, size);

    return 0;
}