//
// Created by paul on 8/25/24.
//

#include "../include/diskfinder.h"
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

char** searchdisks() {
    char** pointarr = malloc(1024);
    int devcounter = 0;

    DIR* dir = opendir("/sys/block");
    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if (strncmp(entry->d_name, "sd", 2) == 0) {   //case for mass storage like sda, sdb....
            pointarr[devcounter] = entry->d_name;
            ++devcounter;
        }
        if (strncmp(entry->d_name, "nvme", 4) == 0) { //case for nvme devices
            pointarr[devcounter] = entry->d_name;
            ++devcounter;
        }
    }

    closedir(dir);
    return pointarr;
}

unsigned int getDiskNum() {
    DIR* dir = opendir("/sys/block");
    struct dirent* entry;
    unsigned int dcounter = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0  && strcmp(entry->d_name, "..") != 0 && strncmp(entry->d_name, "loop", 4) != 0)  {
            ++dcounter;
        }
    }
    return dcounter;
}
