/*
3) Find the largest and smallest number in an unsorted integer array. 
 
WTD: Navigate through the elements of the unsorted array, continuously updating the 
largest and smallest values found to identify the extremities in the array. 
 
(e.g.: I/P: [34, 15, 88, 2]; O/P: Max: 88, Min: 2 )
*/

#include <stdio.h>
#include <stdlib.h>

 // Time complexity: O(n)
int* findMinMax(int arr[], int size)
{
    int* minMax = (int*)malloc(sizeof(int) * 2);
    minMax[0] = arr[0];
    minMax[1] = arr[0];

    for(int i=0; i<size; i++)
    {
        if (arr[i] < minMax[0])
            minMax[0] = arr[i];
        else if (arr[i] > minMax[1])
            minMax[1] = arr[i];
    }

    return minMax;
}

int main()
{
    int arr[] = {12,54,36,20,115,2586,458,654,158};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int* res = findMinMax(arr, size);

    printf("Max: %d, Min: %d", res[0], res[1]);

    free(res);

    return 0;
}