#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "mashalib.h"


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
    if ((handle = accept(listenfd, (struct sockaddr *)&peer_addr, &peer_addr_size)) >= 0)
    {
        printf("handle is %d\n", handle);
        close(handle);
    }
    else
    {
        perror("accept failed!");
        close(listenfd);
        return -1;
    }
    close(listenfd);
    return 0;
}