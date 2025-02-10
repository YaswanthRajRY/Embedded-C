/*
24) Find if an array can be divided into pairs whose sum is divisible by k. 
 
WTD: Examine the array to see if it can be segmented into pairs such that the sum of each 
pair's numbers is divisible by a specific number, k. 
 
(e.g.: I/P: [9, 7, 5, -3], k=6; O/P: True) 
*/
#include <stdio.h>
#include <stdlib.h>

/* // Time Complexity: O(n^2)
int canPair(int arr[], int size, int k)
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
*/
 // Time Complexity: O(n)
int canPair(int arr[], int size, int k)
{
    int* freq = (int*)calloc(k, sizeof(int));

    for (int i=0; i<size; i++)
    {
        int num = arr[i] % k;
        if (num < 0)
            num += k;
        freq[num]++;
    }

    if (freq[0] % 2 != 0)
        return 0;
    
    for (int i=1; i<k/2; i++)
    {
        if (freq[i] != freq[k - i])
            return 0;
    }

    free(freq);
    return 1;
}

int main()
{
    int arr[] = {9, 7, 5, -3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 6;

    if (canPair(arr, size, k))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}
