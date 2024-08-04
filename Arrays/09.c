/*
9) Rotate an array to the right by k steps. 
 
WTD: Modify the array by moving its elements to the right, wrapping them around when 
they reach the end, for a specified number of steps. 
 
(e.g.: I/P: [1,2,3,4,5], k=2; O/P: [4,5,1,2,3] ) 
*/

#include <stdio.h>

void rotate(int arr[], int len, int n)
{    
    while(n--)
    {
        int temp = arr[len-1];
        for (int i=len-1; i>=0; i--)
        {
            arr[i] = arr[i-1];
        }
        arr[0] = temp;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = 2;
    int len = sizeof(arr) / sizeof(arr[0]);
    rotate(arr, len, n);
    for(int i=0; i<len; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}