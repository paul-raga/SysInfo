#include <stdio.h>
#include "diskinfo.h"
#include "fileinfo.h"
#include "basedevopen.h"

int main(void) {

  printf("%s\n", gatherDisksInfo());

  printf("%s",searchinfo(devfopen("cpu"),"model name"));
  printf("%s\n",searchinfo(devfopen("cpu"),"cpu cores"));

  printf("%s",searchinfo(devfopen("mem"),"MemTotal"));
  printf("%s",searchinfo(devfopen("mem"),"MemFree"));
  printf("%s\n",searchinfo(devfopen("mem"),"MemAvailable"));

  printf("%s",searchinfo(devfopen("gpu"),"Model"));

}

