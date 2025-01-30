/*
20. Create a program that flattens a 2D array into a 1D array using pointers. 
WTD:  Use nested loops (or equivalent pointer arithmetic) to traverse the 2D array and 
copy each element to the 1D array. 
 
(I/P: int arr[][] = {{1,2},{3,4}} ,O/P:{1,2,3,4} )
*/
#include <stdio.h>
#include <stdlib.h>

int* flattens(int* arr, int row, int col, int* len)
{
    int* oneDarray = (int*)malloc(sizeof(int) * (row * col));

    for (int i=0; i<(row * col); i++)
    {
        oneDarray[(*len)++] = *(arr + i);
    }

    return oneDarray;
}

int main()
{
    int arr[2][2] = {{1,2},{3,4}};
    int len = 0;

    int* res = flattens((int*)arr, 2, 2, &len);

    for (int i=0; i<len; i++)
    {
        printf("%d ", res[i]);
    }

    return 0;
}