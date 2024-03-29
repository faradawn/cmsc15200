#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "adrbook.h"

const char *_vcard_todo_format = "TODO [vcard]: %s\nhalting\n";

/* vcard_new : allocate a new vcard, copy all strings, return new object
 * note: this is a "deep copy" as opposed to a "shallow copy"; the string 
 *   arguments are not to be shared by the newly allocated vcard
 */ 
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

/* vcard_free : free vcard and the strings it points to
 */
void vcard_free(vcard *c)
{
  free(c->cnet);
  free(c->email);
  free(c->fname);
  free(c->lname);
  free(c->tel);
  free(c);
}

/* vcard_show : display contents of vcard
 * note: f is the destination of the output, e.g. the screen;
 * our code calls this with stdout, which is where printfs are sent;
 * simply use fprintf rather than printf in this function, and pass in f
 * as its first parameter
 */
void vcard_show(FILE *f, vcard *c)
{
  if(c == NULL){
    fprintf(f, "card to show is NULL\n");
  } else{
    fprintf(f, "%s \n", c->cnet);
    fprintf(f, "%s \n", c->email);
    fprintf(f, "%s \n", c->fname);
    fprintf(f, "%s \n", c->lname);
    fprintf(f, "%s \n", c->tel);
  }
}
