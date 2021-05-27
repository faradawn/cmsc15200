#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

// good hash function with low collisions
unsigned long int good_hash(char *s)
{
  unsigned long int out = 17;
  int i = 0;
  while(*(s+i) != '\0'){
    out = out*37 + *(s+i);
    i ++;
  }
  return out;
}

// bad hash function that returns the sum of all char
unsigned long int bad_hash(char *s)
{
  unsigned long int out = 0;
  int i = 0;
  while(*(s+i) != '\0'){
    out += *(s+i);
    i ++;
  }
  return out;
}

htbl *htbl_new(unsigned long int(*h)(char*), unsigned int sz)
{
  htbl* out = (htbl*)malloc(sizeof(htbl));
  if(out == NULL){
    fprintf(stderr, "htbl_new: error malloc out\n");
    exit(1);
  }
  bucket **arr = (bucket**)malloc(sizeof(bucket*) * sz);
  if(arr == NULL){
    fprintf(stderr, "htbl_new: error malloc arr\n");
    exit(1);
  }
  out->hash = arr;
  out->buckets = NULL;
  out->n_buckets = sz; // 0 or sz
  return out;
}

unsigned int htbl_n_entries(htbl *t)
{
  unsigned int count = 0;
  for(int i = 0; i<t->n_buckets; i++){
    count += bucket_size(t->buckets[i]);
  }
  return count;
}

double htbl_load_factor(htbl *t)
{
  return (double) htbl_n_entries(t) / t->n_buckets;
}

unsigned int htbl_max_bucket(htbl *t)
{
  unsigned int max = 0;
  for(int i = 0; i<t->n_buckets; i++){
    if(bucket_size(t->buckets[i] > max))
      max = bucket_size(t->buckets[i];
  }
  return max;

}

void htbl_insert(char *s, htbl *t)
{
  fprintf(stderr,"todo: htbl_insert\n");
  exit(1);
}

int htbl_member(char *s, htbl *t)
{
  fprintf(stderr,"todo: htbl_member\n");
  exit(1);
}

void htbl_show(htbl *t)
{
  fprintf(stderr,"todo: htbl_show\n");
  exit(1);
}

void htbl_free(htbl *t)
{
  fprintf(stderr,"todo: htbl_free\n");
  exit(1);
}

int main(){
  char* str = "FORK";
  good_hash(str);
}