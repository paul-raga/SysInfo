#include <stdio.h>
#include "include/arghandler.h"


int main(int argc, char *argv[]) {

    //printf("%s",createFullReport());

    //printf("%s",createBaseReport());

    //printf("%s", customReport("cpu","model name"));

    //printf("%s",customReport("gpu","all"));

    handle_args(argc,argv);

    return 0;
}

