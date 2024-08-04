/*
4) Find all pairs of an integer array whose sum is equal to a given number. 
 
WTD: Explore combinations of integer pairs in the array. Check if the sum of any of these 
pairs matches a specified target number. 
 
(e.g.: I/P: [2,4,3,5,6,-2,4,7,8,9], Sum: 7; O/P: [2,5],[4,3] )
*/

#include <stdio.h>

int main()
{
    int arr[] = {2,4,3,5,6,-2,4,7,8,9};
    int sum = 7;
    int size = sizeof(arr) / sizeof(arr[0]);

    for (int i=0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (arr[i] + arr[j] == sum)
            {
                printf("[%d, %d]\n",arr[i], arr[j]);
                break;
            }
        }
    }

    return 0;
}