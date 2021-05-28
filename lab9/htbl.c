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

// create a new hash table
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
  out->buckets = arr;
  out->hash = h;
  out->n_buckets = sz; 
  return out;
}

// counts total items in all buckets
unsigned int htbl_n_entries(htbl *t)
{
  unsigned int count = 0;
  for(int i = 0; i<t->n_buckets; i++){
    count += bucket_size(t->buckets[i]);
  }
  return count;
}

// compute the average bucket items
double htbl_load_factor(htbl *t)
{
  return (double) htbl_n_entries(t) / t->n_buckets;
}

// count the max number of items of buckets
unsigned int htbl_max_bucket(htbl *t)
{
  unsigned int max = 0;
  for(int i = 0; i<t->n_buckets; i++){
    if(bucket_size(t->buckets[i]) > max)
      max = bucket_size(t->buckets[i]);
  }
  return max;

}

// insert an item into a bucket
void htbl_insert(char *s, htbl *t)
{
  long unsigned int hash_val = t->hash(s);
  long unsigned int index = hash_val % t->n_buckets;
  bucket *b = t->buckets[index];

  if(b == NULL){
    t->buckets[index] = bucket_cons(s, hash_val, NULL);
  } else{
    t->buckets[index] = bucket_cons(s, hash_val, b);
  }

}

// check if the given string is a memebr of htbl
int htbl_member(char *s, htbl *t)
{
  long unsigned int hash_val = t->hash(s);
  long unsigned int index = t->hash(s) % t->n_buckets;
  bucket *b;
  b = t->buckets[index];
  while(b){
    if(b->hash == hash_val){
      if(strcmp(s, b->string) == 0)
        return 1;
    }
    b = b->next;
  }
  
  return 0;
}

// show all the strings in htbl
void htbl_show(htbl *t)
{
  bucket *b;
  for(int i = 0; i<t->n_buckets; i++){
    b = t->buckets[i];
    printf("bucket %d: ", i);
    while(b){
      printf("%s ", b->string);
      b = b->next;
    }
    printf("\n");
  }
}

// free the htbl
void htbl_free(htbl *t)
{
  for(int i = 0; i<t->n_buckets; i++){
    bucket_free(t->buckets[i]);
  }
  free(t);
}
