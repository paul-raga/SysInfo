//
// Created by paul on 8/26/24.
//

#include "diskinfo.h"
#include "diskfinder.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* stringreader(const char* path) {
    FILE* diskfile  = fopen(path, "r");
    char* strbuff = malloc(56 * sizeof(char));

    while(fgets(strbuff, 56, diskfile) != NULL) {
        ;
    }
    return strbuff;
}

/*TODO fixme: with more than 2 mass storage devices the function
   the function generates a segmentation fault.
   This is probably an heisenbug: if you add something like
   printf the program works fine, meaning that getDiskNum()
   might be too slow when there are many devices to be discoverd */

char* gatherDisksInfo() {
    char* stringbuf = malloc(256 * sizeof(char));
    strcpy(stringbuf, "DISKS: \n");
    const unsigned int disks = getDiskNum();
    const char** diskslist = searchdisks();

    for(int i = 0; i < disks; i++) {
        strcat(stringbuf, diskslist[i]);
        strcat(stringbuf, ": " );
        char pathbuff [256]= "/sys/block/";
        strcat(pathbuff, diskslist[i]);       // /sys/block/*device[n]*
        strcat(pathbuff, "/device");     // /sys/block/*device[n]*/device/

        char modelpath [128] = "";
        strcat(modelpath, pathbuff);
        strcat(modelpath, "/model");
        char* modelinfo = stringreader(modelpath);
        strcat(stringbuf, modelinfo);
        free(modelinfo);

    }

    return stringbuf;
}



