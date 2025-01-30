/*
24. Design a function similar to memcpy() that copies memory areas using pointers. 
 
WTD: Use pointers to traverse both the source and destination and copy each byte. 
 
(e.g.: I/P: Source = "hello", Destination (empty buffer), Length = 5 ; O/P: Destination = 
"hello") 
*/
#include <stdio.h>
#include <string.h>

void custom_memcpy(void* dest, void* src, int len)
{
    char* s = (char*)src;
    char* d = (char*)dest;

    for (int i=0; i<len; i++)
    {
        *d++ = *s++;
    }
}

int main()
{
    char source[] = "hello";
    int len = strlen(source);
    char destination[len+1];

    custom_memcpy(destination, source, len+1);

    printf("%s", destination);

    return 0; 
}