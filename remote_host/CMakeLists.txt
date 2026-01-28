cmake_minimum_required(VERSION 3.28)
project(remote_host)

set(CMAKE_CXX_STANDARD 17)

add_executable(remote_host
        01/InetAddress.cpp
        01/InetAddress.h
        01/Socket.cpp
        01/Socket.h
        01/Log.cpp
        01/Log.h
        01/Server.cpp
        01/Server.h
        01/client.cpp
)
