/*
10) Count occurrences of a number in a sorted array. 
 
WTD: For a given number and a sorted array, iterate through the array to count the number 
of times that particular number appears. 
 
(e.g.: I/P: [1, 2, 2, 2, 3], 2; O/P: 3 )
*/

#include <stdio.h>

/* // Time Complexity: O(n)
int countDuplicate(int arr[], int size, int n)
{
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (n == arr[i])
        count++;
    }
    
    return count;
}
*/

 // Time COmplexity: O(log n)
int binarySearchleft(int arr[], int l, int r, int target)
{
    int index = 0;
    while (l<=r)
    {
        int mid = l + (r - l)/2;

        if (arr[mid] == target)
        {
            index = mid;
            r = mid - 1;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return index;
}

int binarySearchright(int arr[], int l, int r, int target)
{
    int index = 0;
    while (l<=r)
    {
        int mid = l + (r - l)/2;

        if (arr[mid] == target)
        {
            index = mid;
            l = mid + 1;
        }
        else if (arr[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return index;
}

int countDuplicate(int arr[], int size, int n)
{
    int left = binarySearchleft(arr, 0, size, n);
    int right = binarySearchright(arr, 0, size, n);
    
    return right - left + 1;
}

int main()
{
    int arr[] = {1, 1, 1, 1, 2, 2, 2, 2, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = 2;

    int res = countDuplicate(arr, size, num);

    printf("%d", res);

    return 0;
}