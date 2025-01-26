/*
24) Find if an array can be divided into pairs whose sum is divisible by k. 
 
WTD: Examine the array to see if it can be segmented into pairs such that the sum of each 
pair's numbers is divisible by a specific number, k. 
 
(e.g.: I/P: [9, 7, 5, -3], k=6; O/P: True) 
*/
#include <stdio.h>

int div(int arr[], int size, int k)
{
    int track[size];
    int count = 0;

    for (int i=0; i<size; i++)
    {
        track[i] = -1;
    }

    for (int i=0; i<size-1; i++)
    {
        for (int j = i+1; j<size; j++)
        {
            if ((arr[i] + arr[j]) % k == 0 && track[i] == -1 && track[j] == -1)
            {
                count++;
                track[i] = track[j] = 1;
            }
        }
    }

    return (count == size/2);
}

int main()
{
    int arr[] = {9, 7, 5, -3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 6;

    if (div(arr, size, k))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}
