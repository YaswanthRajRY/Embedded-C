/*
6) Sort an array using quicksort algorithm. 
 
WTD: Implement the quicksort sorting technique on the provided array to rearrange its 
elements in ascending order. 
 
(e.g.: I/P: [64, 34, 25, 12, 22, 11, 90]; O/P: [11, 12, 22, 25, 34, 64, 90] )
*/
// Time Complexity: O(nlogn)
#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right)
{
    int piviot_value = arr[right];
    int i = left;

    for (int j=left; j<right; j++)
    {
        if (arr[j] < piviot_value)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[right]);

    return i;
}

void quickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int piviot_index = partition(arr, left, right);

        quickSort(arr, left, piviot_index - 1);
        quickSort(arr, piviot_index + 1, right);
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, size-1);

    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}