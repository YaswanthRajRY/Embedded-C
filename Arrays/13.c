/*
13) Merge two sorted arrays to produce one sorted array. 
 
WTD: Sequentially compare the elements of two sorted arrays, combining them into a 
single array that remains sorted. 
 
(e.g.: I/P: [1,3,5], [2,4,6]; O/P: [1,2,3,4,5,6] )
*/

#include<stdio.h>
#include<stdlib.h>

void mergeArr(int* a, int* a1, int* a2, int s1, int s2 )
{
    for (int i=0; i<s1; i++)
    {
        *(a+i) = *(a1+i);
    }
    for (int i=0; i<s2; i++)
    {
        *(a+s1+i) = *(a2+i);
    }
}

void printArr(int* arr, int size)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void sortArr(int arr)
{

}

int main()
{
    int arr_A[] = {1,3,5};
    int arr_B[] = {2,4,6};

    int size_A = sizeof(arr_A) / sizeof(arr_A[0]);
    int size_B = sizeof(arr_B) / sizeof(arr_B[0]);
    int Totalsize = size_A + size_B;
    int arr[Totalsize];

    mergeArr(arr, arr_A, arr_B, size_A, size_B);
    sortArr(arr);
    printArr(arr, Totalsize);
     
    return 0;
}