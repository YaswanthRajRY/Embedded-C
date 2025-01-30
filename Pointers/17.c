/*
17. Write a function to calculate the dot product of two vectors using pointers. 
 
WTD: Traverse both vectors, multiplying corresponding elements and summing the results. 
 
(e.g.: I/P: int vec1[] = {1,2,3}, vec2[] = {4,5,6} ,O/P: 32 )
*/
#include <stdio.h>

int dotProduct(int arr1[], int len1, int arr2[], int len2)
{
    int i = 0;
    int j = 0;
    int product = 0;

    while (i < len1 && j < len2)
    {
        product += arr1[i++] * arr2[j++];
    }

    return product;
}

int main()
{
    int vec1[] = {1,2,3};
    int vec2[] = {4,5,6};
    int len1 = sizeof(vec1)/sizeof(vec1[0]);
    int len2 = sizeof(vec2)/sizeof(vec2[0]);

    int product = dotProduct(vec1, len1, vec2, len2);

    printf("%d", product);

    return 0;
}