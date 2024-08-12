/*
15) Find the two repeating elements in a given array. 
 
WTD: Investigate the array and find two numbers that each appear more than once. 
 
(e.g.: I/P: [4, 2, 4, 5, 2, 3, 1]; O/P: [4,2] ) 
*/

#include <stdio.h>
#include <stdlib.h>

int* find_repeating_element(int arr[], int n, int* size) {
    int* array = (int*)malloc(sizeof(int) * n);

    for (int i=0; i<n-1; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (arr[i] == arr[j])
            {
                int found = 0;
                for (int k=0; k < *size; k++)
                {
                    if (array[k] == arr[i])
                    {
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    array[(*size)++] = arr[i];
                }
            }
        }
    }
    array = (int*)realloc(array, sizeof(int)* (*size));
    return array;
}

int main() {
    int arr[] = {4,3,4,3,4,4,4,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int size = 0;
    
    int* result = find_repeating_element(arr, n, &size);
    
    for (int i=0; i<size; i++)
    {
        printf("Repeating element %d\n", result[i]);
    }
    return 0;
}