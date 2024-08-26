//
// Created by paul on 8/24/24.
//

#include "basedevopen.h"
#include <string.h>
#include "gpufinder.h"

enum devtype {
    cpu,
    mem,
    gpu,
};

enum devtype string_to_devtype(char *device) {
    if(strcmp(device, "cpu") == 0) return cpu;
    else if(strcmp(device, "mem") == 0) return mem;
    else if(strcmp(device, "gpu") == 0) return gpu;
}


FILE* devfopen (char* name){
    enum devtype device = string_to_devtype(name);
    switch (device) {
        case cpu: return fopen("/proc/cpuinfo", "r");
        case mem: return fopen("/proc/meminfo", "r");
        case gpu: if(findgpu()) {return fopen(gpupathfinder(),"r");}
                                 else {return NULL;};
    }
}
