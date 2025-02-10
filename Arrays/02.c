/*
2) Find the duplicate number on a given integer array. 
 
WTD: Inspect the provided array. Determine if there's any integer that appears more 
frequently than it should, signifying a duplicate. 
 
(e.g.: I/P: [3,1,3,4,2]; O/P: 3 
*/

#include <stdio.h>

/*// Time complexity O(n^2)
int findDup(int arr[], int size)
{
    for (int i = 0; i<size; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (arr[i] == arr[j])
            {
                return arr[i];
            }
        }
    }

    return -1;
}
*/

// Time complexity O(n)
int findDup(int arr[], int size)
{
    int hash[10] = {0};

    for (int i = 0; i<size; i++)
    {
        if (hash[arr[i]] > 0)
            return arr[i];
        hash[arr[i]]++;
    }

    return -1;
}

/*// using unordered set in c++
int findDup(int arr[], int size)
{
    unordered_set<int> seen;

    for (int i = 0; i<size; i++)
    {
        if (seen.count > 0)
            return arr[i];
        seen.insert(arr[i]);
    }

    return -1;
}
*/

int main()
{
    int arr[] = {3,1,3,4,2};
    int size = sizeof(arr) / sizeof(arr[0]) ;

    int res = findDup(arr, size);

    printf("Duplicate number: %d", res);

    return 0;
}