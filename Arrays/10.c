/*
10) Count occurrences of a number in a sorted array. 
 
WTD: For a given number and a sorted array, iterate through the array to count the number 
of times that particular number appears. 
 
(e.g.: I/P: [1, 2, 2, 2, 3], 2; O/P: 3 )
*/

#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 2, 2, 3};
    int num = 2;
    int size = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (num == arr[i])
            count++;
    }

    printf("%d", count);

    return 0;
}