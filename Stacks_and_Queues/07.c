/*
7) Queue-based Sequence Generator. 
WTD: Design a queue-based system that can generate the Fibonacci sequence up to n 
numbers. The queue should be used to store intermediate Fibonacci numbers and help in 
generating subsequent numbers in the sequence.   
(e.g: I/P:  n = 5  ; O/P: 0, 1, 1, 2, 3)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue // createstruct for queue
{
    int start;
    int end;
    int* data;
}Queue;

void initQueue(Queue** queue_ref, int len)
{
    (*queue_ref)->data = (int*)malloc(sizeof(int) * len); // allocate memory to store data
    (*queue_ref)->start = 0; // initialize start pointer value for empty queue
    (*queue_ref)->end = 0; // initialize end pointer value for empty queue
}

void enQueue(Queue** queue_ref, int data)
{
    (*queue_ref)->data[(*queue_ref)->end++] = data; // add data in the queue and increment end pointer
}

void deQueue(Queue** queue_ref)
{
    if ((*queue_ref)->start == (*queue_ref)->end) // return if start and end pointer are equal
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d->",(*queue_ref)->data[(*queue_ref)->start++]); // print first data in the queue and decrement start pointer
}

void fibonacciNum(Queue** queue_ref, int len)
{
    initQueue(queue_ref, len); // initialize queue start and end pointer
    int num = 1;
    enQueue(queue_ref, 0); 
    enQueue(queue_ref, 1);

    for (int i=0; i<len-2; i++) // generate fibonacci series of number 
    {
        enQueue(queue_ref, num+i);
    }

    for (int i=0; i<len; i++) // dequeue each num in the queue
    {
        deQueue(queue_ref);
    }
}

int main()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue)); // allocate memory for queue struct
    int len = 5;

    fibonacciNum(&queue, len);

    free(queue->data); // free allocated memory
    free(queue); // free allocated memory
    
    return 0;
}
