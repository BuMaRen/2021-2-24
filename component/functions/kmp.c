#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Separator_t single_separator = SEPARATOR_NULL;

// ready for kmp
static int *getNextArray(const char *separator)
{
    if (separator == NULL || *separator == '\0') return NULL;
    char *ptr = separator + 1;
    
    if (*ptr == '\0')
    {
        single_separator = SEPARATOR_SINGLE;
        return NULL;
    }
    
    int size = strlen(separator);
    int *next = (int *)malloc(sizeof(int)*(size + 1));
    
    if (next == NULL)
    {
        perror("malloc next array failed!");
        return NULL;
    }
    
    next[0] = -1;
    next[1] = 0;
    int temp = 0;
    unsigned int i = 1;
    for (; i < size; ++i)
    {
        temp = next[i];
        while (temp != -1)
        {
            if (separator[i] == separator[temp])
            {
                next[i+1] = next[i] + 1;
                break;
            }
            else temp = next[temp];
        }
        if (temp == -1) next[i+1] = 0;
    }
    return next;
}

unsigned int stringSeparate(const char *source_string, const char *separator)
{
    int *next = getNextArray(separator);
    unsigned int source_index = 0, separator_index = 0, i = 0;
    
}