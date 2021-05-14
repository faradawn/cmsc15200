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

unsigned int bst_num_entries(bst *t)
{
  if(t == NULL){
    return 0;
  }
  return 1 + bst_num_entries(t->left) + bst_num_entries(t->right);

}

unsigned int bst_height(bst *t)
{
  // todo
  if(t == NULL){
    return 0;
  }
  return 10;
}

vcard *bst_search(bst *t, char *cnet, int *n_comparisons)
{
  int count = 0;
  while(t){
    if(strcmp(cnet, t->c->cnet) == 0){
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
unsigned int bst_c(FILE *f, bst *t, char c)
{
  if (t == NULL){
    return 0;
  }
  // find the smallest qualified cnet 
  if(c == t->c->cnet[0]){
    if(t->left->c->cnet[0] != c){
      // print the smallest first
      fprintf(f, "%s \n", t->c->cnet);
      return 1 + bst_c(f, t->right, c);
    } 
    // then print the current
    fprintf(f, "%s \n", t->c->cnet);
    return 1;
  } else if (c < t->c->cnet[0]){
    return bst_c(f, t->left, c);
  } else {
    return bst_c(f, t->right, c);
  }
}

void bst_free(bst *t)
{
  if(t->left != NULL){
    bst_free(t->left);
    free(t->left);
  } else if (t->right != NULL){
    bst_free(t->right);
    free(t->right);
  }
  free(t);
}
