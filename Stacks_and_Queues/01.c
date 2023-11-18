/*
1) Byte-Packing Stack. 
WTD: Design a stack that efficiently stores 8-bit data in a continuous memory space. 
Ensure that the 32-bit words are packed without any wastage.   
(e.g: I/P: Push 0x01, 0x02, 0x03, 0x04 ; O/P: Memory content - 0x04030201) 
*/

#include <stdio.h>
#include <stdint.h>

#define STACK_SIZE 3

typedef struct {
    unsigned int data[STACK_SIZE]; 
    int top;      
    int bit;
} Stack;

void initStack(Stack* stack)
{
    stack->bit = 0;
    stack->top = 0;
    stack->data[stack->top] = 0;
}

void push(Stack* stack, unsigned int value) 
{
    if (stack->top > 2)
    {
        printf("Stack is full\n");
        return;
    }    
    if (stack->bit == 4)
    {
        stack->top++;
        stack->bit = 0;
        stack->data[stack->top] = 0;
    }  
    value <<= (stack->bit * 8);
    stack->data[stack->top] |= value;
    stack->bit++; 
}

void pop(Stack* stack)
{
    if (stack->top < 0)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Memory content: 0x%X\n",stack->data[stack->top--]);
}

int main() 
{
    Stack stack;

    initStack(&stack);

    push(&stack, 0x11);
    push(&stack, 0x22);
    push(&stack, 0x33);
    push(&stack, 0x44);

    push(&stack, 0x10);
    push(&stack, 0x20);
    push(&stack, 0x30);
    push(&stack, 0x40);
    
    pop(&stack);
    pop(&stack);
    pop(&stack);

    return 0;
}
