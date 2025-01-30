/*
21. Memory Leak Detector. Implement a custom memory allocator and deallocator.Track allocations and deallocations to detect memory leaks using pointers. 
WTD:  Implement custom allocation and deallocation functions. Maintain a list of allocated blocks. On deallocation, remove from the list. At the end, 
non-deallocated blocks are leaks. 
 
(e.g.: I/P: Allocate 5 blocks, deallocate 4 blocks ; O/P: 1 block not deallocated)
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_ALLOC_SIZE 10

typedef struct Allocate
{
    void* addr;
    int size;
}Allocate_Typedef;

Allocate_Typedef Allocate_memory[MAX_ALLOC_SIZE];
int alloc_size = 0;

void* mem_alloc(int size)
{
    if (alloc_size >= MAX_ALLOC_SIZE)
    {
        printf("No space left to allocate\n");
        return NULL;
    }

    void* mem = malloc(size);

    Allocate_memory[alloc_size].addr = mem;
    Allocate_memory[alloc_size].size = size;
    alloc_size++;

    return mem;
}

void mem_dealloc(void* mem)
{
    for (int i=0; i<MAX_ALLOC_SIZE; i++)
    {
        if (Allocate_memory[i].addr == mem)
        {
            free(mem);

            if (alloc_size != 0)
            {
                Allocate_memory[i] = Allocate_memory[alloc_size];
                alloc_size--;
            }
        }
    }
}

void check_mem_leak()
{
    if (alloc_size != 0)
    {
        printf("Memory leak detected\n");
        for (int i=0; i<alloc_size; i++)
        {
            printf("Memory address: %p, size: %d\n", Allocate_memory[i].addr, Allocate_memory[i].size);
        }
    }
    else
    {
        printf("No memory leak detected\n");
    }
}

int main()
{
    void* block_1 = mem_alloc(1);
    void* block_2 = mem_alloc(4);
    void* block_3 = mem_alloc(64);

    mem_dealloc(block_1);
    //mem_dealloc(block_2);
    mem_dealloc(block_3);

    check_mem_leak();

    return 0;
}