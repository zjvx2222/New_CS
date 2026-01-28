//
// Created by 71702 on 2024/12/20.
//
#include <strings.h>
#include <sys/socket.h>
#include "Log.h"
#include <arpa/inet.h>
#include "Socket.h"
#include <iostream>
#include <unistd.h>
#define BUFFER_SIZE 1024
int main() {
    int sockfd  = socket(AF_INET,SOCK_STREAM,0);
    err(sockfd == -1, "socket create error");
    struct  sockaddr_in serv_addr;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);

    err(connect(sockfd,(sockaddr*)&serv_addr,sizeof(serv_addr))==-1,"connect error");

    while (true) {
        char buffer [BUFFER_SIZE];
        bzero(&buffer,sizeof(buffer));
        scanf("s%",buffer);
        ssize_t writes_bytes = write(sockfd,buffer,sizeof(buffer));
        if (writes_bytes == -1) {
            printf("socket already disconnected, can't write any more!\n");
            break;
        }
        bzero(&buffer,sizeof(buffer));
        ssize_t read_bytes = read(sockfd,buffer,sizeof(buffer));
        if(read_bytes > 0){
            printf("message from server: %s\n", buffer);
        }else if(read_bytes == 0){
            printf("server socket disconnected!\n");
            break;
        }else if(read_bytes == -1){
            close(sockfd);
            err(true, "socket read error");
        }

    }
    close(sockfd);
    return 0;
}
