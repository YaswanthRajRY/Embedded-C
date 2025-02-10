/*
9) Rotate an array to the right by k steps. 
 
WTD: Modify the array by moving its elements to the right, wrapping them around when 
they reach the end, for a specified number of steps. 
 
(e.g.: I/P: [1,2,3,4,5], k=2; O/P: [4,5,1,2,3] ) 
*/

#include <stdio.h>

/*// Time Complexity: O(nm);
void rotateRight(int arr[], int len, int n)
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
*/

 // Time Complexity: O(m)
void reverseArray(int arr[], int l, int r)
{
    while (l<r)
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;

        l++;
        r--;
    }
}

void rotateRight(int arr[], int len, int n)
{    
    reverseArray(arr, 0, len-1);
    reverseArray(arr, n, len-1);
    reverseArray(arr, 0, n-1);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int n = 2;

    rotateRight(arr, len, n);

    for(int i=0; i<len; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}