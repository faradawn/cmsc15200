#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

unsigned int is_leap_year(unsigned int year) {
	return !(year%400) || ((year%100) && !(year%4));
}

unsigned int days_in_month(unsigned int month, unsigned int year) {
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 2:
			if(is_leap_year(year))
				return 29;
			else 
				return 28;
		default:
			if(month >= 1 && month <= 12)
				return 30;
			else 
				fprintf(stderr, "error: incorrect months");
				exit(1);
	}
}

void calendar(unsigned char month, unsigned short year,
              unsigned char first_day) {
                  // calculates the number of days in month
                  unsigned int num_days = days_in_month(month, year);
                  // print header line
                  printf("Su Mo Tu We Th Fr Sa \n");
                  // print main calendar with nested loops
                  unsigned int i = 0, num_column = 7;
                  while(i < num_days + first_day - 1) {
                      if(i < first_day-1) { 
                          printf("   ");
                      } else {                          
                          if (i-first_day+2 < 10){
                            printf(" %u ", i-first_day+2);
                          } else {

                            printf("%u ", i-first_day+2);
                          }
                          if (i % 7 == 6) {
                            printf("\n");
                          }                          
                      }
                      i ++;
                  }
              }

int sums_to(int* input, unsigned int input_len, int target_sum) {
    unsigned int count = 0;
    for (int i = 0; i < input_len; i++){
        for (int j = i; j < input_len; j++) {
            if (i + j  == target_sum){
                count ++;
            }
        }
    }
    return count;
}


char* decode(char* s1, char* s2) {
    // determine which one is shorter
    unsigned int shorter_len = strlen(s1);
    if (strlen(s2) < shorter_len) {
        shorter_len = strlen(s2);
    }

    // determine the output array length
    unsigned int i, j = 0, count = 0; 
    for (i = 0; i < shorter_len; i++){
        if (s1[i] == s2[i]) {
            count ++;
        }
    }

    // initialize the output array
    char* out = (char*)malloc(sizeof(char) * (count+1));
    if (out == NULL) {
        fprintf(stderr, "error mallocing out array");
        exit(1);
    }

    // compare two string's each character 
    for (i = 0; i < shorter_len; i++){
        if (s1[i] == s2[i]) {
            out[j] = s1[i];
            j ++;
        }
    }

    // return the out array
    out[count+1] = '\0';
    return out;
}


int* filter_by_array(int* input, unsigned int input_len, 
                     int* filter, unsigned int filter_len, 
                     unsigned int* out_len) {

                        // if empty input, return empty array 

                         // determiene the output array length
                         unsigned int i, j = 0, count = 0;
                         for (i = 0; i < filter_len; i++) {
                             while(j < input_len){
                                if (filter[i] == input[j]) {
                                    count ++;
                                    j ++;
                                } else {
                                    j ++;
                                }
                             }
                         }

                         // set the out_len to the output length 
                         *out_len = count;

                         // initialize the output array
                         int* out = (int*)malloc(sizeof(int) * count);
                         if (out == NULL) {
                            fprintf(stderr, "error mallocing out array");
                            exit(1);
                         }

                         // put values into the output array
                         unsigned int k = 0;
                         for (i = 0; i < filter_len; i++) {
                             while(j < input_len) {
                                 if (filter[i] == input[j]) {
                                     out[k] = input[j];
                                     k ++;
                                     // for safety 
                                     if (k == *out_len) {
                                         break;
                                     }
                                 }
                             }
                         }

                         return out; 

                     }

int main(int arc, char** argv) {

    calendar(4, 2021, 4);

    return 0;
    
}

