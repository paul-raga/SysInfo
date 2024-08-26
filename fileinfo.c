//
// Created by paul on 8/26/24.
//

#include "fileinfo.h"
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFSIZE 128

char* searchinfo(FILE* file, const char* info) {
    if(file != NULL) {
        char* stringbuff = malloc(MAX_BUFFSIZE * sizeof(char));

        while ( fgets(stringbuff,128,file) != NULL) {
            if(strncmp(info,stringbuff,strlen(info)) == 0) {
                return stringbuff;
            }
        } return "parameter not present in the file";
    } else {
        return "device not present or not working";
    }
}
