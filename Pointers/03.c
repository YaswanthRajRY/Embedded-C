/*
3. Create a function that uses pointer arithmetic to count the number of elements in an 
array without utilizing loop constructs. 
 
WTD: Subtract the pointer to the first element from the pointer just past the last element. 
 
(e.g.: I/P: int arr[] = {1,2,3,4,5} ,O/P: 5 )
*/

#include <stdio.h>


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = ((size_t)(&arr+ 1) - (size_t)(&arr)) / 4;

    printf("%d\n", size);

    return 0;
}