/*
6) Palindrome Checker using Stack. 
WTD: Create a function that uses a stack to determine whether a given string is a 
palindrome. Push each character of the string onto a stack and then pop them off to 
compare with the original string.   
(e.g: I/P: "RACECAR" ; O/P: Palindrome)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack // create struct for stack
{
    int top;
    char* data;
}Stack;

void initStack(Stack** stack_ref, int len)
{
    (*stack_ref)->data = (char*)malloc(sizeof(char) * len); // allocate memory to store char
    if ((*stack_ref)->data == NULL)
    {
        printf("Failed allocation memory\n");
    }
    (*stack_ref)->top = 0; // initialize 0 index for empty stack
}

void push(Stack** stack_ref, char str)
{
    (*stack_ref)->data[(*stack_ref)->top++] = str; // push char in the stack and increment the top index
}

char pop(Stack** stack_ref)
{
    if ((*stack_ref)->top == 0) // if stack empty return
    {
        printf("Stack is empty\n");
        return '\0';
    }
    char s = (*stack_ref)->data[--(*stack_ref)->top]; // pop the char in the stack
    return s;
}

int checkPalindrome(Stack** stack_ref, char* str)
{
    char* str_ptr = str;
    while (*str_ptr != '\0') // iterating each char in the string
    {
        push(stack_ref, *str_ptr); // push each char into the stack
        str_ptr++; // move next char in the stack
    }
    str_ptr = str; // reinitialize str pointer
    while (*str_ptr != '\0') // iterating each char in the string
    {
        char s = pop(stack_ref); // save poped char in s
        if (*str_ptr != s) // compare poped char with Str pointer first char
        {
            return 0; // return if not equal
        }
        str_ptr++; // move next char in the stack
    }

    return 1;
}

int main()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack)); // allocate memory for struct
    
    char str[] = "RACECAR";
    int len = strlen(str);

    initStack(&stack, len);
    if(checkPalindrome(&stack, str))
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a palindrome\n");
    }

    return 0;
}
