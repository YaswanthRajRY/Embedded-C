/*
11) Find the "Kth" max and min element of an array. 
 
WTD: Sort the array and retrieve the kth largest and kth smallest numbers. 
 
(e.g.: I/P: [7, 10, 4, 3, 20, 15], K=3; O/P: 7 )
*/

#include <stdio.h>
#include <stdlib.h>

/* // Time Complexity: O(n^2)
int* findMinMax (int *arr, int n, int num)
{
    int* result = (int*)malloc(sizeof(int) * n);
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

    result[0] = (num+1 >= 0) ? arr[num-1] : -1;
    result[1] = (num+1 < n) ? arr[num+1] : -1;

    return result;
}
*/

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

 // Time Complexity: O(n^2)
int* findMinMax (int *arr, int n, int num)
{
    int* result = (int*)malloc(sizeof(int) * n);

    qsort(arr, n, sizeof(int), compare);

    result[0] = (num+1 >= 0) ? arr[num-1] : -1;
    result[1] = (num+1 < n) ? arr[num+1] : -1;

    return result;
}

int main()
{
    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = 3;

    int* res = findMinMax(arr, size, num);

    printf("min: %d\nmax: %d", res[0], res[1]);

    return 0;    
}