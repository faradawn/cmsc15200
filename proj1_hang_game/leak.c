#include <stdio.h>
#include <stdlib.h>

void leak() 
{
  char *mem = malloc(666);
}

int main()
{
  leak();
  printf("Nothing to see here.\n");
  return 0;
}