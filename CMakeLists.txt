cmake_minimum_required(VERSION 3.29)
project(SysInfo_ C)

set(CMAKE_C_STANDARD 11)

add_executable(SysInfo_ main.c
        basedevopen.c
        basedevopen.h
        devfinder.c
        devfinder.h
        gpufinder.c
        gpufinder.h
        diskfinder.c
        diskfinder.h
        fileinfo.c
        fileinfo.h
        diskinfo.c
        diskinfo.h
)
