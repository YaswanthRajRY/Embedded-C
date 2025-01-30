/*
19. Implement a function that finds the common elements in three sorted arrays using 
pointers. 
WTD: Use three pointers. Move the pointer pointing to the smallest value until all three 
pointers point to the same value or the end is reached. 
 
(e.g.: I/P: int arr1[] = {1,5,10,20,40,80}, arr2[] = {6,7,20,80,100}, arr3[] = {3,4,15,20,30,70,80,120} ,O/P:{20,80} )
*/
#include <stdio.h>
#include <stdlib.h>

int* findCommonElement(int arr1[], int l1, int arr2[], int l2, int arr3[], int l3, int* len)
{
    int* array = (int*)malloc(sizeof(int) * (l1 + l2 + l3));
    int i = 0;
    int j = 0;
    int k = 0;

    while ((i < l1) && (j < l2) && (k < l3))
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            array[(*len)++] = arr1[i];
            i++;
            j++;
            k++;
        }
        else if (arr1[i] < arr2[j] && arr1[i] < arr3[k])
        {
            i++;
        }
        else if (arr2[j] < arr1[i] && arr1[j] < arr3[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }

    return (int*)realloc(array, sizeof(int) * (*len));
}

int main()
{
    int arr1[] = {1,5,10,20,40,80};
    int arr2[] = {6,7,20,80,100};
    int arr3[] = {3,4,15,20,30,70,80,120};

    int l1 = sizeof(arr1)/sizeof(arr1[0]);
    int l2 = sizeof(arr2)/sizeof(arr2[0]);
    int l3 = sizeof(arr3)/sizeof(arr3[0]);

    int len = 0;

    int* res = findCommonElement(arr1, l1, arr2, l2, arr3, l3, &len);

    for (int i=0; i<len; i++)
    {
        printf("%d ", res[i]);
    }

    return 0;
}