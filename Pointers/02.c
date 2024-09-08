/*
2. Design a function that determines if two pointers point to the same array. 
 
WTD: Traverse from both pointers in both forward and backward directions until null or 
boundary is hit. If both pointers hit the same boundaries, they belong to the same array. 
 
(e.g.: I/P: int arr[] = {1,2,3,4}, *ptr1 = &arr[1], *ptr2 = &arr[3]; O/P: True )
*/

#include <stdio.h>
#include <stdbool.h>

bool find(int* ptr1, int* ptr2, int arrSize)
{
    if ((size_t)ptr1 < (size_t)ptr2)
    {
        int* temp = ptr1;
        ptr1 = ptr2;
        ptr2 = temp;
    }

       for (int i=0; i<arrSize; i++)
       {
            if (ptr1 == ptr2)
            {
                return true;
            }
            ptr2++;
       }

       return false;
}

int main()
{
    int arr_1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr_1) / sizeof(arr_1[0]);

    int* ptr_1 = &arr_1[1];
    int* ptr_2 = &arr_1[4];

    if(find(ptr_1, ptr_2, size))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }

    return 0;
}