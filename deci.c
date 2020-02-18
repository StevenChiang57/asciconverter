
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "decibin.h"
#include "files.h"

#define MAX 127
#define BUFLEN 200
int main (int argc, const char * argv []){
  FILE* fout;
  int n;

  if (argc != 2) { fprintf(stderr, "Usage: ./deci filename\n"); exit(1); }
  if ((fout = fopen(argv[1], "w")) == NULL) {
    fprintf(stderr, "Cannot open file: %s\n", argv[1]);
    exit(2);
  }

  for (int i = 0; i <= MAX; ++i) {
    fprintf(fout, "%s ", convert(i));
    if (i % 8 == 7) {
      fprintf(fout, "\n");
    }
  }

  return 0;
}
