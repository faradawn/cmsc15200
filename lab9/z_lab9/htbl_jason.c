/* CMSC 15200
 * Jason Huang, jasonhuang
 * lab9
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htbl.h"

unsigned long int good_hash(char *s)
{
    unsigned int res = 17;
    unsigned int i = 0;
    while (s[i]) {
	      printf("%d", s[i]);
        res = res * 37 + s[i];
        i++;
    }
    return res;
}

unsigned long int bad_hash(char *s)
{
    unsigned res = 17;
    unsigned i = 0;
    while (s[i]) {
        while (i < 2) {
            res = res * 37 + s[i];
            i++;
        }
    } 
    return res;
}

htbl *htbl_new(unsigned long int(*h)(char*), unsigned int sz)
{
    htbl *new_htbl = (htbl*) malloc (sizeof(htbl) * sz);
    new_htbl -> hash = h;
    new_htbl -> buckets = NULL;
    new_htbl -> n_buckets = sz;
    return new_htbl;
}

unsigned int htbl_n_entries(htbl *t)
{
    int i = 0;
    int j = 0;
    struct bucket *bucket;
    while(t) {
        while (t -> buckets[i]) {
            bucket = t -> buckets[i];
            while (bucket) {
                j++;
                bucket = bucket -> next;
            }
            i++; 
        }
    }
    return j;
}

double htbl_load_factor(htbl *t)
{
    int j = 0;
    int i = htbl_n_entries(t);
    while(t) {
        while (t -> buckets[j]) {
            j++;
        }
    }
    return (i / j);
}

unsigned int htbl_max_bucket(htbl *t)
{
    int i = 0;
    int j = 0;
    while (t -> buckets[i]) {
        i++;
        if (i > j) {
            j = i;
        }
    }
    return j;
}

void htbl_insert(char *s, htbl *t)
{
    unsigned long int hash = t -> hash(s);
    unsigned long int new_hash = hash % t -> n_buckets;
    if (t -> buckets[new_hash] == NULL) {
        t -> buckets[new_hash] = bucket_cons(s, hash, NULL);
    } else {
        t -> buckets[new_hash] = bucket_cons(s, hash, t -> buckets[new_hash]);
    }
}

int htbl_member(char *s, htbl *t)
{
    unsigned long int hash = good_hash(s);
    unsigned new_hash = hash % t -> n_buckets;
    if (t -> buckets[new_hash]) {
        if (!strcmp(t -> buckets[new_hash] -> string, s)) {
            return 1;
        }
        while (t -> buckets[new_hash] -> next != NULL) {
            if (!strcmp(t -> buckets[new_hash] -> string, s)) {
                return 1;
            }
            t -> buckets[new_hash] = t -> buckets[new_hash] -> next;
        }
        return 0;
    }
    return 0;
}

void htbl_show(htbl *t)
{
    int i = 0;
    while (t -> buckets[i]) {
        printf("h: %lu str: %s ", t -> buckets[i] -> hash, 
            t -> buckets[i] -> string);
        t -> buckets[i] = t -> buckets[i] -> next;
        ++i;
    }
}

void htbl_free(htbl *t)
{
    int i = 0;
    struct bucket *bucket;
    struct bucket *temp;
    while (t -> buckets[i]) {
        bucket = t -> buckets[i];
        while (bucket) {
            temp = bucket -> next;
            free(bucket);
            bucket = temp;
        }
        temp = bucket;
        free(temp);
    }
}
