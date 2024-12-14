//
// Created by paul on 12/10/24.
//

#include "../include/arghandler.h"
#include "../include/sysreport.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
                char *device = malloc(sizeof(char)*12 + 1);
                char *info = malloc(sizeof(char)*24 + 1);

                printf("what device's informations do you want? : ");
                scanf("%s",device);

                printf("what kind of information do you want? : ");
                scanf("%s",info);


                printf("%s",customReport(device,info));

                free(info);
                free(device);
                break;

            case 'h':
                printf("Options are:\n -f for the full system informations report\n -b for a basic system report\n -c to be prompted in a custom report creation\n");
                break;

            default :
                printf("type \"sysinfo -h\" for to list the possible arguments\n");
                break;
        }
    }

