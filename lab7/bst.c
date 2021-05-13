#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

bst *bst_singleton(vcard *c)
{
  bst *out = (bst*)malloc(sizeof(bst));
  if(out == NULL){
    fprintf(stderr, "bst_singleton: error mallocing\n");
    exit(1);
  }
  out->c = c;
  out->left = NULL;
  out->right = NULL;
  return out;
}

int bst_insert(bst *t, vcard *c)
{
  if(t == NULL){
    fprintf(stderr, "bst_insert: tree is empty\n");
    exit(1);
  }

  if(strcmp(c->cnet, t->c->cnet) == 0){
    return 0;
  } else if(strcmp(c->cnet, t->c->cnet) > 0){
    t->right = bst_insert(t->right, c);
  } else { 
    t->left = bst_insert(t->left, c);
  }
  
  return t;
}

unsigned int bst_num_entries(bst *t)
{
  fprintf(stderr,_bst_todo_format,"bst_num_entries");
  exit(1);  
}

unsigned int bst_height(bst *t)
{
  fprintf(stderr,_bst_todo_format,"bst_height");
  exit(1);
}

vcard *bst_search(bst *t, char *cnet, int *n_comparisons)
{
  fprintf(stderr,_bst_todo_format,"bst_search");
  exit(1);
}

/* note: f is the destination of the output, e.g. the screen;
 * our code calls this with stdout, which is where printfs are sent;
 * simply use fprintf rather than printf in this function, and pass in f
 * as its first parameter
 */
unsigned int bst_c(FILE *f, bst *t, char c)
{
  fprintf(stderr,_bst_todo_format,"bst_c");
  exit(1);
}

void bst_free(bst *t)
{
  fprintf(stderr,_bst_todo_format,"bst_free");
  exit(1);
}
