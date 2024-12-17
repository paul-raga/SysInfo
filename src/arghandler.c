//
// Created by paul on 12/10/24.
//

#include "../include/arghandler.h"
#include "../include/sysreport.h"
#include "../include/boardinfo.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_args(int argc, char *argv[]) {

   int  option = getopt(argc, argv, "bhcp");
        switch (option) {

            case 'b' :
                printf("%s",createBaseReport());
                break;

            case 'c' :
                char *device;
                char *info1;
                char *infocat = malloc(sizeof(char)*36);

                device = argv[optind];
                info1 = argv[optind+1];

                if (argv[optind+2] != NULL) {
                    const char *info2 = argv[optind + 2];
                    strcat(infocat, info1);
                    strcat(infocat, " ");
                    strcat(infocat, info2);

                    printf("%s",customReport(device,infocat));
                    free(infocat);
                }
                else {
                    printf("%s",customReport(device,info1));
                }
                break;

            case 'h':
                printf("Options are:\n -b for a basic system report\n "
                       "-p for the product infos\n "
                       "-c <device> <info_type1> <info_type2>(OPTIONAL) "
                       "to search for a specific information of a device\n");
                break;

            case 'p' :
               printf("%s", createBoardReport());

            default :
                printf("type \"sysinfo -h\" for to list the possible arguments\n");
                break;
        }
    }

