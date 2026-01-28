//
// Created by 71702 on 2024/12/20.
//
#include <iostream>
#include <strings.h>
#include <unistd.h>

#include "InetAddress.h"
#include "Socket.h"
#define READ_BUFFER 1024
int main() {
    Socket* serv_sock = new Socket();
    InetAddress* serv_addr =  new InetAddress("127.0.0.1", 8888);
    serv_sock->bind(serv_addr);
    serv_sock->listen();
    InetAddress* clnt_addr = new InetAddress();
    int clntfd = serv_sock->accept(clnt_addr);
    printf("new client fd %d! IP: %s Port: %d\n",
        clntfd, inet_ntoa(clnt_addr->addr.sin_addr), ntohs(clnt_addr->addr.sin_port));
    char buf[READ_BUFFER];
    while(true){    //由于使用非阻塞IO，读取客户端buffer，一次读取buf大小数据，直到全部读取完毕
        bzero(&buf, sizeof(buf));
        ssize_t bytes_read = read(clntfd, buf, sizeof(buf));
        if(bytes_read > 0){
            printf("message from client fd %d: %s\n", clntfd, buf);
            write(clntfd, buf, sizeof(buf));
        } else if(bytes_read == -1 && errno == EINTR){  //客户端正常中断、继续读取
            printf("continue reading");
            continue;
        } else if(bytes_read == -1 && ((errno == EAGAIN) || (errno == EWOULDBLOCK))){//非阻塞IO，这个条件表示数据全部读取完毕
            printf("finish reading once, errno: %d\n", errno);
            break;
        } else if(bytes_read == 0){  //EOF，客户端断开连接
            printf("EOF, client fd %d disconnected\n", clntfd);
            close(clntfd);   //关闭socket会自动将文件描述符从epoll树上移除
            break;
        }
    }
    delete serv_sock;
    delete serv_addr;
    return 0;
}

