/*
23) Compute the leaders in an array. 
 
WTD: Traverse the array from right to left, finding numbers that remain the largest 
compared to all numbers on their right. 
 
(e.g.: I/P: [16,17,4,3,5,2]; O/P: [2,5,17])
*/
#include <stdio.h>

void findLargestNum(int arr[], int size)
{
    int max = 0;

    for (int i=size-1; i>=0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            printf("%d ", arr[i]);
        }
    }
}

int main()
{
    int arr[] = {16,17,4,3,5,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    findLargestNum(arr, size);

    return 0;
}