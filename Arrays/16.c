/*
16) Rearrange positive and negative numbers in an array. 
 
WTD: Sort the array such that all the positive numbers appear before the negative ones, 
while maintaining their original sequence. 
(e.g.: I/P: [-1, 2, -3, 4, 5, 6, -7, 8, 9]; O/P: [2,4,5,6,8,9,-1,-3,-7] )
*/

#include <stdio.h>
#include <stdlib.h>

/* // Time complexity: O(n)
void sort(int* arr, int l)
{
    int n = 0;
    int m = 0;
    int flag = 1;

    int* pos = (int*)malloc(sizeof(int) * l);
    int* neg = (int*)malloc(sizeof(int) * l);

    for (int i=0; i<l; i++)
    {
        if (arr[i] >= 0)
        {
            pos[n++] = arr[i];
        }   
        else
        {
            neg[m++] = arr[i];
        }
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n)
    {
        arr[k++] = pos[i++];
    }
    while (j < m)
    {
        arr[k++] = neg[j++];
    }

    free(pos);
    free(neg);
}
*/

 // Time complexity: O(n)
void sort(int arr[], int l)
{
    int k = 0;
    for (int i=0; i<l; i++)
    {
        if (arr[i] >= 0)
        {
            int temp = arr[i];
            
            for (int j=i; j>k; j--)
            {
                arr[j] = arr[j-1];
            }
            
            arr[k++] = temp;
        }
    }
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int l = sizeof(arr)/sizeof(arr[0]);

    sort(arr, l);

    for (int i=0; i<l; i++)
    {
        printf("%d, ",arr[i]);
    }
    return 0;
}