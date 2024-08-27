#include <stdio.h>
#include <malloc.h>
#include "include/secondarydevfopen.h"
#include "include/primarydevopen.h"
#include "include/fileinfo.h"


int main(void) {

    char * string1 = allinfos(secondary_devfopen("inputdevs"));
    char * string2 = allinfos(primary_devfopen("gpu"));
    char * string3 = allinfos(secondary_devfopen("soundscard"));

    printf("%s%s%s", string1, string2, string3);
    free(string1);
    free(string2);
    free(string3);

}

