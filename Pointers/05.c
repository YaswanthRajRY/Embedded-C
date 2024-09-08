/*
5. Create a function that segregates even and odd values of an integer array using 
pointers. 
 
WTD: Use two pointers, one starting from the beginning and the other from the end. 
Traverse and swap even and odd numbers until the two pointers meet. 
 
(e.g.: I/P: int arr[] = {12,34,9,8,45,90} ,O/P: {12,34,8,90,9,45} )
*/

#include <stdio.h>

void swapEvenOrOdd(int* start, int* end)
{
    while (start < end)
    {
        if (*start % 2 == 0)
        {
            start++;
        }
        if (*end % 2 == 1)
        {
            end--;
        }

        if (*start % 2 != 0)
        {
            *start = *start ^ *end;
            *end = *start ^ *end;
            *start = *start ^ *end;

            start++;
        }
        if (*end % 2 != 1)
        {
            *start = *start ^ *end;
            *end = *start ^ *end;
            *start = *start ^ *end;
            
            end--;
        }
    }
}

int main()
{
    int arr[] = {12,34,9,8,45,90};
    int arrSize = ((size_t)(&arr+1) - (size_t)(&arr)) / 4;

    swapEvenOrOdd(&arr[0], &arr[arrSize-1]);

    for (int i=0; i<arrSize; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}