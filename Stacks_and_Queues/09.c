/*
9) Queue-based Text Filter.  
WTD: Develop a queue-based text filter that removes specific words from a given text 
string. The words to be filtered out should be enqueued and then compared against the text 
for filtering.   
(e.g: I/P: Text - "Hello world", Filter - "world" ; O/P: "Hello") 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct queue    // create structure 
{
    char* str;
    struct queue* next;
}Queue;

Queue* createNode(char* str)    //create node
{
    Queue* temp = (Queue*)malloc(sizeof(Queue));
    temp->str = str;
    temp->next = NULL;

    return temp;
}

void enQueue(Queue** queue, char* str)  // enqueue string into the queue
{
    Queue* temp = createNode(str);
    if (*queue == NULL)     // if queue is empty initiate first element in the queue
    {
        (*queue) = temp;
    }
    else    // if queue is not empty 
    {
        Queue* end = (*queue);
        while (end != NULL && end->next != NULL)    // iterate to last node
        {
            end = end->next;
        }    
        end->next = temp;   // add node at last
    }
    
}

void deQueue(Queue** queue)
{
    if ((*queue) == NULL)   // return if queue is empty
    {
        return;
    }
    else
    {
        Queue* temp = (*queue);     // temp node 
        (*queue) = (*queue)->next;  //move pointer to next node
        free(temp);     // free enqueued memeory
    }
}

int main()
{
    Queue* queue = NULL;

    char string[] = "Hello World";
    char removeStr[] = "World";
    
    char* s = strtok(string," ");       // strtok lib function to tokenize the string set delimiter as " "

    while (s != NULL)
    {
        enQueue(&queue, s);
        s = strtok(NULL, " ");      // tokenize the string till null
    } 
    
    while (queue != NULL)   // dequeue till empty
    {
        if (strcmp(queue->str, removeStr) != 0)     // print string which is not equal to filter string 
        {
            printf("%s\n", queue->str);     
        }
        deQueue(&queue);    
    }

    return 0;
}