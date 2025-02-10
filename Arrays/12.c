/*
12) Move all zeros to the left of an array while maintaining the order of other numbers. 
 
WTD: Reorder the array by moving all zero values to the leftmost positions while ensuring 
the relative order of the non-zero numbers remains unchanged. 
 
(e.g.: I/P: [1,2,0,4,3,0,5,0]; O/P: [0,0,0,1,2,4,3,5] )
*/

#include <stdio.h>

/*// Time Complexity: O(n^2)
void swap(int* arr, int n)
{
    int temp = *(arr+n); 
    for(int i=n; i>0; i--)
    {
        *(arr+i) = *(arr+i-1);
    }
    *(arr) = temp;
}

void reorderArr(int* arr, int size)
{
    for (int i=0; i<size; i++)
    {
        if (*(arr+i)==0)
        {
            swap(arr,i);
        }
    }
}
*/

 // Time Complexity: O(n)
void reorderArr(int* arr, int size)
{
    int index = size-1; 
    for (int i = size-1; i>=0; i--)
    {
        if (arr[i] != 0)
        {
            arr[index--] = arr[i];
        }
    }

    while (index >= 0)
    {
        arr[index--] = 0;
    }
}

void printarr(int* arr, int size)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,2,0,4,3,0,5,0};
    int size = sizeof(arr) / sizeof(arr[0]);
    printarr(arr,size);

    reorderArr(arr, size);

    printarr(arr,size);

    return 0;   
}