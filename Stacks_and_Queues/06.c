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

typedef struct stack
{
    int top;
    char* data;
}Stack;

void initStack(Stack** stack_ref, int len)
{
    (*stack_ref)->data = (char*)malloc(sizeof(char) * len);
    if ((*stack_ref)->data == NULL)
    {
        printf("Failed allocation memory\n");
    }
    (*stack_ref)->top = 0;
}

void push(Stack** stack_ref, char str)
{
    (*stack_ref)->data[(*stack_ref)->top++] = str;
}

char pop(Stack** stack_ref)
{
    if ((*stack_ref)->top == 0)
    {
        printf("Stack is empty\n");
        return '\0';
    }
    char s = (*stack_ref)->data[--(*stack_ref)->top];
    return s;
}

int checkPalindrome(Stack** stack_ref, char* str)
{
    char* str_ptr = str;
    while (*str_ptr != '\0')
    {
        push(stack_ref, *str_ptr);
        str_ptr++;
    }
    str_ptr = str;
    while (*str_ptr != '\0')
    {
        char s = pop(stack_ref);
        if (*str_ptr != s)
        {
            return 0;
        }
        str_ptr++;
    }

    return 1;
}

int main()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    
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