//
// Created by paul on 12/15/24.
//
#include "../../include/utils/customStrUtils.h"

#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 128

char * searchString (const char * source, const char * dest ) {
    const unsigned int length = strlen(source);
    char current_char;
    char *matched_information = malloc(MAX_LINE_SIZE);
    int dest_counter = -1;
    int source_counter = 0;

    while ((current_char = dest[++dest_counter]) != '\0'  ) {
        if (source[source_counter] == current_char) {
            ++source_counter;

            if (source_counter == length) {
                char supportChar;
                int count = 0;
                while ((supportChar=dest[++dest_counter]) != '\n') {
                    matched_information[count] = supportChar;
                    count++;
                }
                return matched_information;
            };

        }else {
            source_counter=0;
        }
    }

    return "no match found";
}
