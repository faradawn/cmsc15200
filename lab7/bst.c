#include <stdlib.h>
#include <stdio.h>
#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

/* Create a bst consisting of one leaf node. */
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

/* Insert a vcard into a non-empty BST. */
int bst_insert(bst *t, vcard *c)
{
  if(t == NULL){
    fprintf(stderr, "bst_insert: tree is empty\n");
    exit(1);
  }

  while(t){
    if(strcmp(c->cnet, t->c->cnet) == 0){
      return 0;
    } else if(strcmp(c->cnet, t->c->cnet) > 0){
      if(t->right == NULL){
        t->right = bst_singleton(c);
        return 1;
      }
      t = t->right;
    } else if(strcmp(c->cnet, t->c->cnet) < 0){
      if(t->left == NULL){
        t->left = bst_singleton(c);
        return 1;
      }
      t = t->left;
    }
  }
  return 0;
}

/* Compute the total number of vcards in the tree. */
unsigned int bst_num_entries(bst *t)
{
  if(t == NULL){
    return 0;
  }
  return 1 + bst_num_entries(t->left) + bst_num_entries(t->right);

}

/* The empty bst has height 0. */
unsigned int bst_height(bst *t)
{
  if(t == NULL){
    return 0;
  } else {
    unsigned left = bst_height(t->left);
    unsigned right = bst_height(t->right);
    if (left > right) 
      return 1 + left;
    else 
      return 1 + right;
  }  
}

/* Return NULL if nothing is found. */
vcard *bst_search(bst *t, char *cnet, int *n_comparisons)
{
  int count = 0;
  while(t){
    if(strcmp(cnet, t->c->cnet) == 0){
      *n_comparisons = count;
      return t->c;
    } else if(strcmp(cnet, t->c->cnet) > 0){
      t = t->right;
    } else if(strcmp(cnet, t->c->cnet) < 0){
      t = t->left;
    }
    count ++;
  }
  *n_comparisons = count;
  return NULL;
}

/* note: f is the destination of the output, e.g. the screen;
 * our code calls this with stdout, which is where printfs are sent;
 * simply use fprintf rather than printf in this function, and pass in f
 * as its first parameter
 */
/* Show all cnets that start with given character. */
unsigned int bst_c(FILE *f, bst *t, char c)
{
  if (t == NULL){
    return 0;
  }
  if(c == t->c->cnet[0]){
    unsigned int left = bst_c(f, t->left, c);
    fprintf(f, "%s \n", t->c->cnet);
    unsigned int right = bst_c(f, t->right, c); 
    return 1 + left + right;
  } else {
    unsigned int left = bst_c(f, t->left, c);
    unsigned int right = bst_c(f, t->right, c);  
    return left + right;
  }
}

/* Free the bst and all vcards as well. */
void bst_free(bst *t)
{
  if(t){
    bst_free(t->left);
    bst_free(t->right);
  vcard_free(t->c);
    if(t->left == NULL && t->right == NULL)
      free(t);
  }  
}
