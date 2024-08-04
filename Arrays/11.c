/*
11) Find the "Kth" max and min element of an array. 
 
WTD: Sort the array and retrieve the kth largest and kth smallest numbers. 
 
(e.g.: I/P: [7, 10, 4, 3, 20, 15], K=3; O/P: 7 )
*/

#include <stdio.h>

void sortAsc (int *arr, int n)
{
    int swapFlag;
    for (int i=0; i < n-1; i++)
    {
        swapFlag = 0;
        for (int j=i; j<n-1; j++)
        {
            if (*(arr+i) > *(arr+j))
            {
                int temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
                swapFlag = 1;
            }

        }
        if (swapFlag == 0)
            break;
    }
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int num = 3;
    int size = sizeof(arr) / sizeof(arr[0]);

    sortAsc(arr, size);

    for (int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n%d", arr[num - 1]);

    return 0;    
}