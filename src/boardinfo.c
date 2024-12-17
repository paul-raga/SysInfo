//
// Created by paul on 12/17/24.
//

#include "../include/boardinfo.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PATH "/sys/class/dmi/id/"

char ** getFilesList() {
    DIR* dir = opendir("/sys/class/dmi/id/");
    struct dirent* entry;
    char ** files = malloc(1024 * sizeof(char *));
    int fileCount = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 && strcmp(entry->d_name, "power") != 0 && strcmp(entry->d_name, "subsystem") != 0) {
            files[fileCount] = entry->d_name;
            ++fileCount;
        }
    }
 return files;
}


char * createBoardReport() {
    char * boardReport = malloc(1024 * sizeof(char));
    char * strbuffer = malloc(128 * sizeof(char));
    char ** filesList = getFilesList();
    size_t elems = 0;

    while (filesList[elems] != NULL) {
        elems++;
    }


    for (int i = 0; i < elems; ++i) {
        char * pathbuff = malloc(56 * sizeof(char));
        strcpy(pathbuff, PATH);
        strcat(pathbuff, filesList[i]);

        FILE* file = fopen(pathbuff, "r");
        if (file != NULL) {
            while(fgets(strbuffer, 128, file) ) {
               strcat( strcat(boardReport, filesList[i]), " : ");
                strcat(boardReport, strbuffer);
            }
            fclose(file);
        }
    free(pathbuff);
    }

    free(strbuffer);
    free(filesList);
    return boardReport;
}
