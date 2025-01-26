/*
18) Find the equilibrium index of an array (where sum of elements on the left is equal to 
sum on the right). 
 
WTD: Examine the array to find an index where the sum of all elements to its left is equal 
to the sum of all elements to its right. 
 
(e.g.: I/P: [-7, 1, 5, 2, -4, 3, 0]; O/P: 3)
*/
#include <stdio.h>

int findEquilibriumIndex(int arr[], int size)
{
    int sum = 0;

    for(int i=0; i<size; i++)
    {
        sum += arr[i];
    }

    int leftSum = 0;

    for (int i=0; i<size; i++)
    {
        int rightSum = sum - leftSum - arr[i];

        if (leftSum == rightSum)
        {
            return i;
        }

        leftSum += arr[i];
    }

    return -1;
}

int main()
{
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int size = sizeof(arr)/sizeof(arr[0]);

    int index = findEquilibriumIndex(arr, size);

    printf("The eqilibrium index is %d", index);

    return 0;
}