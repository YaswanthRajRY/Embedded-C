/*
25. Implement a function that detects if a pointer has gone out of bounds of an array. 
WTD: Compare the pointer with the address of the first and past-the-last elements of the 
array. 
 
(e.g.: I/P: Array = {1,2,3,4,5}, Pointer pointing after last element ; O/P: Out of bounds)
*/
#include <stdio.h>

void check_array(int arr[], int* ptr, int size)
{
    if (ptr < arr || ptr >= (arr + size))
    {
        printf("Pointer has gone out of bounds of an array\n");
    }
    else
    {
        printf("Pointer inside bounds of an array\n");
    }
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = 2;

    check_array(arr, &arr[index], size);

    return 0;
}