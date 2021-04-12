#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int react_to_key(){
	for(unsigned int i = 0; i<3; i++){
		printf(">> i is %d\n", i);
	}
	return 1;
}


int main(int arc, char** argv) {
	
	printf("his");
	printf(">> ans is %d \n", react_to_key());
	return 0;
}

