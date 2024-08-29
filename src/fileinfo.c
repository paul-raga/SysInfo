//
// Created by paul on 8/26/24.
//

#include "../include/fileinfo.h"
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFSIZE 8192
#define MAX_LINE_SIZE 128

char* searchinfo(FILE* file, const char* info) {
    if(file != NULL) {
        char* stringbuff = malloc(MAX_LINE_SIZE * sizeof(char));

        while ( fgets(stringbuff,128,file) != NULL) {
            if(strncmp(info,stringbuff,strlen(info)) == 0) {
                return stringbuff;
            }
        } return strcpy(malloc(56),"parameter not present in the file \n");
    } else {
        return strcpy(malloc(56),"device not present or not working \n");
    }
}

char* allinfos(FILE* file){
    if(file != NULL) {
        char *stringbuff = malloc(MAX_BUFFSIZE * sizeof(char));
        char buff[56];
        while (fgets(buff, 56, file) != NULL) {
            strcat(stringbuff, buff);
        }
        return stringbuff;
    }else return "device file not present or not working";
}

