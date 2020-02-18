#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "decibin.h"


#define MAX 127
#define BUFLEN 200


void swap (char*s, char*t){
  char temp = *s;
  *s = *t;
  *t = temp;
}

char * reverse(char* s){
  char * p = s;
  size_t len = strlen(s);
  char * t = s + len - 1;
  len /= 2;
  while (len-- > 0){
    swap(s++, t--);
  }
  return p;
}

char* convert (size_t n){
  // int deci = 128, index = 0;
  // char bin[8];
  // memset(bin, 0, sizeof(bin));
  // while (n >= 0){
  //   if (n > deci){
  //     n -= pow(2 , i)
  //     deci -= pow(2, i);
  //     bin[i] = '1';
  //     ++i;
  //   }
  // }
  // return reverse(bin);
  static char buf[BUFLEN];
  memset(buf, 0, sizeof(buf));
  size_t index = 0;
  while (n > 0){
    buf[index++] = '0' + n % 2;
    n /= 2;
  }
  buf[index] = '\0';
  size_t len = strlen(buf);
  for (size_t b = 0; b < 8 - len; ++b){
    buf[len + b] ='0';
  }
  buf[strlen(buf)] = '\0';
  reverse(buf);
  return buf;
}
