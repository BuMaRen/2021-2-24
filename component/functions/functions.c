#include "functions.h"

static unsigned int isSeparator(const char *separator, const char *buffer)
{
    unsigned int i = 0;
    while(*separator && *buffer)
    {
        if (*separator != *buffer) 
        {
            return 0;
        }
        else
        {
            ++separator;
            ++buffer;
            ++i;
        }
    }
    return (*separator) ? 0 : i;
}
void readBySeparator(const char *src, char *separator, char *dest, BufferSize_t dest_capacity)
{
    while (!isSeparator(separator, src))
    {
        *dest = *src;
        ++dest;
        ++src;
    }
}
