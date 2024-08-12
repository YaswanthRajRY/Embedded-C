/*
14) Find the majority element in an array (appears more than n/2 times). 
 
WTD: Traverse the array and maintain a count of each number. Identify if there's any 
number that appears more than half the length of the array. 
 
(e.g.: I/P: [3,3,4,2,4,4,2,4,4]; O/P: 4 )
*/

#include <stdio.h>

int find_majority_element(int arr[], int n) {
    if (n == 0) return -1;
    
    int candidate = -1;
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
        }
        count += (arr[i] == candidate) ? 1 : -1;
    }
    
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }
    
    if (count > n / 2) {
        return candidate;
    }
    
    return -1;
}

int main() {
    int arr[] = {4,3,4,3,4,4,4,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = find_majority_element(arr, n);
    
    if (result != -1) {
        printf("Majority element is %d\n", result);
    } else {
        printf("No majority element found\n");
    }
    
    return 0;
}
