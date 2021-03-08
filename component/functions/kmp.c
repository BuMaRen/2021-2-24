#include "functions.h"

static Separator_t single_separator = SEPARATOR_NULL;

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

int stringSeparate(const char *source_string, const char *separator)
{
    int *next = getNextArray(separator);
    unsigned int source_index = 0, separator_index = 0, i = 0;
    while (separator[separator_index] && source_string[i])
    {
        if (separator[separator_index] == source_string[i])
        {
            ++i;
            ++separator_index;
        }
        else if (separator_index == 0)
        {
            ++source_index;
            i = source_index;
        }
        else
        {
            source_index += separator_index - next[separator_index];
            separator_index = (next[separator_index] == -1) ? 0 : next[separator_index];
        }
    }
    return (separator[separator_index]) ? -1 : source_index;
}

const char *cLoopCopy(char *dest, const char *source_string, const char separator, BufferSize_t size)
{
    unsigned int i = 0;
    for (; i < size-1; ++i)
    {
        if (*source_string == '\0')
        {
            dest[i] = '\0';
            return source_string;
        }
        if (separator == *source_string)
        {
            dest[i] = '\0';
            return source_string + 1;
        }
        dest[i] = *source_string;
        ++source_string;
    }
    if (separator == *source_string)
    {
        dest[i] = '\0';
        return source_string + 1;
    }
    memset(dest, 0, size);
    return NULL;
}