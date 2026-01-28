//
// Created by 71702 on 2024/12/20.
//

#include "Socket.h"

#include <unistd.h>

#include "InetAddress.h"
#include "Log.h"
#include <sys/socket.h>


Socket::Socket():_fd(-1) {
    _fd = socket(AF_INET,SOCK_STREAM,0);
    err(_fd == -1,"spcket create error");
}
Socket::Socket(int fd):_fd(fd) {
    err(fd == -1, "socket create error");
}
Socket::~Socket(){
    if(_fd != -1){
        close(_fd);
        _fd = -1;
    }
}
void Socket::bind(InetAddress* addr) {
    err(::bind(_fd,(sockaddr*)&addr->addr,addr->addr_len),"socket bind error\n");
}
void Socket::listen() {
    err(::listen(_fd,SOMAXCONN)==-1,"socket listen error\n");
}
int Socket::accept(InetAddress *addr) {
    int clnt_sockfd = ::accept(_fd,(sockaddr*)&addr->addr,&addr->addr_len);
    err(clnt_sockfd == -1,"socket accept error");
    return clnt_sockfd;
}
int Socket::GetFd() {
    return _fd;
}



