/*
19)Find the longest consecutive subsequence in an array. 
 
WTD: Examine the array to find the longest stretch of numbers that appear in increasing 
consecutive order. 
 
(e.g.: I/P: [1, 9, 3, 10, 4, 20, 2]; O/P: [1, 2, 3, 4] )
*/
#include <stdio.h>
#include <stdlib.h>

 // Time Complexity: O(n logn)
int compare(const void* a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int findLongestSubseq(int arr[], int size)
{
    qsort(arr, size, sizeof(int), compare);

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