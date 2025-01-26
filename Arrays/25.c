/*
25) Find the subarray with the least sum.  
 
WTD: Investigate all possible subarrays of the given array, finding the one with the smallest 
sum. 
 
(e.g.: I/P: [3,1,-4,2,0]; O/P: -4)
*/
#include <stdio.h>

void findSmallestSum(int arr[], int size)
{
    int sum = 0;
    int small = 0xffffffff;

    for (int i=0; i<size; i++)
    {
        sum += arr[i];

        if (small > sum)
        {
            small = sum;
        }

        if (sum > 0)
        {
            sum = 0;
        }
    }

    printf ("%d", small);
}

int main()
{
    int arr[] = {3,1,-4,0,3};
    int size = sizeof(arr)/sizeof(arr[0]);

    findSmallestSum(arr, size);

    return 0;
}