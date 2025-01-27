/*
1) Find the missing number in a given integer array of 1 to 500. 
 
WTD: Examine an array expected to contain consecutive integers from 1 to 500. Identify 
any integer that is missing from this sequence. 
 
(e.g.: I/P: [1,2,4,5]; O/P: 3)
*/
#include <stdio.h>

int findMissingNum(int arr[], int size)
{
    int a = arr[0];
    int b = 1;

    for (int i=1; i<size-1; i++)
    {
        a ^= arr[i];
    }

    for (int i=2; i<=size; i++)
    {
        b ^= i;
    }

    return a^b;
}

int main()
{
    int arr[] = {1,2,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int missingNum = findMissingNum(arr, size);
    
    printf("\nThe missing number: %d", missingNum);

    return 0;
}