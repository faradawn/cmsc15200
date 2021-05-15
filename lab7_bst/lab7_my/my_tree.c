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
  if(c == NULL){
    printf("card is NULL");
  } else{
    printf("%s \n", c->cnet);
  }
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

// ok
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

// ok
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

// ok
unsigned int bst_num_entries(bst *t)
{
  if(t == NULL){
    return 0;
  }
  return 1 + bst_num_entries(t->left) + bst_num_entries(t->right);

}

// ok
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

// ok
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

// void print_horizonal(bst *t, char c, unsigned int height){
//   if(t){
//     if(height == 1){
//       if(c == t->c->cnet[0]){
//         printf("%s \n", t->c->cnet);
//         return 
//       }
//     } else {
//       print_horizonal(t->left, c, height-1);
//       print_horizonal(t->right, c, height-1);
//     }
//   }
// }

// biggest
unsigned int bst_c(bst *t, char c)
{
  if (t == NULL){
    return 0;
  }
  if(c == t->c->cnet[0]){
    unsigned int left = bst_c(t->left, c);
    printf("%s \n", t->c->cnet);
    unsigned int right = bst_c(t->right, c);  
    return 1 + left + right;
  } else {
    unsigned int left = bst_c(t->left, c);
    unsigned int right = bst_c(t->right, c);
    return left + right;
  }
}

int main(){
  // construct a tree
  vcard *c1 = vcard_new("ddd", "mike964@uchicago.edu", "Mike", "Tyner", "555-619-1510");
  vcard *c2 = vcard_new("bba", "mike964@uchicago.edu", "Mike", "Tyner", "555-619-1510");
  vcard *c3 = vcard_new("bbc", "mike964@uchicago.edu", "Mike", "Tyner", "555-619-1510");
  vcard *c4 = vcard_new("aaa", "mike964@uchicago.edu", "Mike", "Tyner", "555-619-1510");
  vcard *c5 = vcard_new("bbb", "mike964@uchicago.edu", "Mike", "Tyner", "555-619-1510");
  bst *tree = bst_singleton(c1);
  tree->left = bst_singleton(c2);
  tree->left->right = bst_singleton(c3);
  tree->left->left = bst_singleton(c4);
  
  // insert
  printf("insert result: %d\n",bst_insert(tree, c5));
  show_bst(tree);

  // search and height and number of nodes
  int comparisons = 0;
  printf("search match cnet: ");
  vcard_show(bst_search(tree, "bbb", &comparisons));
  printf("times compared: %d\n", comparisons);
  printf("number of tree nodes: %d\n", bst_num_entries(tree));
  printf("tree height %u: \n", bst_height(tree));

  // match search
  printf("number of matches: %u", bst_c(tree, 'b'));

  // free tree   
  free_bst(tree);
}