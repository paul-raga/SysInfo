//
// Created by paul on 12/10/24.
//

#include "../include/arghandler.h"
#include "../include/sysreport.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_args(int argc, char *argv[]) {

   int  option = getopt(argc, argv, "fbhc");
        switch (option) {

            case 'f' :
                printf("%s",createFullReport());
                break;

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
                    char *info2 = argv[optind + 2];
                    strcat(infocat, info1);
                    strcat(infocat, " ");
                    strcat(infocat, info2);

                    printf("%s",customReport(device,infocat));
                    free(infocat);
                    free(info2);
                }
                else {
                    printf("%s",customReport(device,info1));
                }
            
                free(device);
                free(info1);
                break;

            case 'h':
                printf("Options are:\n -f for the full system informations report\n -b for a basic system report\n -c to be prompted in a custom report creation\n");
                break;

            default :
                printf("type \"sysinfo -h\" for to list the possible arguments\n");
                break;
        }
    }

