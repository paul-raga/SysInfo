//
// Created by paul on 8/24/24.
//

#include "../include/devfileopen.h"
#include <string.h>
#include "../include/gpufinder.h"
#include "../include/string_to_dev.h"
#include "../include/devtypes.h"


FILE* devf_open (const char* name){
    enum devtype device = string_to_devtype(name);
    switch (device) {
        case cpu: return fopen("/proc/cpuinfo", "r");
        case mem: return fopen("/proc/meminfo", "r");
        case gpu: if(findgpu()) {return fopen(gpupathfinder(),"r");}
                                 else {return NULL;};
        case soundscard : return fopen("/proc/asound/cards", "r");
        case inputdevs : return fopen("/proc/bus/input/devices","r");
        default: return NULL;
    }
}
