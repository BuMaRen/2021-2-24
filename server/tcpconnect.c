#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include "mashalib.h"

#define BUFFER_SIZE 512

void processConnection(Socketfd_t handle)
{
    ssize_t read_len = 0;
    char buffer[BUFFER_SIZE];
    do
    {
        bzero(buffer, BUFFER_SIZE);
        read_len = recv(handle, (void *)buffer, BUFFER_SIZE, 0/*MSG_DONTWAIT*/);
        if (read_len > 0)
        {
            unsigned int i = 0;
            char printf_buffer[BUFFER_SIZE] = {0};
            char *ptr = printf_buffer;
            for(;i < read_len; ++i)
            {
                ptr += sprintf(ptr, "%02x ", buffer[i]);
            }
            printf("read : %s\n", printf_buffer);
        }
        else
            printf("read_len = %d, next loop\n", read_len);
        sleep(1);
    }while((read_len > 0) || (read_len < 0 && (errno == EAGAIN || errno == EWOULDBLOCK)));
}

int main()
{
    Socketfd_t listenfd = socket(AF_INET, SOCK_STREAM, 0);

    Port_t port = htons(43997);
    struct sockaddr_in sock_addr = {
        .sin_family = AF_INET,
        .sin_addr = INADDR_ANY,
        .sin_port = port
    };

    if (bind(listenfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)))
    {
        perror("bind failed!");
        close(listenfd);
        return -1;
    }
    else
    {
        printf("bind successfully!\n");
    }

    if (listen(listenfd, 5))
    {
        perror("listen failed!");
        close(listenfd);
        return -1;
    }
    else
    {
        printf("listen on port 43997!\n");
    }

    struct sockaddr_in peer_addr;
    Socketfd_t handle;
    socklen_t peer_addr_size;
    while(1)
    {
        if ((handle = accept(listenfd, (struct sockaddr *)&peer_addr, &peer_addr_size)) >= 0)
        {
            printf("handle is %d\n", handle);
            processConnection(handle);
            close(handle);
        }
        else
        {
            perror("accept failed!");
            close(listenfd);
            return -1;
        }
    }
    return 0;
}
