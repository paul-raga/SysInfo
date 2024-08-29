//
// Created by paul on 8/29/24.
//


#include "../include/sysreport.h"

#include <malloc.h>
#include <string.h>
#include "../include/devfileopen.h"
#include "../include/diskinfo.h"
#include "../include/fileinfo.h"

#define MAX_REPORT_SIZE 16384
#define MIN_REPORT_SIZE 256
#define MAX_LINE_SIZE 128

char* createFullReport(){
    char* report = malloc(MAX_REPORT_SIZE);

    char* cpustr = allinfos(devf_open("cpu"));
    char* memstr = allinfos(devf_open("mem"));
    char* gpustr = allinfos(devf_open("gpu"));

    char* diskstr = gatherDisksInfo();

    char* soundstr = allinfos(devf_open("soundscard"));
    char* inpstr = allinfos(devf_open("inputdevs"));

    strcpy(report,"PROCESSORS: \n");
    strcat(report,cpustr);
    strcat(report,"********************************************************************** \n");
    strcat(report,"MEMORY: \n");
    strcat(report,memstr);
    strcat(report,"********************************************************************** \n");
    strcat(report,"GPU: \n");
    strcat(report, gpustr);
    strcat(report,"********************************************************************** \n");

    strcat(report,diskstr);
    strcat(report,"********************************************************************** \n");

    strcat(report, "SOUND CARDS: \n");
    strcat(report,soundstr);
    strcat(report,"********************************************************************** \n");
    strcat(report,"INPUT DEVICES: \n");
    strcat(report, inpstr);

    free(cpustr);
    free(memstr);
    free(gpustr);
    free(diskstr);
    free(soundstr);
    free(inpstr);

    return report;
}


char* createBaseReport(){
    char* report = malloc(MIN_REPORT_SIZE);

    char* cpu_model = searchinfo(devf_open("cpu"),"model name");
    char* cpu_cores = searchinfo(devf_open("cpu"),"cpu cores");
    char* cpu_threads = searchinfo(devf_open("cpu"),"siblings");


    char* mem_total = searchinfo(devf_open("mem"),"MemTotal");
    char* mem_free = searchinfo(devf_open("mem"),"MemFree");
    char* mem_available = searchinfo(devf_open("mem"),"MemAvailable");

    char* gpu_model = searchinfo(devf_open("gpu"),"Model");

    strcat(report, "CPU: \n");
    strcat(report,cpu_model);
    strcat(report,cpu_cores);
    strcat(report,cpu_threads);
    strcat(report, "*************************************** \n");

    strcat(report, "MEMORY: \n");
    strcat(report,mem_total);
    strcat(report,mem_free);
    strcat(report,mem_available);
    strcat(report, "*************************************** \n");

    strcat(report,"GPU: \n");
    strcat(report,gpu_model);


    free(cpu_cores);
    free(cpu_model);
    free(cpu_threads);
    free(mem_available);
    free(mem_total);
    free(mem_free);
    free(gpu_model);

    return report;

}

char* customReport(char* device, const char* info) {
    if(strncmp(info, "all",3) == 0) {
        return allinfos(devf_open(device));
    }
    else
        {
        printf("%s%c", device,' ');
        return searchinfo(devf_open(device),info);
    }
}

