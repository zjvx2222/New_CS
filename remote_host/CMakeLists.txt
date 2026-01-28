cmake_minimum_required(VERSION 3.28)
project(remote_host)

set(CMAKE_CXX_STANDARD 17)

add_executable(remote_host
        server.cpp
        client.cpp)
