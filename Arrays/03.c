/*
3) Find the largest and smallest number in an unsorted integer array. 
 
WTD: Navigate through the elements of the unsorted array, continuously updating the 
largest and smallest values found to identify the extremities in the array. 
 
(e.g.: I/P: [34, 15, 88, 2]; O/P: Max: 88, Min: 2 )
*/

#include <stdio.h>

int main()
{
    int arr[] = {12,54,36,20,115,2586,458,654,158};
    int size = sizeof(arr) / sizeof(arr[0]);
    int max,min;
    
    max = min = arr[0];
    for(int i=0; i<size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        else if (arr[i] < min)
            min = arr[i];
    }

    printf("Max: %d, Min: %d", max, min);

    return 0;
}