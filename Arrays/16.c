/*
16) Rearrange positive and negative numbers in an array. 
 
WTD: Sort the array such that all the positive numbers appear before the negative ones, 
while maintaining their original sequence. 
(e.g.: I/P: [-1, 2, -3, 4, 5, 6, -7, 8, 9]; O/P: [2,-3,4,-1,9,-7,4,8,6] )
*/

#include <stdio.h>
#include <stdlib.h>

int* sort(int* arr, int l)
{
    int n = 0;
    int m = 0;
    int flag = 1;

    int* pos = (int*)malloc(sizeof(int));
    int* neg = (int*)malloc(sizeof(int));

    for (int i=0; i<l; i++)
    {
        if (arr[i] >= 0)
        {
            pos[n++] = arr[i];
            int* temp1 = (int*)realloc(pos, sizeof(int) * (n+1));
            pos = temp1;
        }   
        else
        {
            neg[m++] = arr[i];
            int* temp2 = (int*)realloc(neg, sizeof(int) * (m+1));
            neg = temp2;
        }
    }

    for (int i=0; i<l; i++)
    {
        if (flag == 1)
        {
            arr[i] = *(pos++);
            if (neg != NULL)
                flag = -1;
        }
        else if (flag == -1)
        {
            arr[i] = *(neg);
            if (pos != NULL)
                flag = 1;
        }
    }
    return arr;
}

int main()
{
    int arr[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    int l = sizeof(arr)/sizeof(arr[0]);

    int* res = sort(arr, l);

    for (int i=0; i<(sizeof(arr)/sizeof(arr[0])); i++)
    {
        printf("%d, ",res[i]);
    }
    printf("\n");
    return 0;
}