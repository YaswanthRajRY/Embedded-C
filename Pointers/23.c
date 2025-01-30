/*
23. Implement a custom strtok() function using pointers that splits a string based on a 
delimiter. 
WTD:  Use pointers to traverse the string. When the delimiter is found, replace it with '\0' 
and return the start of the token. 
 
(e.g.: I/P: String = "embedded,systems,linux", Delimiter = "," ; O/P: "embedded", 
"systems", "linux")
*/
#include <stdio.h>

char* custom_strtok(char* str, char dilimiter)
{
    static char* next_token = NULL;

    if (str != NULL)
    {
        next_token = str;
    }

    if (next_token == NULL)
    {
        return NULL;
    }

    char* start_token = next_token;
    while (*next_token != '\0')
    {
        if (*next_token == dilimiter)
        {
            *next_token = '\0';
            next_token++;
            return start_token;
        }
        next_token++;
    }

    if(*next_token == '\0')
    {
        return start_token;
    }

    next_token = NULL;

    return '\0';
}

int main()
{
    char str[] = "embedded,systems,linux";

    char* token = custom_strtok(str, ',');

    while (*token != '\0')
    {
        printf("%s\n", token);
        token = custom_strtok(NULL, ',');
    }

    return 0;
}