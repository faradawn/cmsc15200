#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct tree inttree;
struct tree {
    int val;
    inttree* left;
    inttree* right;
} ;

inttree* make_tree(int val, inttree* left, inttree* right){
    inttree* tree = (inttree*)malloc(sizeof(inttree));
    if(tree == NULL){
        fprintf(stderr, "make_tree allocation error");
        exit(1);
    } 
    tree->val = val;
    tree->right = right;
    tree->left = left;
    return tree;
}

void free_tree(inttree* t){
    if(t){
        free_tree(t->left);
        free_tree(t->right);
        free(t); // free middle last
    }
}

void show_tree(inttree* t){
    // pre-order print tree
    if(t){
        printf("%d ", t->val);
        show_tree(t->left);
        show_tree(t->right);
    }
}


int contain(inttree* t, int val){
    if(t == NULL){
        return 0;
    }
    // check middle first (short circuit)
    return t->val == val || contain(t->left, val) ||contain(t->right, val);
}

int count_nodes(inttree* t){
    if(t == NULL){
        return 0;
    }
    int left = count_nodes(t->left);
    int right = count_nodes(t->right);
    return 1 + left + right;
}

int main(){
    
    
}