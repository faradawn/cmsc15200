#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(int arc, char** argv) {
    char **str_list = (char**)malloc(sizeof(char*) * 1);
    printf("one level: %d \n", str_list);
    free(str_list);
    return 0;
    
}

