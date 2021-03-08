#include "mashatypes.h"
#include "functions.h"

// what if *request_line == '\0'
// file kmp.c functions.h mashatypes.h
static Bool requestLine(const char *request_line, char *method, char *request_uri, char *http_version)
{
    request_line = cLoopCopy(method, request_line, ' ', DEFAULT_HTTP_METHOD_LENGTH);
    if (!request_line)
    {
        printf("method : buffer of dest is not enough\n");
        return False;
    }

    request_line = cLoopCopy(request_uri, request_line, ' ', DEFAULT_HTTP_URI_LENGTH);
    if (!request_line)
    {
        printf("request_uri : buffer of dest is not enough\n");
        return False;
    }

    request_line = cLoopCopy(http_version, request_line, '\0', DEFAULT_HTTP_URI_LENGTH);
    if (!request_line)
    {
        printf("request_uri : buffer of dest is not enough\n");
        return False;
    }

    #if 0 implement by stringSeparate
    int size = stringSeparate(request_line, MASHA_SPACE);
    if (size == -1 || size > DEFAULT_HTTP_METHOD_LENGTH) return False;
    memcpy(method, request_line, size);
    request_line += size + 1;

    size = stringSeparate(request_line, MASHA_SPACE);
    if (size == -1 || size > DEFAULT_HTTP_URI_LENGTH) return False;
    memcpy(request_uri, request_line, size);
    request_line += size + 1;

    size = stringSeparate(request_line, MASHA_SPACE);
    if (size == -1 || size > DEFAULT_HTTP_VERSION_LENGTH) return False;
    memcpy(http_version, request_line, size);
    
    return True;
    #endif
}

void requestHandle(char *http_request)
{
    char method[DEFAULT_HTTP_METHOD_LENGTH] = {0};
    char request_uri[DEFAULT_HTTP_URI_LENGTH] = {0};
    char http_version[DEFAULT_HTTP_VERSION_LENGTH] = {0};

}
