/*
7) Queue-based Sequence Generator. 
WTD: Design a queue-based system that can generate the Fibonacci sequence up to n 
numbers. The queue should be used to store intermediate Fibonacci numbers and help in 
generating subsequent numbers in the sequence.   
(e.g: I/P:  n = 5  ; O/P: 0, 1, 1, 2, 3)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int start;
    int end;
    int* data;
}Queue;

void initQueue(Queue** queue_ref, int len)
{
    (*queue_ref)->data = (int*)malloc(sizeof(int) * len);
    (*queue_ref)->start = 0;
    (*queue_ref)->end = 0;
}

void enQueue(Queue** queue_ref, int data)
{
    (*queue_ref)->data[(*queue_ref)->end++] = data;
}

void deQueue(Queue** queue_ref)
{
    if ((*queue_ref)->start == (*queue_ref)->end)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("%d->",(*queue_ref)->data[(*queue_ref)->start++]);
}

void fibonacciNum(Queue** queue_ref, int len)
{
    initQueue(queue_ref, len);
    int num = 1;
    enQueue(queue_ref, 0);
    enQueue(queue_ref, 1);

    for (int i=0; i<len-2; i++)
    {
        enQueue(queue_ref, num+i);
    }

    for (int i=0; i<len; i++)
    {
        deQueue(queue_ref);
    }
}

int main()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    int len = 5;

    fibonacciNum(&queue, len);

    free(queue->data);
    free(queue);
    
    return 0;
}