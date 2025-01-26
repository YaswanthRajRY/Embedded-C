/*
19)Find the longest consecutive subsequence in an array. 
 
WTD: Examine the array to find the longest stretch of numbers that appear in increasing 
consecutive order. 
 
(e.g.: I/P: [1, 9, 3, 10, 4, 20, 2]; O/P: [1, 2, 3, 4] )
*/
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
        if (arr[j] <= piviot_value)
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

int findLongestSubseq(int arr[], int size)
{
    quickSort(arr, 0, size-1);

    int start = 0;
    int count = 0;
    int max = 0;
    int currentStart = 0;

    for (int i=0; i<size-1; i++)
    {
        if (arr[i] + 1 == arr[i + 1])
        {
            count++;
        }
        else
        {
            if (count > max)
            {
                max = count;
                start = currentStart;
            }
            count = 0;
            currentStart = i+1;
        }
    }

    for (int i=start; i<=start+max; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {1, 9, 3, 10, 4, 20, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    findLongestSubseq(arr, size);

    return 0;
}