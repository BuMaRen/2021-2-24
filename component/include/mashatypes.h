
// type for Separator_t
#define SEPARATOR_NULL      0
#define SEPARATOR_SINGLE    1
#define SEPARATOR_MUTI      2

#define MASHA_SPACE " "
#define MASHA_CRLF "\r\n"

// Request Line
#define DEFAULT_HTTP_METHOD_LENGTH 12
#define DEFAULT_HTTP_URI_LENGTH 1024
#define DEFAULT_HTTP_VERSION_LENGTH 12

typedef int Socketfd_t;
typedef uint16_t Port_t;
typedef unsigned int BufferSize_t;
typedef enum {False = 0, True = 1}Bool;

typedef unsigned char Separator_t;
