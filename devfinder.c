//
// Created by paul on 8/24/24.
//

#include "devfinder.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

//0: disk, 1: gpu
char* find_devname(int device) {
    DIR* dir = opendir("/sys/block");
    struct dirent* entry;

    switch (device){
        case 0:
            while((entry = readdir(dir)) != NULL) {
                if(strcmp(entry->d_name, "sda") == 0 ) {
                    return "sda"; break;}
                if(strcmp(entry->d_name, "nvme0n1") == 0 ) {
                    return "nvme0n1"; break;
                }
            }
        case 1:
            while((entry = readdir(dir)) != NULL) {
                if(strcmp(entry->d_name, "nvidia") == 0 ) {
                    return "nvidia"; break;
                }
                if(strcmp(entry->d_name, "amd") == 0 ) {
                    return "amd"; break;
                }
            }
        default: return "not found"; break;
    }
}


