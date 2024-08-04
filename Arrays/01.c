/*
1) Find the missing number in a given integer array of 1 to 500. 
 
WTD: Examine an array expected to contain consecutive integers from 1 to 500. Identify 
any integer that is missing from this sequence. 
 
(e.g.: I/P: [1,2,4,5]; O/P: 3)
*/

#include <stdio.h>

int main()
{
    int a, b, size;
    printf("Enter array size: ");
    scanf("%d", &size);

    int arr[size - 1];

    for (int i=0; i<size - 1; i++)
        scanf("%d", &arr[i]);

    a = arr[0];
    for (int i = 1; i< size - 1; i++)
        a = a ^ arr[i];

    b = 1;
    for (int i=2; i <= size; i++)
        b = b ^ i;
    
    printf("\nThe missing number: %d", a^b);

    return 0;
}