cmake_minimum_required(VERSION 3.29)
project(SysInfo_ C)

set(CMAKE_C_STANDARD 11)

add_executable(SysInfo_ main.c

        src/devfileopen.c
        include/devfileopen.h
        src/gpufinder.c
        include/gpufinder.h
        src/diskfinder.c
        include/diskfinder.h
        src/fileinfo.c
        include/fileinfo.h
        src/diskinfo.c
        include/diskinfo.h
        include/string_to_dev.h
        include/devtypes.h
        src/string_to_dev.c
        include/sysreport.h
        src/sysreport.c
)
