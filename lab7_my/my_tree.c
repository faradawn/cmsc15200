#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// todo: look slide free bst 

typedef struct {
  char *cnet;
  char *email;
  char *fname;
  char *lname;
  char *tel;
} vcard;

typedef struct bst bst;
struct bst {
  vcard *c;
  bst *left;
  bst *right;
};

vcard *vcard_new(char *cnet, char *email, char *fname, char *lname, char *tel)
{
  // malloc struct also malloc each string?
  vcard *out = (vcard*)malloc(sizeof(vcard));
  if(out == NULL){
    fprintf(stderr, "error allocating new vcard struct");
    exit(1);
  }

  out->cnet = strdup(cnet);
  out->email = strdup(email);
  out->fname = strdup(fname);
  out->lname = strdup(lname);
  out->tel = strdup(tel);

  return out;
}

void vcard_free(vcard *c)
{
  free(c->cnet);
  free(c->email);
  free(c->fname);
  free(c->lname);
  free(c->tel);
  free(c);
}

void vcard_show(vcard *c)
{
  printf("%s \n", c->cnet);
}



// part 2: bst 

void show_bst(bst *t){
  if(t){
    show_bst(t->left);
    show_bst(t->right);
    vcard_show(t->c);
  }
}

void free_bst(bst *t){
  if(t){
    free_bst(t->left);
    free_bst(t->right);
    vcard_free(t->c);
    if(t->left == NULL && t->right == NULL)
      free(t);
  }
}

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



int main(){
  // construct a tree
  vcard *c1 = vcard_new("ddd", "mike964@uchicago.edu", "Mike", "Tyner", "555-619-1510");
  vcard *c2 = vcard_new("bba", "mike964@uchicago.edu", "Mike", "Tyner", "555-619-1510");
  vcard *c3 = vcard_new("bbc", "mike964@uchicago.edu", "Mike", "Tyner", "555-619-1510");
  vcard *c4 = vcard_new("aaa", "mike964@uchicago.edu", "Mike", "Tyner", "555-619-1510");
  bst *tree = bst_singleton(c1);
  tree->left = bst_singleton(c2);
  tree->right = bst_singleton(c3);
  tree->left->left = bst_singleton(c4);
  show_bst(tree);

  // count number of levels

  // free tree   
  free_bst(tree);
}