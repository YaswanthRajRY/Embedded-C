/*
9. Design a program to find the overlapping part of two arrays using pointers. 
WTD: Use two pointers to traverse both arrays. When a common element is found, move 
both pointers forward. 
 
(e.g.: I/P: int arr1[] = {1,2,3,4,5,6}, arr2[] = {5,6,7,8} ,O/P: {5,6} )
*/
#include <stdio.h>
#include <stdlib.h>

int* findOverlappingPart(int arr1[], int arr2[], int s1, int s2, int* len)
{
    int* res = (int*)malloc(sizeof(int) * s2);
    int i = 0;
    int j = 0;

    while (i < s1 && j < s2)
    {
        if (arr1[i] == arr2[j])
        {
            res[(*len)++] = arr2[j++];
        }
        i++;
    }

    return (int*)realloc(res, sizeof(int) * (*len));
}

int main()
{
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {5,6,7,8};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int len = 0;

    int* res = findOverlappingPart(arr1, arr2, size1, size2, &len);

    for (int i=0; i<len; i++)
    {
        printf("%d ",res[i]);
    }

    return 0;
}

