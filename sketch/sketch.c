#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(int arc, char** argv) {
    
    char str[4] = {'a', 'b', 'c', '\0'};
    str[3] = 'd';
    str[3] = '\0';
    printf("len: %lu; str: %s \n", strlen(str), str);
    return 0;
    
}

