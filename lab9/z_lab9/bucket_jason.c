/* CMSC 15200
 * Jason Huang, jasonhuang
 * lab9
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

bucket *bucket_cons(char *s, unsigned long int hash, bucket *b)
{
    bucket *head = (struct bucket*)malloc(sizeof(struct bucket));
    
    head -> string = strdup(s);    
    head -> hash = hash;
    head -> next = b;
    
    return head;
}

unsigned int bucket_size(bucket *b)
{
    int i = 0;
    while (b) {
        i++;
        b = b -> next;
    }
    return i;
}

void bucket_show(bucket *b)
{
    unsigned i = 0;
    while (b) {
        while (b -> string[i]) {
            printf("%c", b -> string[i]);
        }
        b = b -> next;
    }
}

void bucket_free(bucket *b)
{
    struct bucket *node = b;

    while (b) {
        node = b;
        b = b -> next;
        free(node -> string);
        free(node);
    }
}

