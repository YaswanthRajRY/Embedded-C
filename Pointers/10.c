/*
10. Create a function that rotates an array to the right by `k` elements using pointers. 
 
WTD: Reverse the whole array, then reverse the first k elements, and finally reverse the 
rest. 
 
(e.g.: I/P: int arr[] = {1,2,3,4,5}, k=2 ,O/P: {4,5,1,2,3} )
*/
#include <stdio.h>

void reverseArray(int arr[], int left, int right)
{
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

void rotateRight(int arr[], int size, int k)
{
    reverseArray(arr, 0, size-1);
    reverseArray(arr, 0, k-1);
    reverseArray(arr, k, size-1);
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    rotateRight(arr, size, k);

    for (int i=0; i<size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}