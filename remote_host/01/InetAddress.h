//
// Created by 71702 on 2024/12/19.
//

#ifndef INETADDRESS_H
#define INETADDRESS_H
#pragma once
#include <arpa/inet.h>



class InetAddress {
public:
    struct sockaddr_in addr;
    socklen_t addr_len;
    InetAddress();
    InetAddress(const char* ip,uint16_t port);
    ~InetAddress();
};



#endif //INETADDRESS_H
