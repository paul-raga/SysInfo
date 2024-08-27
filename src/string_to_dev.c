//
// Created by paul on 8/27/24.
//
#include <string.h>
#include "../include/devtypes.h"
#include "../include/string_to_dev.h"

enum devtype string_to_devtype(const char *device) {
    if (strcmp(device, "cpu") == 0) return cpu;
    else if (strcmp(device, "mem") == 0) return mem;
    else if (strcmp(device, "gpu") == 0) return gpu;
    else if (strcmp(device, "soundscard") == 0) return soundscard;
    else if (strcmp(device, "inputdevs") == 0) return inputdevs;
    return -1;
}