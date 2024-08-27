//
// Created by paul on 8/27/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/secondarydevfopen.h"
#include "../include/string_to_dev.h"
#include "../include/devtypes.h"


FILE* secondary_devfopen(const char* device){
    enum devtype dev = string_to_devtype(device);
    switch (dev) {
        case soundscard : return fopen("/proc/asound/cards", "r");
        case inputdevs : return fopen("/proc/bus/input/devices","r");
        case -1 : return NULL;
    }
}