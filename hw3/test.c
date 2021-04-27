#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char** build_array(){
    // want to build: arr = {str1, str2, str3}
    char** arr = (char**)malloc(sizeof(char*) * 3);
    
    char str1[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char str2[4] = {'h', 'e', 'y', '\0'};
    char str3[3] = {'h', 'i', '\0'};

    arr[0] = str1;
    arr[1] = str2;
    arr[2] = str3;

    return arr;
}

int main(){
    char** arr = build_array();
    printf("%s \n", arr[0]);
    printf("%s \n", arr[1]);
    printf("%s \n", arr[2]);
    free(arr);

}