//
// Created by paul on 8/25/24.
//

#include "../include/gpufinder.h"

#include <dirent.h>
#include <stdlib.h>
#include <string.h>


bool findgpu() {
    DIR * dir = opendir("/proc/driver");
    struct  dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, "nvidia") == 0 ) {
            closedir(dir); return true;
        }
        if(strcmp(entry->d_name, "amd") == 0 ) {
           closedir(dir); return true;
        }
        if(strcmp(entry->d_name, "intel") == 0 ) {
           closedir(dir); return true;
        }
    }

    return false;

}


char* gpupathfinder() {
    char* pathbuff = malloc(sizeof (char) * 256);
    strcpy(pathbuff,"/proc/driver");

    DIR* dir = opendir(pathbuff);
    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if(strcmp(entry->d_name, "nvidia") == 0 ) {
            strcat(pathbuff,"/nvidia/gpus/"); closedir(dir); break;
        }
        if(strcmp(entry->d_name, "amd") == 0 ) {
            strcat(pathbuff,"/amd/gpus/"); closedir(dir); break;
        }
    }

    dir = opendir(pathbuff);

    while ( (entry = readdir(dir)) != NULL){
        if( (strcmp(entry->d_name, ".") !=0) && (strcmp(entry->d_name, "..") ) != 0)  {
            strcat(pathbuff, entry->d_name);  // /proc/driver/*vendor*/gpus/*index*
            closedir(dir); break;
        }
    };

    strcat(pathbuff, "/information"); // /proc/driver/*vendor*/gpus/*index*/information

    return pathbuff;

}
