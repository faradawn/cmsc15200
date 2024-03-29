#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

// create a bucket linked list
bucket *bucket_cons(char *s, unsigned long int hash, bucket *b)
{
  bucket *out = (bucket*)malloc(sizeof(bucket));
  if(out == NULL){
    fprintf(stderr, "bucket_cons: malloc error\n");
    exit(1);
  }
  out->string = strdup(s);
  out->hash = hash;
  out->next = b;
  return out;
}

// count the number of items in the bucket
unsigned int bucket_size(bucket *b)
{
  if(b == NULL)
    return 0;
  return 1 + bucket_size(b->next);
}

// show the items in the linked list
void bucket_show(bucket *b)
{
  if(b){
    printf("%s ", b->string);
    bucket_show(b->next);
  }
}

// free the bucket linked list
void bucket_free(bucket *b)
{
  if(b){
    bucket_free(b->next);
    free(b->string);
    free(b);
  }
}
