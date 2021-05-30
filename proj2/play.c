#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char **argv){

    unsigned int width, height;

    for(int i=0; i<argc; i++){
        if(strcmp(argv[i], "-w") == 0)
            width = atoi(argv[i+1]);
        else if(strcmp(argv[i], "-h") == 0)

        
        
    }
    printf("width: %u\n", width);
}