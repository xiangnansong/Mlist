cmake_minimum_required(VERSION 2.8.12.2)
project(Mlist)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Mlist ${SOURCE_FILES} MAL.h LinkList.h Node.h)
