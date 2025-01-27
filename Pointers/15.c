/*
15. Design a function that uses pointers to find the intersection of two arrays. 
 
WTD:  If the arrays are sorted, use two pointers to traverse and find common elements. If 
not, use a hash table for one array and search for elements of the other. 
 
(e.g.: I/P: int arr1[] = {1,2,3,4}, arr2[] = {3,4,5,6} ,O/P: {3,4} )
*/
#include <stdio.h>
#include <stdlib.h>

int* findIntersection(int arr1[], int s1, int arr2[], int s2, int* len)
{
    int* array = (int*)malloc(sizeof(int) * s1);
    int i = 0;
    int j = 0;

    while ((i < s1) && (j < s2))
    {
        if (arr1[i] == arr2[j])
        {
            array[(*len)++] = arr1[i];
            i++;
            j++;
        }
        else if (arr1[i] < arr2[i])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return array;
}

int main()
{
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {3, 4, 5, 6};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int len = 0;

    int* res = findIntersection(arr1, size1, arr2, size2, &len);

    for (int i=0; i<len; i++)
    {
        printf("%d ", res[i]);
    }

    return 0;
}