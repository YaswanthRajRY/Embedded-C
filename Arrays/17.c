/*
17) Find if there's a subarray with zero sum.

WTD: Explore the array's subarrays (subsets of consecutive elements) to determine if there
exists any subarray that sums up to zero.

(e.g.: I/P: [4, 2, -3, 1, 6]; O/P: True )
*/
#include <stdio.h>

int subArraywithZero(int arr[], int size)
{
    int hash[100] = {0};
    hash[50] = 1;
    int sum = 0;

    for (int i=0; i<size; i++)
    {
        sum += arr[i];

        if (sum == 0 || hash[sum + 50])
        {
            return 1;
        }

        hash[sum + 50] = 1;
    }

    return 0;
}

int main()
{
    int arr[] = {1,2,-3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    if (subArraywithZero(arr, size))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}