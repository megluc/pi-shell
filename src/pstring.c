// pstring.c

#include "pstring.h"

int strcmp(const char *str1, const char *str2) {
  while (*str1 && (*str1 == *str2)) {
    str1++;
    str2++;
  }
  return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int strcmplen(const char *str1, const char *str2, unsigned int n) {
  while (n && *str1 && (*str1 == *str2)) {
    str1++;
    str2++;
    n--;
  }
  if (n == 0) {
    return 0;
  } else {
    return *(unsigned char *)str1 - *(unsigned char *)str2;
  }
}