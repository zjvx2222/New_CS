//
// Created by 71702 on 2024/12/20.
//

#ifndef SOCKET_H
#define SOCKET_H
#pragma once


class InetAddress;
class Socket {
private:
    int _fd;
public:
    Socket();
    Socket(int fd);
    ~Socket();
    void bind(InetAddress* addr);

    int accept(InetAddress* addr);

    void listen();

    int GetFd();
};



#endif //SOCKET_H
