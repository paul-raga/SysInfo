//
// Created by paul on 8/29/24.
//

#ifndef SYSINFO__DEVREPORT_H
#define SYSINFO__DEVREPORT_H

char* createFullReport();

char* createBaseReport();

char* customReport(char* device, const char* info);

char* customFullReport(char* devlist);

#endif //SYSINFO__DEVREPORT_H
