/*
5) Find duplicate numbers in an array if it contains multiple duplicates. 
 
WTD: Examine the array to identify numbers that appear more than once. Compile a list of 
these repetitive numbers. 
 
(e.g.: I/P: [4,3,2,7,8,2,3,1]; O/P: [2,3])
*/

#include <stdio.h>

/*// Time Complexity: O(n^2)
void dupArray(int* arr, int len)
{
    int dup = 1;
    for (int i=0; i<len-1; i++)
    {
        for (int j=i+1; j<len; j++)
        {
            if (*(arr+i) == *(arr+j))
            {
                dup = 0;
                printf ("%d ",*(arr+i));
            }
        }
    }
    
    if (dup)
    {
        printf("No duplicate number");
    }
}
*/

 // Time Complexity: O(n)
 void dupArray(int* arr, int len)
 {
    int hash[100] = {0};
    int found = 0;

    for (int i=0; i<len; i++)
    {
        if (hash[arr[i]] > 0)
        {
            printf("%d ", arr[i]);
        }
        else
        {
            hash[arr[i]]++;
        }
    }

    if (found)
        printf("No duplicate number\n");
 }

int main()
{
    int arr[] = {4,3,2,7,8,2,3,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    dupArray(arr, len);

    return 0;
}