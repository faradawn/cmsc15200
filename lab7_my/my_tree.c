#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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