#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned int num_ones(unsigned int n){
    unsigned int count = 0;

    while(n>0){
        if(n & 1){
            count ++;
        }
        n = n >> 1;
    }
    return count;
}


typedef struct graph graph;

struct graph {
    unsigned int num_vertices;
    bool** adj;
};

unsigned int most_popular(graph g){
    unsigned int count = 0;
    unsigned int max = 0;
    // tunnel down a user's column 
    for(int i = 0; i<g.num_vertices; i++){ // column
        for(int j = 0; i<g.num_vertices; j++){ // row
            if(g.adj[i][j] == true){
                count ++;
            }
        }
        if(count > max){
            max = count;
        }
    }
    return max;
}

// tree
typedef struct inttree inttree;

struct inttree {
   int val;
   inttree* left;
   inttree* right;
};

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


// LR path
int lr_path(inttree* t, char* path){
    if(t == NULL){
        return 0;
    }

    int count = t->val;
    for(int i = 0; i<strlen(path); i++){
        if(path[i] == 'L'){
            if(t->left == NULL){
                return -1;
            } else {
                count += t->left->val;
                t = t->left;
            }
        } else {
            if(t->right == NULL){
                return -1;
            } else {
                count += t->right->val;
                t = t->right;
            }
        }
    }
    if(t->left || t->right){
        return -1;
    } else {
        return count;
    }
}

// multiplier tree
bool multiplier_tree(inttree* t){
    if(t == NULL){
        return true;
    }
    if(t->left && t->right){
        if(t->left->val % t->val != 0 || t->right->val != 0){
            return false;
        } else{
            return multiplier_tree(t->left) && multiplier_tree(t->right);
        }
    } else if(t->left){
        if(t->left->val % t->val != 0){
            return false;
        } else{
            return multiplier_tree(t->left) && multiplier_tree(t->right);
        }
    } else if(t->right){
        if(t->right->val % t->val != 0){
            return false;
        } else {
            return multiplier_tree(t->left) && multiplier_tree(t->right);
        }
    }
    return true;
}


int main(){
    inttree *t = make_tree(2, make_tree(4, make_tree(12, NULL, NULL), make_tree(8, NULL, NULL)), 
                            make_tree(6, NULL, make_tree(12, make_tree(24, NULL, NULL), make_tree(28, NULL, NULL))));
    show_tree(t);
    printf("tree: %d\n", lr_path(t, "LR"));
    printf("check: %d\n", multiplier_tree(t));
    

    free_tree(t);


    
}