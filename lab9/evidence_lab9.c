#include "htbl.h"
#include <stdio.h>
#include <string.h>

// clang -g -Wall evidence_lab9.c bucket.c htbl.c; ./a.out

int main(){
  // Part1: Bucket
  printf("\n=== Part1: Bucket ===\n");
  printf(">> build bucket:\n");
  bucket* b = bucket_cons("alice", 10, bucket_cons("bob", 11, bucket_cons("catherine", 12, NULL)));
  printf("bucket built\n");
  printf("\nshow bucket:");
  bucket_show(b);
  printf("\n>> bucket size: %u\n", bucket_size(b));
  printf("\n>> free bucket:\n");
  bucket_free(b);
  printf("bucket freed\n");



  // Part2: Hash Table
  printf("\n=== Part2: Hash Table ===\n");
  printf(">> create htbl\n");
  htbl* t = htbl_new(good_hash, 2);
  printf("htbl created\n");
  
  // insert 
  printf("\n>> insert 'alice', 'bob', 'cathy', 'emma', 'felicia', 'grant', 'helen':\n");
  htbl_insert("abigail", t);
  htbl_insert("belle", t);
  htbl_insert("caroline", t);
  htbl_insert("daisy", t);
  htbl_insert("elizabeth", t);
  htbl_insert("freya", t);
  htbl_show(t);

  // status 
  printf("\n\n>> number of items: %u\n", htbl_n_entries(t));
  printf(">> max items bucket: %u\n", htbl_max_bucket(t));
  printf(">> loard factor: %lf\n", htbl_load_factor(t));

  // check is member
  printf("\n\n>> check 'abigail': %d\n", htbl_member("abigail", t));
  printf(">> check 'elizabeth': %d\n", htbl_member("elizabeth", t));
  printf(">> check 'none': %d\n", htbl_member("none", t));

  printf(">> free htbl\n");
  htbl_free(t);
  printf("freed\n");

}
